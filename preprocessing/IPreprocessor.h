//
// Created by typhoon on 16.03.18.
//

#ifndef LAB_1_PREPROCESS_H
#define LAB_1_PREPROCESS_H


#include <string>

class IPreprocessor {
public:
    virtual unsigned long* evaluate_array(std::string &str) = 0;
    virtual unsigned long* evaluate_modified_array(std::string &str) =0;
};


#endif //LAB_1_PREPROCESS_H
