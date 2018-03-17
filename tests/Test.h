//
// Created by typhoon on 01.03.18.
//

#ifndef LAB_1_TEST_H
#define LAB_1_TEST_H


#include "../Parser.h"

class Test {
public:
    static void
    run(const std::string &source_texts, const std::string &patterns, int num_iterations);
    static void mad_test();

    static void benchamrk();
};


#endif //LAB_1_TEST_H
