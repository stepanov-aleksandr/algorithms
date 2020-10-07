#ifndef TST_TESTS1_H
#define TST_TESTS1_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "../function.h"

using namespace testing;
using namespace function;

TEST(UnitTests, Test_FindPrimes_1) {
  std::vector<int> in_data_vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> out_data_vector{2, 3, 5, 7};
  FindPrimes(in_data_vector);
  auto ret = std::equal(in_data_vector.begin(), in_data_vector.end(),
                        out_data_vector.begin());
  EXPECT_EQ(ret, true);
}

TEST(UnitTests, Test_FindPrimes_2) {
  std::vector<int> out_data_list{2, 3, 5, 7};
  std::list<int> in_data_list{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  FindPrimes(in_data_list);
  bool ret = std::equal(in_data_list.begin(), in_data_list.end(),
                        out_data_list.begin());
  EXPECT_EQ(ret, true);
}

TEST(UnitTests, Test_GetMinMax) {
  auto ret = GetMinMax(5);
  EXPECT_EQ(ret.first, 3);
  EXPECT_EQ(ret.second, 3221225472);
}

TEST(UnitTests, Test_CountsNumberWorlds_1) {
  std::string path = "text.txt";
  auto ret = WordCount(path).get();
  std::map<int, int> out{{2, 2}, {2, 4}, {2, 5}};
  bool ret_ = std::equal(ret->begin(), ret->end(), out.begin());
  EXPECT_EQ(ret_, true);
}

#endif  // TST_TESTS1_H
