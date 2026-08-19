#pragma once
#include <string>
#include <vector>
#include "token.hpp"

class Lexer {
public:
    Lexer(std::string source);
    std::vector<Token> tokenize();
private:
    std::string src_;
    size_t pos_ = 0;
    int line_ = 1;
};