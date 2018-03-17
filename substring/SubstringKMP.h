//
// Created by typhoon on 16.03.18.
//

#ifndef LAB_1_SUBSTRINGKMP_H
#define LAB_1_SUBSTRINGKMP_H


#include "ISubstring.h"
#include <map>

class SubstringKMP: public ISubstring {
private:
    const int ALPHABET_POWER = 256;
    std::list<std::map<char, unsigned long>> matrix;
    unsigned long *borders_modidied;
    unsigned long **matr;
    void evaluate_borders_modified();
    void evaluate_matrix(unsigned long *borders_modified);
    std::list<unsigned long> positions() override;
    std::list<unsigned long> modified_positions() override;
public:
    SubstringKMP(const std::string &source_text, const std::string &pattern, IPreprocessor *preprocessor);

    unsigned long *substring_online();
};


#endif //LAB_1_SUBSTRINGKMP_H
