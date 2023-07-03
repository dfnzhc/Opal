/**
 * @File CommonTest.cpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2023/7/3
 * @Brief 
 */
 
#include <gtest/gtest.h>

#include "Core/Core.hpp"

using namespace Opal::Core;

TEST(CommonTest, TestABC) {
    EXPECT_EQ(Add(1, 2), 3);
}

TEST(CommonTest, TestCBA) {
    EXPECT_EQ(Add(3, 4), 7);
}
