//
// Created by typhoon on 16.03.18.
//

#ifndef LAB_1_BLOCKPREPROCESSOR_H
#define LAB_1_BLOCKPREPROCESSOR_H


#include "IPreprocessor.h"

class BlockPreprocessor: public IPreprocessor {
private:
    unsigned long cmp(const std::string &str, unsigned long var1, unsigned long var2);

public:
    unsigned long* evaluate_array(std::string &str) override;

    BlockPreprocessor();
};


#endif //LAB_1_BLOCKPREPROCESSOR_H
