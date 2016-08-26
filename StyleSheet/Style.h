//
//  Style.h
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

#ifndef Style_h
#define Style_h

#include "PropertySet.h"
#include "Selector.h"
#include <set>

namespace StyleSheet
{
    class CssStyle
    {
    public:
        CssStyle(const string& cssId, const string& cssType) :
            id(CssSelector::CssIdSelector(cssId)),
            type(CssSelector::CssTypeSelector(cssType))
        {
        }
        const CssSelector& getIdSelector() const
        {
            return id;
        }
        const CssSelector& getTypeSelector() const
        {
            return type;
        }
        
        void setType(const string& cssType)
        {
            type = CssSelector::CssTypeSelector(cssType);
        }
        const CssSelectorList& getClassSelectors() const
        {
            return classSelectors;
        }
        
        void addClasses(const string& classTagValue);
        void addClass(const string& c);
        void removeClass(const string& c);
        bool hasClass(const string& c)
        {
            return hasClassSelectors.find(c) != hasClassSelectors.end();
        }
        void setInlineProperties(const CssPropertySet& inlineProperties_)
        {
            inlineProperties = inlineProperties_;
        }
        const CssPropertySet& getInlineProperties() const
        {
            return inlineProperties;
        }
        
    private:
        const CssSelector id;
        CssSelector type;
        CssSelectorList classSelectors;
        std::set<string> hasClassSelectors;
        CssPropertySet inlineProperties;
    };
}

#endif /* Style_h */
