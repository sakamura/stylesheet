//
//  Style.cpp
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
