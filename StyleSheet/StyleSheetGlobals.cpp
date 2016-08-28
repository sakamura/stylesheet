//
//  StyleSheetGlobals.cpp
//  StyleSheet
//
//  MIT License
//
//  Copyright (c) 2016 Michel Donais
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
//

#include "StyleSheetGlobals.h"
#include <stdexcept>

static bool isnotspace(const char& c)
{
    return !isspace(c);
}

StyleSheet::string StyleSheet::trim(string& str)
{
    str.erase(str.begin(), find_if(str.begin(), str.end(), isnotspace));
    str.erase(find_if(str.rbegin(), str.rend(), isnotspace).base(), str.end());
    return str;
}

bool StyleSheet::parametrizer(const string& str, const string::value_type& delim, const string::value_type& eoldelim, string& left, string& right)
{
    const size_t cutoff = str.find_first_of(delim);
    if (cutoff == string::npos)
    {
        throw std::invalid_argument("Cannot find delimiter");
        return false;
    }
    left = str.substr(0, cutoff);
    trim(left);
    
    const size_t endofline = str.find_first_of(eoldelim, cutoff);
    if (endofline == string::npos)
    {
        if (cutoff == str.size() - 1)
        {
            throw std::invalid_argument("No value");
            return false;
        }
        right = str.substr(cutoff + 1);
    }
    else
    {
        right = str.substr(cutoff + 1, endofline - cutoff - 1);
    }
    trim(right);
    
    return true;
}
