// MIT License

// Copyright (c) 2018 conghanting(conghting@gmail.com)

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef HERA_INCLUDE_STRING_UTIL_H_
#define HERA_INCLUDE_STRING_UTIL_H_

#include <string>
#include <vector>
#include <sstream>

namespace hera {

template< class T > struct BasicStringType
{
    T item;
};

template<> struct BasicStringType<std::wstring>
{
    std::wstring item;
};

// Returns an vector contains the result of input string seperated by sep.
// It is a static function.  And it is thread-safe.
template<typename T>
static void split(const T &input, std::vector<T> &output, const T &seperator)
{
	output.clear();
    std::basic_stringstream<BasicStringType<T>.item::value_type> bss(input);
    T temp;

    while (std::getline(bss, temp, seperator)) {
        output.emplace_back(std::move(temp));
    }

    return;
}
}
#endif