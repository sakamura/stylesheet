//
//  Property.h
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

#ifndef Property_h
#define Property_h

#include "StyleSheetGlobals.h"

namespace StyleSheet
{
    class CssProperty
    {
    public:
        static const CssProperty& Empty();
        static CssProperty parse(const string& str);
        
        CssProperty(const string& _name, const string& _value) :
            name(_name),
            value(_value)
        {
        }
        
        bool operator<(const CssProperty& p) const
        {
            return name < p.name;
        }
        
        const string& getName() const
        {
            return name;
        }
        const string& getValue() const
        {
            return value;
        }
        
        bool isValid() const
        {
            return !name.empty();
        }
        
        string toString() const;
        
    private:
        string name;
        string value;
    };
}

#endif /* Property_h */
