//
//  Style.cpp
//  StyleSheet
//
//  Created by Michel Donais on 16-08-19.
//  Copyright © 2016 Michel Donais. All rights reserved.
//

#include "Style.h"
#include <stdexcept>

void StyleSheet::CssStyle::addClasses(const string& classTagValue)
{
    tokenizer(classTagValue, ' ', [this](const string& c)
              {
                  this->addClass(c);
              });
}

void StyleSheet::CssStyle::addClass(const string& c)
{
    if (c.empty())
    {
        return;
    }
    
    auto result = hasClassSelectors.insert(c);  // returns (where,newinsert)
    if (result.second)
    {
        classSelectors.push_back(CssSelector::CssClassSelector(c));
    }
}

void StyleSheet::CssStyle::removeClass(const string& c)
{
    auto result = hasClassSelectors.erase(c);   // returns num-erased (0 or 1)
    if (result > 0)
    {
        auto it = std::find(classSelectors.begin(), classSelectors.end(), CssSelector::CssClassSelector(c));
        if (it == classSelectors.end())
        {
            throw std::logic_error("Set and List aren't matching");
            return;
        }
        classSelectors.erase(it);
    }
}
