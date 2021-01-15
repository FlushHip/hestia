#pragma once

#include <string>

namespace hestia
{

namespace base
{

namespace string
{

// https://flushhip.blog.csdn.net/article/details/82836867

bool UnicodeToUTF8(const std::wstring &strSource, std::string &strDest);
bool UTF8ToUnicode(const std::string &strSource, std::wstring &strDest);
std::string UnicodeToUTF8(const std::wstring &strSource);
std::wstring UTF8ToUnicode(const std::string &strSource);

bool UnicodeToANSI(const std::wstring &strSource, std::string &strDest);
bool ANSIToUnicode(const std::string &strSource, std::wstring &strDest);
std::string UnicodeToANSI(const std::wstring &strSource);
std::wstring ANSIToUnicode(const std::string &strSource);

bool UTF8ToANSI(const std::string &strSource, std::string &strDest);
bool ANSIToUTF8(const std::string &strSource, std::string &strDest);
std::string UTF8ToANSI(const std::string &strSource);
std::string ANSIToUTF8(const std::string &strSource);

} // namespace string
 
} // namespace base

} // namespace hestia