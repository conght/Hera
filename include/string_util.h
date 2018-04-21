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

namespace hera {


// A extra string utils set..
// Example:
//    ::hera::StringUtil::Func();
class StringUtil {
public:

	// Returns an vector contains the result of input string seperated by sep.
	// It is a static function.  And it is thread-safe.
    static std::vector<std::string> Split(const std::string &input, const std::string &seperator = ",");

};


}
#endif