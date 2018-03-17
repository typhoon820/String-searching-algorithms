//
// Created by typhoon on 28.02.18.
//

#include "SubstringFromBlock.h"

SubstringFromBlock::SubstringFromBlock(const std::string &source_text, const std::string &pattern) : ISubstring(
        source_text, pattern) {}



std::list<unsigned long> SubstringFromBlock::positions() {
    //unsigned long *res = new unsigned long[_source_text.length()];
    std::list<unsigned long> res;
    //std::fill_n(res, _source_text.length(), 0);
    unsigned long k = 0;
    std::string eval_str = _pattern + ESCAPE_CHARACTER + _source_text;
    unsigned long *temp = _preprocessor->evaluate_array(eval_str);
    for (unsigned long i = _pattern.length() + 1; i < eval_str.length(); ++i) {
        if (temp[i] == _pattern.length())
            res.push_back(i);
    }
    delete[] temp;
    return res;
}

//unsigned long *SubstringFromBlock::evaluate_array(std::string &input) {
//    unsigned long l = 0;
//    unsigned long r = 0;////ddd///d/d/d/d/d/d//
//    auto *blocks = new unsigned long[input.length()];
//    blocks[0] = 0;
//    for (unsigned long i = 1; i < input.length(); i++) {
//        blocks[i] = 0;
//        if (i >= r) {
//            blocks[i] = cmp(input, 0, i);
//            l = i;
//            //r = i + blocks[i] - 1;
//            r = l + blocks[i];
//        } else {
//            unsigned long k = i - l;
//            if (blocks[k] < r - i) {
//                blocks[i] = blocks[k];
//            } else {
////                blocks[i] = r - i + 1;
////                blocks[i] += cmp(input, r - i + 1, r + 1);
//                blocks[i] = r-i+cmp(input,r-i,r);
//                l = i;
//                //r = i + blocks[i] - 1;
//                r = l+blocks[i];
//            }
//        }
//    }
//    return blocks;
//}
//
//unsigned long SubstringFromBlock::cmp(const std::string &str, unsigned long var1, unsigned long var2) {
//    unsigned long n = str.length();
//    unsigned long t,j;
//    if (var1 > n || var2 > n) {
//        return 0;
//    } else {
//        if (n - var1 < n - var2) {
//            t =n-var1;
//        } else{
//            t = n - var2;
//        }
//        j=0;
//        while(j<=t && str[var1+j] == str[var2+j]){
//            j++;
//        }
//        return j;
//    }
//}

SubstringFromBlock::~SubstringFromBlock() = default;

SubstringFromBlock::SubstringFromBlock(const std::string &source_text, const std::string &pattern,
                                       IPreprocessor *preprocessor) : ISubstring(source_text, pattern, preprocessor) {}

std::list<unsigned long> SubstringFromBlock::modified_positions() {
    return std::list<unsigned long>();
}
