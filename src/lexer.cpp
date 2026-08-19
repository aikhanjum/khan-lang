#include "lexer.hpp"
#include <cctype>

Lexer::Lexer(std::string source): src_(source) {}

std::vector<Token> Lexer::tokenize(){
    std::vector<Token> tokens;

    while(pos_ < src_.size()){
        char c = src_[pos_];

        if(c == ' ') {pos_++; continue;}
        else if(c == '\n') {pos_++; line_++; continue;}
        else if(std::isdigit(c)) {
            tokens.push_back(Token{TokenType::Number, std::string(1, c), line_});
            pos_++;
        }


    }

    tokens.push_back(Token{TokenType::End, "", line_});
    return tokens;
}