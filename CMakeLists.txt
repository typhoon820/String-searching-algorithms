cmake_minimum_required(VERSION 3.9)
project(lab_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab_1 main.cpp Parser.h Parser.cpp substring/ISubstring.cpp substring/ISubstring.h substring/SubstringFromBorder.cpp substring/SubstringFromBorder.h substring/SubstringFromBlock.cpp substring/SubstringFromBlock.h tests/Test.cpp tests/Test.h preprocessing/IPreprocessor.cpp preprocessing/IPreprocessor.h preprocessing/BorderPreprocessor.cpp preprocessing/BorderPreprocessor.h preprocessing/BlockPreprocessor.cpp preprocessing/BlockPreprocessor.h substring/SubstringKMP.cpp substring/SubstringKMP.h)