#include "../include/clock.hpp"

#include <iostream>
#include <chrono>


int test_chrono_high_resolution_clock()  
{  
    // high_resolution_clock::now: Returns the current time_point in the frame of the high_resolution_clock  
    using namespace std::chrono;  
  
    high_resolution_clock::time_point t1 = high_resolution_clock::now();  
  
    std::cout << "printing out 1000 stars...\n";  
    for (int i = 0; i<1000; ++i) std::cout << "*";  
    std::cout << std::endl;  
  
    high_resolution_clock::time_point t2 = high_resolution_clock::now();  
  
    duration<double> time_span = duration_cast<duration<double> >(t2 - t1);  
  
    std::cout << "It took me " << time_span.count() << " seconds.";  
    std::cout << std::endl;  
  
    return 0;  
}

int test_chrono_system_clock()  
{ // system_clock::from_time_t: Converts t into its equivalent of member type time_point.  
    using namespace std::chrono;  
  
    // create tm with 1/1/2000:  
    std::tm timeinfo = std::tm();  
    timeinfo.tm_year = 100;   // year: 2000  
    timeinfo.tm_mon = 0;      // month: january  
    timeinfo.tm_mday = 1;     // day: 1st  
    std::time_t tt = std::mktime(&timeinfo);  
  
    system_clock::time_point tp = system_clock::from_time_t(tt);  
    system_clock::duration d = system_clock::now() - tp;  
  
    // convert to number of days:  
    typedef duration<int, std::ratio<60 * 60 * 24> > days_type;  
    days_type ndays = duration_cast<days_type> (d);  
  
    // display result:  
    std::cout << ndays.count() << " days have passed since 1/1/2000";  
    std::cout << std::endl;  
}

int test_chrono_nanoseconds_duration()  
{  
    ::hera::ProgressTimer<std::nano> pt;  
  
    return 0;  
}

int test_chrono_microseconds_duration()  
{  
    ::hera::ProgressTimer<std::micro> pt;  
  
    return 0;  
}

int test_chrono_milliseconds_duration()  
{  
    ::hera::ProgressTimer<std::milli> pt;  
  
    return 0;  
}

int test_chrono_seconds_duration()  
{  
    ::hera::ProgressTimer<std::ratio<1> > pt;  
  
    return 0;  
}


int main()
{
	test_chrono_nanoseconds_duration();
	test_chrono_microseconds_duration();
	test_chrono_milliseconds_duration();
    test_chrono_seconds_duration();
	
    std::cout << ::hera::get_second_timestamp() << std::endl;
	std::cout << ::hera::get_millisecond_timestamp() << std::endl;
	std::cout << ::hera::get_mircosecond_timestamp() << std::endl;
}