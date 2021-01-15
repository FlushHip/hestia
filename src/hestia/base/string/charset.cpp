#include "hestia/base/string/charset.h"

#include <locale>
#include <codecvt>
#include <cwchar>
#include <memory>

namespace hestia
{

namespace base
{

namespace string
{

namespace
{

bool InitLocale()
{
    setlocale(LC_CTYPE, "");
    return true;
}

bool IsInit = InitLocale();

} // namespace

bool UnicodeToUTF8(const std::wstring &strSource, std::string &strDest)
{
    try {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> cv;
        strDest = cv.to_bytes(strSource);
        return true;
    } catch (std::exception &) {
    }
    return false;
}

bool UTF8ToUnicode(const std::string &strSource, std::wstring &strDest)
{
    try {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> cv;
        strDest = cv.from_bytes(strSource);
        return true;
    } catch (std::exception &){
    }
    return false;
}

std::string UnicodeToUTF8(const std::wstring &strSource)
{
    std::string result;
    UnicodeToUTF8(strSource, result);
    return result;
}

std::wstring UTF8ToUnicode(const std::string &strSource)
{
    std::wstring result;
    UTF8ToUnicode(strSource, result);
    return result;
}

bool UnicodeToANSI(const std::wstring &strSource, std::string &strDest)
{
    std::mbstate_t state = {};
    auto src = strSource.data();
    size_t invalid = static_cast<size_t>(-1);
    size_t length = std::wcsrtombs(nullptr, &src, 0, &state);
    if (length == invalid)
        return false;
    auto buffer = std::make_unique<char[]>(length + 1);
    if (invalid != std::wcsrtombs(buffer.get(), &src, length, &state)) {
        strDest.assign(buffer.get(), length);
        return true;
    }
    return false;
}

bool ANSIToUnicode(const std::string &strSource, std::wstring &strDest)
{
    std::mbstate_t state = {};
    auto src = strSource.data();
    size_t invalid = static_cast<size_t>(-1);
    size_t length = std::mbsrtowcs(nullptr, &src, 0, &state);
    if (length == invalid)
        return false;
    auto buffer = std::make_unique<wchar_t[]>(length + 1);
    if (invalid != std::mbsrtowcs(buffer.get(), &src, length, &state)) {
        strDest.assign(buffer.get(), length);
        return true;
    }
    return false;
}

std::string UnicodeToANSI(const std::wstring &strSource)
{
    std::string result;
    UnicodeToANSI(strSource, result);
    return result;
}

std::wstring ANSIToUnicode(const std::string &strSource)
{
    std::wstring result;
    ANSIToUnicode(strSource, result);
    return result;
}

bool UTF8ToANSI(const std::string &strSource, std::string &strDest)
{
    std::wstring unicode;
    if (UTF8ToUnicode(strSource, unicode))
        return UnicodeToANSI(unicode, strDest);
    return false;
}

bool ANSIToUTF8(const std::string &strSource, std::string &strDest)
{
    std::wstring unicode;
    if (ANSIToUnicode(strSource, unicode))
        return UnicodeToUTF8(unicode, strDest);
    return false;
}

std::string UTF8ToANSI(const std::string &strSource)
{
    std::string result;
    UTF8ToANSI(strSource, result);
    return result;
}

std::string ANSIToUTF8(const std::string &strSource)
{
    std::string result;
    ANSIToUTF8(strSource, result);
    return result;
}
    
} // namespace string
 
} // namespace base

} // namespace hestia