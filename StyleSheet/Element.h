//
//  Element.h
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

#ifndef Element_h
#define Element_h

#include "Selector.h"
#include "PropertySet.h"

namespace StyleSheet
{
    class CssElement
    {
    public:
        static CssElement parse(const string& str);
        
        CssElement(const CssSelector& selector_, const CssPropertySet& properties_) :
            selector(selector_),
            properties(properties_)
        {
        }
        
        bool operator<(const CssElement& e) const
        {
            return selector < e.selector;
        }
        
        const CssSelector& getSelector() const
        {
            return selector;
        }
        size_t getPropertyCount() const
        {
            return properties.size();
        }
        const CssPropertySet& getProperties() const
        {
            return properties;
        }
        
        void addProperty(const CssProperty& prop)
        {
            properties.add(prop);
        }
        
        string toString() const;
        
        bool operator== (const CssElement& r) const
        {
            return getSelector() == r.getSelector();
        }
    private:
        CssSelector selector;
        CssPropertySet properties;
    };
}

namespace std
{
    template<>
    struct hash<StyleSheet::CssElement>
    {
        std::size_t operator()(const StyleSheet::CssElement& k) const
        {
            return std::hash<StyleSheet::CssSelector>()(k.getSelector());
        }
    };
}

#endif /* Element_h */
