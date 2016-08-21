//
//  Document.cpp
//  StyleSheet
//
//  Created by Michel Donais on 16-08-19.
//  Copyright © 2016 Michel Donais. All rights reserved.
//

#include "Document.h"

StyleSheet::CssDocument StyleSheet::CssDocument::parse(const string& doc)
{
    CssDocument document;
    tokenizer(doc, '\n', [&document](const string& str)
              {
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

StyleSheet::string StyleSheet::CssDocument::toString() const
{
    string result;
    for (auto it = begin(); it != end(); ++it)
    {
        result += it->toString() + "\n";
    }
    return result;
}
