//
//  Parser.cpp
//  StyleSheet
//
//  Created by Michel Donais on 16-08-19.
//  Copyright © 2016 Michel Donais. All rights reserved.
//

#include "Parser.h"

StyleSheet::CssPropertySet StyleSheet::CssParser::getProperties(const CssStyle& style) const
{
    CssPropertySet result;
    
    result.add(style.getInlineProperties());
    result.add(doc.getProperties(style.getIdSelector()));
    result.add(doc.getProperties(style.getTypeSelector()));
    result.add(doc.getProperties(style.getClassSelectors()));

    return result;
}
