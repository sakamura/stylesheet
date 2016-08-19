//
//  Parser.h
//  StyleSheet
//
//  Created by Michel Donais on 16-08-19.
//  Copyright © 2016 Michel Donais. All rights reserved.
//

#ifndef Parser_h
#define Parser_h

#include "Document.h"
#include "Style.h"

namespace StyleSheet
{
    class CssParser
    {
        CssParser(const CssDocument& doc);
        CssPropertySet getProperties(const CssStyle& style) const;
    };
    
}

#endif /* Parser_h */
