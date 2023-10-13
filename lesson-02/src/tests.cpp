#include <iostream>
#include <gtest/gtest.h>

#include "utils.hpp"

class TestConvert : public ::testing::Test
{
protected:
    void SetUp() {}
    void TearDown() {}
protected:
    Allocator allocator_;
};

TEST_F(TestConvert, test_convert_to_string)
{
    ASSERT_EQ(std::string("100500"), convert_from_int(100500));
}

TEST_F(TestConvert, test_convert_to_int)
{
    ASSERT_EQ(100500, convert_to_int(std::string("100500")));
}

TEST_F(TestConvert, test_allocator_foo)
{
    ASSERT_TRUE(allocator_.foo());
    ASSERT_FALSE(Allocator::boo());
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
