//
// Created by typhoon on 28.02.18.
//

#ifndef LAB_1_SUBSTRINGFROMBORDER_H
#define LAB_1_SUBSTRINGFROMBORDER_H


#include "ISubstring.h"

class SubstringFromBorder: public ISubstring {

private:
    //std::string _source_text;
    //virtual unsigned long* evaluate_array(std::string& input) override;
    virtual std::list<unsigned long> positions() override;
    std::list<unsigned long> modified_positions() override;
public:
    SubstringFromBorder(const std::string &source_text, const std::string &pattern);

    SubstringFromBorder(const std::string &source_text, const std::string &pattern, IPreprocessor *preprocessor);

    virtual ~SubstringFromBorder();
};


#endif //LAB_1_SUBSTRINGFROMBORDER_H
