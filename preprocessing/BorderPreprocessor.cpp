//
// Created by typhoon on 16.03.18.
//

#include "BorderPreprocessor.h"

unsigned long *BorderPreprocessor::evaluate_array(std::string &str) {
    auto *res = new unsigned long[str.length()];
    unsigned long prev_border = 0;
    res[0] = 0;
    for (unsigned long i = 1; i < str.length(); ++i) {
        prev_border = res[i - 1];
        while (prev_border && (str[i] != str[prev_border]))
            prev_border = res[prev_border - 1];
        if (str[i] == str[prev_border])
            res[i] = prev_border + 1;
        else
            res[i] = 0;
    }
    return res;
}

unsigned long *BorderPreprocessor::evaluate_modified_array(std::string &str) {
    auto *res = new unsigned long[str.length()];
    unsigned long *borders = evaluate_array(str);
    res[0] = 0;
    res[str.length()-1] = borders[str.length()-1];
    for(int i = 0; i< str.length()-1; i++){
        if(borders[i] && (borders[i]+1 == borders[i+1])){
            res[i] = res[borders[i] -1];
        } else{
            res[i] = borders[i];
        }
    }
    return res;
}
