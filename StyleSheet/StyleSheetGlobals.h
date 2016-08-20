//
//  StyleSheetGlobals.h
//  StyleSheet
//
//  Created by Michel Donais on 16-08-19.
//  Copyright © 2016 Michel Donais. All rights reserved.
//

#ifndef StyleSheetGlobals_h
#define StyleSheetGlobals_h

#include <string>
#include <functional>

namespace StyleSheet {
    typedef std::string string;
    typedef std::size_t size_t;
    
    void tokenizer(const string& str, const string::value_type& delim, std::function<void (const string& token)> f);
    string trim(string& str);
    bool parametrizer(const string& str, const string::value_type& delim, const string::value_type& eoldelim, string& left, string& right);
}

#endif /* StyleSheetGlobals_h */
