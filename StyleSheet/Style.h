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
#include <set>

namespace StyleSheet
{
    typedef std::list<CssSelector> CssSelectorList;
    
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
