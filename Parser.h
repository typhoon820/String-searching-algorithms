//
// Created by typhoon on 11.02.18.
//
#include "string"
#include "substring/ISubstring.h"

#ifndef LAB_1_PARSER_H
#define LAB_1_PARSER_H

class Parser {
private:
    std::string source_text, pattern;
    ISubstring * _evaluator;
public:
    Parser();
    ~Parser();

    Parser(ISubstring *_evaluator);

    std::list<unsigned long> find_substr(bool modified = false);
    std::string get_substr_context(unsigned long index, unsigned long offset);
    Parser(const std::string &source_text, const std::string &pattern);

    const std::string &get_source_text() const;

    const std::string &get_pattern() const;

};


#endif //LAB_1_PARSER_H
