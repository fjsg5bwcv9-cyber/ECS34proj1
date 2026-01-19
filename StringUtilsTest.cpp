#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    EXPECT_EQ(StringUtils::Slice("Hello", 1, 4), "ell");
    
}

TEST(StringUtilsTest, Capitalize){
    EXPECT_EQ(StringUtils::Capitalize("a"), "A");
    
}

TEST(StringUtilsTest, Upper){
    EXPECT_EQ(StringUtils::Upper("abc"), "ABC");
    
}

TEST(StringUtilsTest, Lower){
    EXPECT_EQ(StringUtils::Lower("ABC"), "abc");
    
}

TEST(StringUtilsTest, LStrip){
    EXPECT_EQ(StringUtils::LStrip(" hello "), "hello ");
    
}

TEST(StringUtilsTest, RStrip){
    EXPECT_EQ(StringUtils::RStrip(" hello "), " hello");
    
}

TEST(StringUtilsTest, Strip){
    EXPECT_EQ(StringUtils::Strip(" hello "), "hello");
    
}

TEST(StringUtilsTest, Center){
    EXPECT_EQ(StringUtils::Center("hi", 5, '.'), ".hi..");
    
}

TEST(StringUtilsTest, LJust){
    EXPECT_EQ(StringUtils::LJust("hi", 5, '.'), "hi...");
    
}

TEST(StringUtilsTest, RJust){
    EXPECT_EQ(StringUtils::RJust("hi", 5, '.'), "...hi");
    
}

TEST(StringUtilsTest, Replace){
    EXPECT_EQ(StringUtils::Replace("ccc", "c", "X"), "XXX");
    
}

TEST(StringUtilsTest, Split){
    EXPECT_EQ(
        StringUtils::Split("a,,b,", ","),
        (std::vector<std::string>{"a", "", "b", ""})
    );
}

TEST(StringUtilsTest, Join){
    EXPECT_EQ(
        StringUtils::Join("-", std::vector<std::string>{"a", "b", "c"}),
        "a-b-c"
    );
    
}

TEST(StringUtilsTest, ExpandTabs){
    EXPECT_EQ(
        StringUtils::ExpandTabs("a\tb", 4),
        "a   b"
    );
    
}

TEST(StringUtilsTest, EditDistance){
    EXPECT_EQ(
        StringUtils::EditDistance("kitten", "sitting"),
        3
    );
}
