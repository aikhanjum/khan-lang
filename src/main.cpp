#include <cassert>
#include <iostream>
#include "lexer.hpp"

int main(){
    Lexer lx("7");
    std::vector<Token> tokens = lx.tokenize();
    
    assert(tokens.size() == 2);
    assert(tokens[1].type == TokenType::End);
    assert(tokens[0].type == TokenType::Number);
    std::cout << "ok\n";
}



