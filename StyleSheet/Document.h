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

namespace StyleSheet
{
    class CssDocument
    {
        static CssDocument parse(const std::string& doc);
        
        CssDocument();
        
        std::size_t getElementCount() const;
        CssElement getElement(const CssSelector& selector) const;
        bool hasSelector(const CssSelector& selector) const;
        void addElement(const CssElement& element);
        std::string toString() const;
        
    };
}

#endif /* Document_h */
