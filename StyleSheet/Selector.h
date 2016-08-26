//
//  Selector.h
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

#ifndef Selector_h
#define Selector_h

#include "StyleSheetGlobals.h"
#include <list>

namespace StyleSheet
{
    class CssSelector
    {
    public:
        enum Type
        {
            kType,
            kClass,
            kId
        };
        
        static CssSelector CssTypeSelector(const string& name)
        {
            return CssSelector(kType, name);
        }
        static CssSelector CssClassSelector(const string& name)
        {
            return CssSelector(kClass, name);
        }
        static CssSelector CssIdSelector(const string& name)
        {
            return CssSelector(kId, name);
        }
        static CssSelector parse(string str);
        
        bool operator==(const CssSelector& other) const
        {
            return type == other.type && name == other.name;
        }
        bool operator!=(const CssSelector& other) const
        {
            return !(operator==(other));
        }
        bool operator<(const CssSelector& other) const
        {
            return type < other.type || (type == other.type && name < other.name);
        }
        
        const Type& getType() const
        {
            return type;
        }
        const string& getName() const
        {
            return name;
        }
        bool isType() const
        {
            return type == kType;
        }
        bool isClass() const
        {
            return type == kClass;
        }
        bool isId() const
        {
            return type == kId;
        }
        
        string toString() const;
                
    private:
        CssSelector(Type type, const string& name);
        
        Type type;
        string name;
    };
    
    typedef std::list<CssSelector> CssSelectorList;
}


namespace std
{
    template<>
    struct hash<StyleSheet::CssSelector>
    {
        std::size_t operator()(const StyleSheet::CssSelector& k) const
        {
            return
                StyleSheet::rotl(std::hash<int>()((int)k.getType()),1) ^
                std::hash<std::string>()(k.getName());
        }
    };
}

#endif /* Selector_h */
