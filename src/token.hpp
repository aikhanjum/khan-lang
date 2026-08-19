#pragma once
#include <string>
enum class TokenType {Number, Identifier, Let, Print,
Plus, Minus, Star, Slash, Equals,
LParen, RParen, Semicolon, End};
struct Token{
    TokenType type;
    std::string text;
    int line;
};
