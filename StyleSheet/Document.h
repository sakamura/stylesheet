//
//  Document.h
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

#ifndef Document_h
#define Document_h

#include "Element.h"
#include <unordered_set>

namespace StyleSheet
{
    class CssDocument : protected std::unordered_set<CssElement>
    {
    public:
        static CssDocument parse(const string& doc);
        
        size_t getElementCount() const
        {
            return size();
        }
        CssElement getElement(const CssSelector& selector) const;
        
        CssPropertySet getProperties(const CssSelector& selector) const;
        CssPropertySet getProperties(const CssSelectorList& selectors) const;
        
        bool hasSelector(const CssSelector& selector) const
        {
            CssElement element(selector, CssPropertySet());
            return find(element) != end();
        }
        void addElement(const CssElement& element)
        {
            if (element.getPropertyCount() != 0)
            {
                insert(element);
            }
        }
        string toString() const;
    };
}

#endif /* Document_h */
