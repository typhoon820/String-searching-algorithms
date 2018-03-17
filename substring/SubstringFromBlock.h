//
// Created by typhoon on 28.02.18.
//

#ifndef LAB_1_SUBSTRINGFROMBLOCK_H
#define LAB_1_SUBSTRINGFROMBLOCK_H


#include "ISubstring.h"

class SubstringFromBlock : public ISubstring {
private:
    //virtual unsigned long *evaluate_array(std::string &input) override;

    virtual std::list<unsigned long> positions() override;
    std::list<unsigned long> modified_positions() override;

    //unsigned long cmp(const std::string &str, unsigned long var1, unsigned long var2);

public:
    SubstringFromBlock(const std::string &source_text, const std::string &pattern);

    SubstringFromBlock(const std::string &source_text, const std::string &pattern, IPreprocessor *preprocessor);

    virtual ~SubstringFromBlock();

};


#endif //LAB_1_SUBSTRINGFROMBLOCK_H
