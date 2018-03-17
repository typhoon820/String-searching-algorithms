#include <iostream>
#include <sstream>
#include <algorithm>
#include <chrono>
#include "Parser.h"
#include "string"
#include "fstream"
#include "substring/SubstringFromBorder.h"
#include "substring/SubstringFromBlock.h"
#include "tests/Test.h"
#include "preprocessing/BlockPreprocessor.h"
#include "substring/SubstringKMP.h"
#include "preprocessing/BorderPreprocessor.h"


int main() {

//    std::ifstream ifs("../examples/got.txt");
//    std::string content((std::istreambuf_iterator<char>(ifs)),
//                        (std::istreambuf_iterator<char>()));
//    std::string pattern = "c";
//    std::string content = "aaaaa";
////    //ISubstring *eval = new SubstringFromBlock(content, pattern, new BlockPreprocessor());
//    ISubstring *kmp = new SubstringKMP(content, pattern, new BorderPreprocessor());
//    Parser parser = Parser(kmp);
//    std::list<unsigned long> substr =  parser.find_substr();
//
//    Parser parser1 = Parser(kmp);
//    int size = substr.size();
//    int size1 = parser1.find_substr(true).size();
////
////
////    //unsigned long* (*sub_func)() = parser.substr_pos;
//   std::list<unsigned long> s_i = parser.find_substr(true);
////
////    //Test::run(content, pattern, 10);
//    std::cout<< "Occurences " << kmp->get_occurences()<< std::endl;
//    std::cout<<content.length()<<std::endl;
//    //Test::mad_test();
//    int i=0;
////    for (auto it= s_i.begin(); it!=s_i.end(); ++it, ++i) {
////        std::cout << i << ":   " + parser.get_substr_context(*it, 10) << std::endl
////                  << "========================================================================" << std::endl;
////    }




    Test::benchamrk();


    return 0;
}