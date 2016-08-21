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
    public:
        CssParser(const CssDocument& doc_) :
            doc(doc_)
        {
        }
        CssPropertySet getProperties(const CssStyle& style) const;
        
    private:
        const CssDocument& doc;
    };
}

#endif /* Parser_h */
