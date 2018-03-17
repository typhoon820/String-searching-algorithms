//
// Created by typhoon on 01.03.18.
//

#include <chrono>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Test.h"
#include "../substring/SubstringFromBlock.h"
#include "../substring/SubstringFromBorder.h"
#include "../substring/SubstringKMP.h"
#include "../preprocessing/BorderPreprocessor.h"

void Test::run(const std::string &source_text, const std::string &pattern, int num_iterations) {
    Parser parser = Parser(source_text, pattern);
    ISubstring *block_evaluator = new SubstringFromBlock(source_text, pattern);
    ISubstring *border_evaluator = new SubstringFromBorder(source_text, pattern);
    double elapsed_block, elapsed_border;
    elapsed_block = elapsed_border = 0.;
    for (int i = 0; i < num_iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        //parser.find_substr(block_evaluator);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time = finish - start;
        elapsed_block += time.count();

        start = std::chrono::high_resolution_clock::now();
        //parser.find_substr(border_evaluator);
        finish = std::chrono::high_resolution_clock::now();

        time = finish - start;
        elapsed_border += time.count();
    }
    //delete[] border_evaluator;
    //delete[] block_evaluator;

    std::cout << "=============================================================\n"
              << "============================TESTS============================\n"
              << "=============================================================\n"
              << "Z-blocks: ~" << elapsed_block / num_iterations << "sec\n"
              << "Borders : ~" << elapsed_border / num_iterations << "sec\n"
              << block_evaluator->get_occurences() << "bl\n"
              << border_evaluator->get_occurences() << "bo"
              << std::endl;

}

void Test::mad_test() {
    std::string *tests = new std::string[4];
    std::string *patterns = new std::string[4];
    for (int i = 0; i < 1000000; i++) {
        tests[0] += (i / 10000 == 0) ? "b" : "a";
    }
    for (int i = 0; i < 1000000; i++) {
        tests[1] += "a";
    }
    for (int i = 0; i < 1000000; i++) {
        tests[2] += "aabc";
    }
    std::ifstream ifs("../dna1kk.txt");
    std::string test((std::istreambuf_iterator<char>(ifs)),
                     (std::istreambuf_iterator<char>()));
//    std::replace(test.begin(), test.end(), char(10), ' ');
//    std::replace(test.begin(), test.end(), char(13), ' ');
    //test.erase(std::remove(test.begin(), test.end(), '\n'), test.end());
    //test.erase(std::remove(test.begin(), test.end(), char(13)), test.end());

    tests[3] = test;


    for (int i = 0; i < 10000; i++) {
        patterns[0].append("a");
    }
    for (int i = 0; i < 100000; i++) {
        patterns[1].append("a");
    }
    patterns[1] = "aaa";
    patterns[2] = "bcaa";
    patterns[3] = "ag";
    double elapsed_block, elapsed_border;
    for (int i = 0; i < 4; i++) {
        elapsed_block = elapsed_border = 0;
        ISubstring *block = new SubstringFromBlock(tests[i], patterns[i]);
        ISubstring *border = new SubstringFromBorder(tests[i], patterns[i]);
        Parser parser = Parser(tests[i], patterns[i]);
        auto start = std::chrono::high_resolution_clock::now();
        //parser.find_substr(block);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time = finish - start;
        elapsed_block += time.count();

        start = std::chrono::high_resolution_clock::now();
        //parser.find_substr(border);
        finish = std::chrono::high_resolution_clock::now();

        time = finish - start;
        elapsed_border += time.count();

        //delete[] border_evaluator;
        //delete[] block_evaluator;

        std::cout << "=============================================================\n"
                  << "===============TEST" << i << "    Length: =" << tests[i].length() << "================\n"
                  << "=============Pattern: " << patterns[i] << "====================================\n"
                  << "Z-blocks: ~" << elapsed_block << " sec, " << block->get_occurences() << " _occurences\n"
                  << "Borders : ~" << elapsed_border << " sec, " << border->get_occurences() << " _occurences\n"
                  << std::endl;

    }

}

void Test::benchamrk() {
    std::string fileNames[] = {"../examples/100kk(a).txt",
                               "../examples/10kk(ab).txt",
                               //"../examples/10kkk(a).txt",
                               "../examples/10kk(a).txt",
                               "../examples/dna1kk.txt"};
    std::string *texts = new std::string[4];
    std::string *patterns = new std::string[4];
    int indexes[4] = {1000000,100000, 1000000, 1};
    std::string img[4] ={"a", "ba","c","cac"};
    for (int i = 0; i < 4; i++) {
        std::ifstream ifs(fileNames[i]);
        std::string text((std::istreambuf_iterator<char>(ifs)),
                 (std::istreambuf_iterator<char>()));
        texts[i] = text;
    }

    for(int i =0; i<3; i++){
        for (int j =0; j< indexes[i]; j++){
            patterns[i] += img[i];
        }
    }
    patterns[3] = img[3];
    double elapsed_classic, elapsed_online;
    unsigned long occurences_classic, occurences_online;
    for (int i =0; i< 4; i++){
        elapsed_classic = elapsed_online = 0.;
        occurences_classic = occurences_online = 0;
        ISubstring* kmp = new SubstringKMP(texts[i], patterns[i], new BorderPreprocessor());
        Parser parser = Parser(kmp);
        Parser parser_online = Parser(kmp);
        auto start = std::chrono::high_resolution_clock::now();
        parser.find_substr();
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time = finish - start;
        elapsed_classic += time.count();
        occurences_classic = kmp->get_occurences();

        start = std::chrono::high_resolution_clock::now();
        parser_online.find_substr(true);
        finish = std::chrono::high_resolution_clock::now();
        time = finish - start;
        elapsed_online += time.count();
        occurences_online = kmp->get_occurences();
        std::cout<<"filename: "<<fileNames[i]<<std::endl
                 <<"pattern: "<<indexes[i]<<" - "<<img[i]<< std::endl
                 <<"occurences KMP: "<<occurences_classic<<std::endl
                 <<"occurences KMP-online: "<<occurences_online<<std::endl
                 <<"classic KMP-algorithm time: "<<elapsed_classic<<" ms"<< std::endl
                 <<"on-line KMP-algorithm time: "<< elapsed_online<<" ms"<<std::endl
                 <<"====================================================================\n\n";
    }


}
