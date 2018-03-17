//
// Created by typhoon on 28.02.18.
//

#include "ISubstring.h"

ISubstring::ISubstring(const std::string &source_text, const std::string &pattern) : _source_text(source_text),
                                                                                     _pattern(pattern) {}

std::list<unsigned long> ISubstring::real_positions(bool modified) {
    std::list<unsigned long> res;
    if(modified) {
        res = modified_positions();
    }
    else {
        res = positions();
    }
    _occurences = res.size();
    return res;
}

unsigned long ISubstring::get_occurences() {
    return _occurences;
}

ISubstring::ISubstring(const std::string &source_text, const std::string &pattern, IPreprocessor *preprocessor):_source_text(source_text),
                                                                                                                _pattern(pattern),
                                                                                                                _preprocessor(preprocessor)
{}

const std::string &ISubstring::get_source_text() const {
    return _source_text;
}

const std::string &ISubstring::get_pattern() const {
    return _pattern;
}
