//
// Created by typhoon on 16.03.18.
//

#include "BlockPreprocessor.h"

unsigned long *BlockPreprocessor::evaluate_array(std::string &str) {
    unsigned long l = 0;
    unsigned long r = 0;
    auto *blocks = new unsigned long[str.length()];
    blocks[0] = 0;
    for (unsigned long i = 1; i < str.length(); i++) {
        blocks[i] = 0;
        if (i >= r) {
            blocks[i] = cmp(str, 0, i);
            l = i;
            //r = i + blocks[i] - 1;
            r = l + blocks[i];
        } else {
            unsigned long k = i - l;
            if (blocks[k] < r - i) {
                blocks[i] = blocks[k];
            } else {
//                blocks[i] = r - i + 1;
//                blocks[i] += cmp(input, r - i + 1, r + 1);
                blocks[i] = r-i+cmp(str,r-i,r);
                l = i;
                //r = i + blocks[i] - 1;
                r = l+blocks[i];
            }
        }
    }
    return blocks;
}

unsigned long BlockPreprocessor::cmp(const std::string &str, unsigned long var1, unsigned long var2) {
    unsigned long n = str.length();
    unsigned long t,j;
    if (var1 > n || var2 > n) {
        return 0;
    } else {
        if (n - var1 < n - var2) {
            t =n-var1;
        } else{
            t = n - var2;
        }
        j=0;
        while(j<=t && str[var1+j] == str[var2+j]){
            j++;
        }
        return j;
    }
}

BlockPreprocessor::BlockPreprocessor() {}
