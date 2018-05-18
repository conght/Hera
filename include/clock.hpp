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

#include <iostream>
#include <chrono>
#include "noncopyable.h"

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


template<class Proid>
class ProidLiteral
{
public:
	static inline std::string literal_value() {
		return " s";
	}
};

template<>
class ProidLiteral<std::nano>
{
public:
	static inline std::string literal_value() {
		return " ns";
	}
};

template<>
class ProidLiteral<std::micro>
{
public:
	static inline std::string literal_value() {
		return " us";
	}
};

template<>
class ProidLiteral<std::milli>
{
public:
	static inline std::string literal_value() {
		return " ms";
	}
};

template<class Proid>
class ProgressTimer : private Noncopyable
{
public:
	explicit ProgressTimer( std::ostream & os = std::cout )
	// os is hint; implementation may ignore, particularly in embedded systems
	: Noncopyable(), m_os(os) { _start_time = std::chrono::high_resolution_clock::now(); }

	void   restart() { _start_time = std::chrono::high_resolution_clock::now(); }
	double elapsed() const     // return elapsed time in Proid
	{
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
		return std::chrono::duration_cast<std::chrono::duration<double, Proid> >(t2 - _start_time).count();
	}

	~ProgressTimer()
	{
		//  A) Throwing an exception from a destructor is a Bad Thing.
		//  B) The ProgressTimer destructor does output which may throw.
		//  C) A ProgressTimer is usually not critical to the application.
		//  Therefore, wrap the I/O in a try block, catch and ignore all exceptions.
		try
		{
			// use istream instead of ios_base to workaround GNU problem (Greg Chicares)
			std::istream::fmtflags old_flags = m_os.setf( std::istream::fixed,
			                                           std::istream::floatfield );
			//std::streamsize old_prec = m_os.precision( 2 );
			m_os << elapsed() << ProidLiteral<Proid>::literal_value() << "\n"; // "s" is System International d'Unites std
			m_os.flags( old_flags );
			//m_os.precision( old_prec );
	    }

	    catch (...) {} // eat any exceptions
	} // ~ProgressTimer

private:
	std::ostream & m_os;
	std::chrono::high_resolution_clock::time_point _start_time;
};


}
#endif