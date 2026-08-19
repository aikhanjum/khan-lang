#include "lexer.hpp"

Lexer::Lexer(std::string source): src_(source) {}

std::vector<Token> Lexer::tokenize(){
    std::vector<Token> tokens;
    tokens.push_back(Token{TokenType::End, "", line_});
    return tokens;
}