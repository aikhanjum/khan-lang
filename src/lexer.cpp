#include "lexer.hpp"
#include <cctype>
#include <iostream>
#include <cstdlib>

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
            }
            tokens.push_back(Token{TokenType::Number, src_.substr(start, pos_-start), line_});
        }
        else {
        switch (c) {
        case '+': tokens.push_back(Token{TokenType::Plus,      "+", line_}); pos_++; break;
        case '-': tokens.push_back(Token{TokenType::Minus,     "-", line_}); pos_++; break;
        case '*': tokens.push_back(Token{TokenType::Star,      "*", line_}); pos_++; break;
        case '/': tokens.push_back(Token{TokenType::Slash,     "/", line_}); pos_++; break;
        case '=': tokens.push_back(Token{TokenType::Equals,    "=", line_}); pos_++; break;
        case '(': tokens.push_back(Token{TokenType::LParen,    "(", line_}); pos_++; break;
        case ')': tokens.push_back(Token{TokenType::RParen,    ")", line_}); pos_++; break;
        case ';': tokens.push_back(Token{TokenType::Semicolon, ";", line_}); pos_++; break;
        default:
            std::cerr << "khan: unexpected character '" << c
                      << "' on line " << line_ << "\n";
            std::exit(1);
    }
}


    }

    tokens.push_back(Token{TokenType::End, "", line_});
    return tokens;
}