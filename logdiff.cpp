#include <dtl/dtl.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <time.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#include "comparator.h"

using namespace std;

using dtl::Diff;
using dtl::elemInfo;
using dtl::uniHunk;

typedef enum {
  MODE_DEC_INSENSITIVE,
  MODE_HEX_INSENSITIVE,
  MODE_DECS_INSENSITIVE,
  MODE_HEXS_INSENSITIVE,
} comp_mode_e;

static comp_mode_e comp_mode = MODE_DEC_INSENSITIVE;

static void
show_stats (const char *path1, const char *path2)
{
  const int MAX_LENGTH = 255;
  char time_format[] = "%Y-%m-%d %H:%M:%S %z";
  struct stat st[2];
  int ret = -1;

  ret = stat(path1, &st[0]);
  assert (ret == 0);
  ret = stat(path2, &st[1]);
  assert (ret == 0);

  time_t rawtime[2];
  struct tm *timeinfo[2];
  char buf[2][MAX_LENGTH + 1];
  rawtime[0] = st[0].st_mtime;
  timeinfo[0] = localtime(&rawtime[0]);
  strftime(buf[0], MAX_LENGTH, time_format, timeinfo[0]);
  printf ("--- %s\t%s\n", path1, buf[0]);
  rawtime[1] = st[1].st_mtime;
  timeinfo[1] = localtime(&rawtime[1]);
  strftime(buf[1], MAX_LENGTH, time_format, timeinfo[1]);
  printf ("+++ %s\t%s\n", path2, buf[1]);
}

template <typename comparator>
static void
logdiff (const char *path1, const char *path2)
{
  typedef string elem;
  typedef vector<elem> sequence;
  typedef pair<elem, elemInfo> sesElem;

  ifstream ifs1 (path1);
  ifstream ifs2 (path2);
  elem buf;
  sequence seq1, seq2;

  while (getline(ifs1, buf))
    seq1.push_back(buf);
  while (getline(ifs2, buf))
    seq2.push_back(buf);

  Diff<elem, sequence, comparator> diff(seq1, seq2);
  diff.onHuge();
  diff.compose();

  int dist = diff.getEditDistance();
  if (dist > 0)
    show_stats (path1, path2);

  diff.composeUnifiedHunks();
  diff.printUnifiedFormat();
}

static void
usage (void)
{
  fprintf (stderr, "[USAGE] logdiff FILE1 FILE2\n");
  fprintf (stderr, "  -d : Insensitive for decimal number (default).\n");
  fprintf (stderr, "  -x : Insensitive for hex number.\n");
  fprintf (stderr, "  -D : Insensitive for continuous decimal numbers.\n");
  fprintf (stderr, "  -X : Insensitive for continuous hex numbers.\n");
  exit (EXIT_FAILURE);
}

int
main (int argc, char *argv[])
{
  int c = -1;

  while ((c = getopt (argc, argv, "hdxDX")) != -1)
    {
      switch (c)
        {
        case 'd':
          comp_mode = MODE_DEC_INSENSITIVE;
          break;
        case 'x':
          comp_mode = MODE_HEX_INSENSITIVE;
          break;
        case 'D':
          comp_mode = MODE_DECS_INSENSITIVE;
          break;
        case 'X':
          comp_mode = MODE_HEXS_INSENSITIVE;
          break;
        case 'h':
        default:
          usage ();
          break;
        }
    }

  if (argc - optind != 2)
    {
      usage ();
    }

  const char *path1 = argv[optind];
  const char *path2 = argv[optind + 1];

  assert (access (path1, R_OK) == 0);
  assert (access (path2, R_OK) == 0);

  switch (comp_mode)
    {
    case MODE_DEC_INSENSITIVE:
      logdiff<DecNumberInsensitive> (path1, path2);
      break;
    case MODE_HEX_INSENSITIVE:
      logdiff<HexNumberInsensitive> (path1, path2);
      break;
    case MODE_DECS_INSENSITIVE:
      logdiff<DecNumbersInsensitive> (path1, path2);
      break;
    case MODE_HEXS_INSENSITIVE:
      logdiff<HexNumbersInsensitive> (path1, path2);
      break;
    }

  return 0;
}
