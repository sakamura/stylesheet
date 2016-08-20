//
//  StyleSheetGlobals.cpp
//  StyleSheet
//
//  Created by Michel Donais on 16-08-19.
//  Copyright © 2016 Michel Donais. All rights reserved.
//

#include "StyleSheetGlobals.h"
#include <stdexcept>

void StyleSheet::tokenizer(const string& str, const string::value_type& delim, std::function<void (const string& token)> f)
{
    if (str.empty())
    {
        return;
    }
    
    size_t start;
    size_t end = (size_t)-1;
    do
    {
        start = end + 1;
        end = str.find_first_of(delim, start);

        f(str.substr(start, end-start));

    } while (end < string::npos);
}

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
    if (cutoff == std::string::npos)
    {
        throw std::invalid_argument("Cannot find delimiter");
        return false;
    }
    left = str.substr(0, cutoff);
    trim(left);
    
    const size_t endofline = str.find_first_of(eoldelim, cutoff);
    if (endofline == std::string::npos)
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
