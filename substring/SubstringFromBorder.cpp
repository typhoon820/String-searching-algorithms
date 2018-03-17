//
// Created by typhoon on 28.02.18.
//

#include "SubstringFromBorder.h"


//unsigned long *SubstringFromBorder::evaluate_array(std::string &input) {
//    auto *res = new unsigned long[input.length()];
//    unsigned long prev_border = 0;
//    res[0] = 0;
//    for (unsigned long i = 1; i < input.length(); ++i) {
//        prev_border = res[i - 1];
//        while (prev_border && (input[i] != input[prev_border]))
//            prev_border = res[prev_border - 1];
//        if (input[i] == input[prev_border])
//            res[i] = prev_border + 1;
//        else
//            res[i] = 0;
//    }
//    return res;
//}

SubstringFromBorder::SubstringFromBorder(const std::string &source_text, const std::string &pattern) : ISubstring(
        source_text, pattern) {}

std::list<unsigned long> SubstringFromBorder::positions() {
    //auto *res = new unsigned long[_source_text.length()];
    std::list<unsigned long> res;
    //std::fill_n(res, _source_text.length(), 0);
    unsigned long k = 0;
    std::string eval_str = _pattern + ESCAPE_CHARACTER + _source_text;
    unsigned long *temp = _preprocessor->evaluate_array(eval_str);
    for (unsigned long i = _pattern.length() + 1; i < eval_str.length(); ++i) {
        if (temp[i] == _pattern.length())
            res.push_back(i - (_pattern.length() << 1));
    }
    delete[] temp;
    return res;
}

SubstringFromBorder::~SubstringFromBorder() {

}

SubstringFromBorder::SubstringFromBorder(const std::string &source_text, const std::string &pattern,
                                         IPreprocessor *preprocessor) : ISubstring(source_text, pattern,
                                                                                   preprocessor) {}

std::list<unsigned long> SubstringFromBorder::modified_positions() {
    return std::list<unsigned long>();
}
