//
// Created by typhoon on 28.02.18.
//
#include <string>
#include <list>
#include "../preprocessing/IPreprocessor.h"

#ifndef LAB_1_SUBSTRING_H
#define LAB_1_SUBSTRING_H


class ISubstring {
protected:
    std::string _source_text, _pattern;
    const char ESCAPE_CHARACTER = '~';
    unsigned long _occurences = 0;
    IPreprocessor *_preprocessor;
    //virtual unsigned long* evaluate_array(std::string& input) =0;
    virtual std::list<unsigned long> positions() =0;
    virtual std::list<unsigned long> modified_positions() =0;

public:
    std::list<unsigned long> real_positions(bool modified = false);

    const std::string &get_source_text() const;

    const std::string &get_pattern() const;

    unsigned long get_occurences();

    ISubstring(const std::string &source_text, const std::string &pattern);
    ISubstring(const std::string &source_text, const std::string &pattern, IPreprocessor *preprocessor);
};


#endif //LAB_1_SUBSTRING_H
