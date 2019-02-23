#include <string>
#include <stdio.h>
#include <assert.h>

#include <dtl/dtl.hpp>
#include <gtest/gtest.h>

#include "comparator.h"

TEST (TestDecNumberInsensitive, OneNumbersSameString) {
  DecNumberInsensitive c;
  ASSERT_TRUE(c.impl("123: abc", "456: abc"));
}

TEST (TestDecNumberInsensitive, OneNumbersDiffString) {
  DecNumberInsensitive c;
  ASSERT_FALSE(c.impl("123: abcd", "456: abc"));
}
