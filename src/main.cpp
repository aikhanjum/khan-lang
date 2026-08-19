#include <cassert>
#include <iostream>
#include "lexer.hpp"

int main() {
    {   // empty input -> just End
        Lexer lx("");
        auto t = lx.tokenize();
        assert(t.size() == 1);
        assert(t[0].type == TokenType::End);
    }
    {   // single digit
        Lexer lx("7");
        auto t = lx.tokenize();
        assert(t.size() == 2);
        assert(t[0].type == TokenType::Number);
        assert(t[0].text == "7");
    }
    {   // multi-digit batching
        Lexer lx("42");
        auto t = lx.tokenize();
        assert(t.size() == 2);
        assert(t[0].type == TokenType::Number);
        assert(t[0].text == "42");
    }
    {   // two numbers, whitespace between
        Lexer lx("1 2");
        auto t = lx.tokenize();
        assert(t.size() == 3);
        assert(t[0].text == "1");
        assert(t[1].text == "2");
        assert(t[2].type == TokenType::End);
    }
    {   // two numbers, whitespace between
        Lexer lx("12+34");
        auto t = lx.tokenize();
        assert(t.size() == 4);
        assert(t[0].text == "12");
        assert(t[1].text == "+");
        assert(t[2].text == "34");
        assert(t[3].type == TokenType::End);
    }
    std::cout << "all 5 ok\n";
}



