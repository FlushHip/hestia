#include <gtest/gtest.h>

#include "hestia/base/string/charset.h"

TEST(String, UnicodeToUTF8)
{
    EXPECT_EQ(hestia::base::string::UnicodeToUTF8(L"FlushHip"), u8"FlushHip");
}

TEST(String, UTF8ToUnicode)
{
    EXPECT_EQ(hestia::base::string::UTF8ToUnicode(u8"FlushHip"), L"FlushHip");
}