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

#include <iostream>

#include "../include/string_util.h"

int main()
{
	std::cout << " test split ( std::string, char ) ... " << std::endl;
	std::string original_string = "Hello World , I am Hera !";
	std::vector<std::string> v;
	char sep = ' ';
	::hera::split(original_string, v, sep);
	for (auto iter=v.begin();iter!=v.end();iter++) 
	{
		std::cout << (*iter) << std::endl;
	}

	std::cout << " test split ( std::wstring, wchar_t ) ... " << std::endl;
	std::wstring original_wstring = L"Hello World , I am Hera !";
	
	wchar_t w_sep = ' ';
	std::vector<std::wstring> w_v;
	::hera::split(original_wstring, w_v, w_sep);
	for (auto iter=w_v.begin();iter!=w_v.end();iter++) 
	{
		std::wcout << (*iter) << std::endl;
	}

	std::cout << " test split ( std::string, std::string ) ... " << std::endl;
	std::string str_sep = " ";
	::hera::split(original_string, v, str_sep);
	for (auto iter=v.begin();iter!=v.end();iter++) 
	{
		std::cout << (*iter) << std::endl;
	}
	return 0;
}