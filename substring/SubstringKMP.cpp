//
// Created by typhoon on 16.03.18.
//

#include "SubstringKMP.h"

SubstringKMP::SubstringKMP(const std::string &source_text, const std::string &pattern, IPreprocessor *preprocessor)
        : ISubstring(source_text, pattern, preprocessor) {
    matr = new unsigned long *[pattern.length()];
    for (unsigned long i = 0; i < pattern.length(); i++) {
        matr[i] = new unsigned long[ALPHABET_POWER];
    }
    for (unsigned long i = 0; i < pattern.length(); i++) {
        for (int j = 0; j < ALPHABET_POWER; j++) {
            matr[i][j] = 0;
        }
    }
}

std::list<unsigned long> SubstringKMP::positions() {
    std::list<unsigned long> res;
    evaluate_borders_modified();
    unsigned long pattern_length = _pattern.length();
    unsigned long text_length = _source_text.length();
    unsigned long k = 0;
    for (int i = 0; i < text_length; i++) {
        while (k && _pattern[k] != _source_text[i]) {
            k = borders_modidied[k - 1];
        }
        if (_pattern[k] == _source_text[i]) {
            k++;
        }
        if (k == pattern_length) {
            res.push_back(i - k);
            k = borders_modidied[k - 1];
        }
    }
    return res;
}

void SubstringKMP::evaluate_matrix(unsigned long *borders_modified) {
    for (int i = 0; i < _pattern.length(); i++) {
        auto k = (int) _pattern[borders_modified[i]];
        matr[i][k] = borders_modified[i];
    }
}

void SubstringKMP::evaluate_borders_modified() {
    borders_modidied = _preprocessor->evaluate_modified_array(_pattern);
}

std::list<unsigned long> SubstringKMP::modified_positions() {
    std::list<unsigned long> res;
    evaluate_borders_modified();
    evaluate_matrix(borders_modidied);
    unsigned long pattern_length = _pattern.length();
    unsigned long text_length = _source_text.length();
    unsigned long k = 0;
    for (int i = 0; i < text_length; i++) {
        if (_pattern[k] != _source_text[i] && k) {
            k = matr[k - 1][(int) _source_text[i]];
        }
        if (_pattern[k] == _source_text[i]) {
            k++;
        }
        if (k == pattern_length) {
            res.push_back(i - k);
//            k = borders_modidied[k - 1];
            k = matr[k-1][(int)_source_text[i+1]];
        }
    }
    return res;
}
