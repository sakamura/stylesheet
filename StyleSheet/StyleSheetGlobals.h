//
//  StyleSheetGlobals.h
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
    
    template<class T>
    inline T rotl(const T& value, int shift)
    {
        constexpr int bitsize = sizeof(value) * std::numeric_limits<T>::digits;
        shift = shift >=0 ? shift % bitsize : -( (-shift) % bitsize );
        return (value<<shift) | (value>>(bitsize-shift));
    }

}

#endif /* StyleSheetGlobals_h */
