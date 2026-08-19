#include <cassert>
#include <iostream>
#include "lexer.hpp"

int main(){
    Lexer lx("");
    std::vector<Token> tokens = lx.tokenize();
    
    assert(tokens.size() == 1);
    assert(tokens[0].type == TokenType::End);
    std::cout << "ok\n";
}



