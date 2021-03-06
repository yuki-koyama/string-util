/*
 MIT License

 Copyright (c) 2019 Yuki Koyama

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#ifndef string_util_hpp
#define string_util_hpp

#include <cassert>
#include <ctime>
#include <string>

namespace stringutil
{
    /// \brief Convert an unsigned integer into a string with zero padding.
    /// \param value The target unsigned integer value.
    /// \param length The target length of the resulting string
    /// \details The result of std::to_string(value).length() should not be
    ///          larger than the target length.
    template<typename T>
    std::string ConvertWithZeroPadding(const T& value,
                                       const unsigned int length)
    {
        std::string str = std::to_string(value);
        assert(length >= str.length());
        str.insert(0, length - str.length(), '0');
        return str;
    }

    /// \brief Create a string representing the current time.
    /// \details The reulst looks like: "20190909222032".
    inline std::string GetCurrentTimeAsString()
    {
        char buffer[100];
        const std::time_t t = std::time(nullptr);
        std::strftime(buffer, sizeof(buffer), "%Y%m%d%H%M%S", std::localtime(&t));
        return std::string(buffer);
    }
}

#endif /* string_util_hpp */
