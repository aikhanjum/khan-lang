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
            int start = pos_;
            while(pos_ < src_.size() && std::isdigit(src_[pos_])) {
                pos_++;
            };
            tokens.push_back(Token{TokenType::Number, src_.substr(start, pos_-start), line_});
        }


    }

    tokens.push_back(Token{TokenType::End, "", line_});
    return tokens;
}