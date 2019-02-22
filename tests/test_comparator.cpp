#include <string>
#include <stdio.h>
#include <assert.h>

#include <dtl/dtl.hpp>

#include "comparator.h"

static void
test (const std::string& lhs, const std::string& rhs, const bool exp)
{
  DecNumberInsensitive c;
  assert (exp == c.impl(lhs, rhs));
}

int
main (void)
{
  test ("123: abc", "456: abc", true);
  test ("123: abcd", "456: abc", false);
  return 0;
}
