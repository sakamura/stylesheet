//
//  Document.h
//  StyleSheet
//
//  Created by Michel Donais on 16-08-19.
//  Copyright © 2016 Michel Donais. All rights reserved.
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
