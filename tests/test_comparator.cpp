#include <string>
#include <stdio.h>
#include <assert.h>

#include <dtl/dtl.hpp>
#include <gtest/gtest.h>

#include "comparator.h"

class TestDecNumberInsensitive: public ::testing::Test {
  protected:
  DecNumberInsensitive c;
};

TEST_F (TestDecNumberInsensitive, NoNumbersSameString) {
  ASSERT_TRUE(c.impl("abc",
                     "abc"));
}

TEST_F (TestDecNumberInsensitive, NoNumbersDiffString) {
  ASSERT_FALSE(c.impl("abd",
                      "abc"));
}

TEST_F (TestDecNumberInsensitive, OneNumbersSameString) {
  ASSERT_TRUE(c.impl("123: abc",
                     "456: abc"));
}

TEST_F (TestDecNumberInsensitive, OneNumbersDiffString) {
  ASSERT_FALSE(c.impl("123: abd",
                      "456: abc"));
}

TEST_F (TestDecNumberInsensitive, OneDiffLenNumbersDiffString) {
  ASSERT_FALSE(c.impl("1234: abc",
                      "456: abc"));
}

TEST_F (TestDecNumberInsensitive, MultiNumbersSameString) {
  ASSERT_TRUE(c.impl("123: abc: 456",
                     "456: abc: 789"));
}

TEST_F (TestDecNumberInsensitive, MultiNumbersDiffString) {
  ASSERT_FALSE(c.impl("123: abd: 456",
                      "456: abc: 789"));
}

class TestHexNumberInsensitive: public ::testing::Test {
  protected:
  HexNumberInsensitive c;
};

TEST_F (TestHexNumberInsensitive, NoNumbersSameString) {
  ASSERT_TRUE(c.impl("xyz",
                     "xyz"));
}

TEST_F (TestHexNumberInsensitive, NoNumbersDiffString) {
  ASSERT_FALSE(c.impl("xyw",
                      "xyz"));
}

TEST_F (TestHexNumberInsensitive, OneNumbersSameString) {
  ASSERT_TRUE(c.impl("0x0123456789AbCdEf: xyz",
                     "0xFeDcBa9876543210: xyz"));
}

TEST_F (TestHexNumberInsensitive, OneNumbersDiffString) {
  ASSERT_FALSE(c.impl("0x0123456789AbCdEf: xyw",
                      "0xFeDcBa9876543210: xyz"));
}

TEST_F (TestHexNumberInsensitive, OneDiffLenNumbersDiffString) {
  ASSERT_FALSE(c.impl("0x0123456789AbCdEff: xyz",
                      "0xFeDcBa9876543210: xyz"));
}

TEST_F (TestHexNumberInsensitive, MultiNumbersSameString) {
  ASSERT_TRUE(c.impl("0x0123456789AbCdEf: xyz: 0xFeDcBa9876543210",
                     "0xFeDcBa9876543210: xyz: 0x0123456789AbCdEf"));
}

TEST_F (TestHexNumberInsensitive, MultiNumbersDiffString) {
  ASSERT_FALSE(c.impl("0x0123456789AbCdEf: xyw: 0xFeDcBa9876543210",
                      "0xFeDcBa9876543210: xyz: 0x0123456789AbCdEf"));
}

class TestDecNumbersInsensitive: public ::testing::Test {
  protected:
  DecNumbersInsensitive c;
};

TEST_F (TestDecNumbersInsensitive, NoNumbersSameString) {
  ASSERT_TRUE(c.impl("abc",
                     "abc"));
}

TEST_F (TestDecNumbersInsensitive, NoNumbersDiffString) {
  ASSERT_FALSE(c.impl("abd",
                      "abc"));
}

TEST_F (TestDecNumbersInsensitive, OneNumbersSameString) {
  ASSERT_TRUE(c.impl("123: abc",
                     "456: abc"));
}

TEST_F (TestDecNumbersInsensitive, OneNumbersDiffString) {
  ASSERT_FALSE(c.impl("123: abd",
                      "456: abc"));
}

TEST_F (TestDecNumbersInsensitive, OneDiffLenNumbersDiffString) {
  ASSERT_TRUE(c.impl("1234: abc",
                     "456: abc"));
}

TEST_F (TestDecNumbersInsensitive, MultiNumbersSameString) {
  ASSERT_TRUE(c.impl("123: abc: 456",
                     "456: abc: 789"));
}

TEST_F (TestDecNumbersInsensitive, MultiNumbersDiffString) {
  ASSERT_FALSE(c.impl("123: abd: 456",
                      "456: abc: 789"));
}

class TestHexNumbersInsensitive: public ::testing::Test {
  protected:
  HexNumbersInsensitive c;
};

TEST_F (TestHexNumbersInsensitive, NoNumbersSameString) {
  ASSERT_TRUE(c.impl("xyz",
                     "xyz"));
}

TEST_F (TestHexNumbersInsensitive, NoNumbersDiffString) {
  ASSERT_FALSE(c.impl("xyw",
                      "xyz"));
}

TEST_F (TestHexNumbersInsensitive, OneNumbersSameString) {
  ASSERT_TRUE(c.impl("0x0123456789AbCdEf: xyz",
                     "0xFeDcBa9876543210: xyz"));
}

TEST_F (TestHexNumbersInsensitive, OneNumbersDiffString) {
  ASSERT_FALSE(c.impl("0x0123456789AbCdEf: xyw",
                      "0xFeDcBa9876543210: xyz"));
}

TEST_F (TestHexNumbersInsensitive, OneDiffLenNumbersDiffString) {
  ASSERT_TRUE(c.impl("0x0123456789AbCdEff: xyz",
                     "0xFeDcBa9876543210: xyz"));
}

TEST_F (TestHexNumbersInsensitive, MultiNumbersSameString) {
  ASSERT_TRUE(c.impl("0x0123456789AbCdEf: xyz: 0xFeDcBa9876543210",
                     "0xFeDcBa9876543210: xyz: 0x0123456789AbCdEf"));
}

TEST_F (TestHexNumbersInsensitive, MultiNumbersDiffString) {
  ASSERT_FALSE(c.impl("0x0123456789AbCdEf: xyw: 0xFeDcBa9876543210",
                      "0xFeDcBa9876543210: xyz: 0x0123456789AbCdEf"));
}
