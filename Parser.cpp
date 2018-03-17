//
// Created by typhoon on 11.02.18.
//
#include <iostream>
#include "string"
#include "Parser.h"
#include <iterator>
#include "algorithm"



std::list<unsigned long> Parser::find_substr(bool modified) {
    return _evaluator->real_positions(modified);
}

std::string Parser::get_substr_context(unsigned long index, unsigned long offset) {
    std::string res = "...";
    unsigned long start = 0;
    if (index >= offset) {
        start = index - offset;
    }
    unsigned long end = index+pattern.length()+offset;
    for(;end>source_text.length(); end--);
    std::replace(source_text.begin(), source_text.end(), char(10), ' ');
    std::replace(source_text.begin(), source_text.end(), char(13), ' ');
    res+=source_text.substr(start, end-start);
    res+="...";
    return res;
}

Parser::Parser(const std::string &source_text, const std::string &pattern) : source_text(source_text),
                                                                             pattern(pattern) {}

const std::string &Parser::get_source_text() const {
    return source_text;
}

const std::string &Parser::get_pattern() const {
    return pattern;
}

Parser::Parser(ISubstring *_evaluator) : _evaluator(_evaluator) {
    source_text = _evaluator->get_source_text();
    pattern = _evaluator->get_pattern();
}


Parser::Parser() = default;

Parser::~Parser() = default;
