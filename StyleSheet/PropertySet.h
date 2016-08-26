//
//  PropertySet.h
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

#ifndef PropertySet_h
#define PropertySet_h

#include "Property.h"
#include <map>

namespace StyleSheet
{
    class CssPropertySet : protected std::map<string, CssProperty>
    {
    protected:
        typedef typename std::map<string, CssProperty> Super;
        
    public:
        static CssPropertySet parse(const string& str);
        
        void add(const CssProperty& prop)
        {
            if (prop.isValid())
            {
                insert(std::make_pair(prop.getName(), prop));
            }
        }
        void add(const CssPropertySet& propSet)
        {
            insert(propSet.begin(), propSet.end());
        }
        
        void remove(const string& propName)
        {
            erase(propName);
        }
        void remove(const CssProperty& prop)
        {
            remove(prop.getName());
        }

        size_t size() const
        {
            return Super::size();
        }
        bool empty() const
        {
            return Super::empty();
        }
        
        const CssProperty& getProperty(const string& name) const
        {
            const_iterator iter = find(name);
            if (iter == end())
            {
                return CssProperty::Empty();
            }
            else
            {
                return iter->second;
            }
        }
        
        string toString() const;
    };
}

#endif /* PropertySet_h */
