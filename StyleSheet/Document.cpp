//
//  Document.cpp
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

#include "Document.h"

StyleSheet::CssDocument StyleSheet::CssDocument::parse(const string& doc)
{
    CssDocument document;
    tokenizer(doc, '\n', [&document](const string& str)
              {
                  if (!str.empty())
                      document.addElement(CssElement::parse(str));
              });
    return document;
}

StyleSheet::CssElement StyleSheet::CssDocument::getElement(const CssSelector& selector) const
{
    CssElement element(selector, CssPropertySet());
    auto result = find(element);
    if (result != end())
    {
        return *result;
    }
    else
    {
        return element;
    }
}

StyleSheet::CssPropertySet StyleSheet::CssDocument::getProperties(const CssSelector& selector) const
{
    CssElement element(selector, CssPropertySet());
    auto result = find(element);
    if (result != end())
    {
        return result->getProperties();
    }
    else
    {
        return CssPropertySet();
    }
}

StyleSheet::CssPropertySet StyleSheet::CssDocument::getProperties(const CssSelectorList& selectors) const
{
    CssPropertySet result;
    for (auto it = selectors.begin(); it != selectors.end(); ++it)
    {
        result.add(getProperties(*it));
    }
    return result;
}


StyleSheet::string StyleSheet::CssDocument::toString() const
{
    string result;
    for (auto it = begin(); it != end(); ++it)
    {
        result += it->toString() + "\n";
    }
    return result;
}
