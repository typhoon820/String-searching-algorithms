//
// Created by typhoon on 16.03.18.
//

#ifndef LAB_1_BORDERPREPROCESSOR_H
#define LAB_1_BORDERPREPROCESSOR_H


#include "IPreprocessor.h"

class BorderPreprocessor: public IPreprocessor{

public:
    unsigned long* evaluate_array(std::string &str) override;
    unsigned long* evaluate_modified_array(std::string &str) override;
};


#endif //LAB_1_BORDERPREPROCESSOR_H
