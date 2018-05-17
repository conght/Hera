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


#ifndef HERA_INCLUDE_CLOCK_H_
#define HERA_INCLUDE_CLOCK_H_

#include <chrono>

namespace hera
{
	template<class Proid>
	std::time_t get_current_timestamp()
	{
		using namespace std::chrono;

		time_point<system_clock, Proid> tp = time_point_cast<Proid>(system_clock::now());  
    	return duration_cast<Proid>(tp.time_since_epoch()).count();  
	}

	std::time_t get_second_timestamp()
	{
		return get_current_timestamp<std::chrono::seconds>();
	}

	std::time_t get_millisecond_timestamp()
	{
		return get_current_timestamp<std::chrono::milliseconds>();
	}

	std::time_t get_mircosecond_timestamp()
	{
		return get_current_timestamp<std::chrono::microseconds>();
	}

}
#endif