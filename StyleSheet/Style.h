//
//  Style.h
//  StyleSheet
//
//  Created by Michel Donais on 16-08-19.
//  Copyright © 2016 Michel Donais. All rights reserved.
//

#ifndef Style_h
#define Style_h

#include "PropertySet.h"
#include "Selector.h"
#include <list>

namespace StyleSheet
{
    typedef std::list<CssSelector> CssSelectorList;
    
    class CssStyle
    {
    public:
        CssStyle(const string& cssId, const string& cssType);
        const CssSelector& getIdSelector() const;
        const CssSelector& getTypeSelector() const;
        
        void setType(const string& cssType);
        const CssSelectorList& getClassSelectors() const;
        
        void addClasses(const string& classTagValue);
        void addClass(const string& c);
        void removeClass(const string& c);
        bool hasClass(const string& c);
        void setInlineProperties(const CssPropertySet& inlineProperies);
        const CssPropertySet& getInlineProperties() const;
    };
}

#endif /* Style_h */
