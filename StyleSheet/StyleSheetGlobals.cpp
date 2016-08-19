//
//  StyleSheetGlobals.cpp
//  StyleSheet
//
//  Created by Michel Donais on 16-08-19.
//  Copyright © 2016 Michel Donais. All rights reserved.
//

#include "StyleSheetGlobals.h"

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
