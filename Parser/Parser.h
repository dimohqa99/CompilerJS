#ifndef COMPILATOR_PARSER_H
#define COMPILATOR_PARSER_H

#include <iostream>
#include <memory>
#include <map>
#include "stdlib.h"
#include "../Lexer/Token.h"
#include "../Lexer/Lexer.h"
#include "../AST/ExprAST.h"
#include "../AST/NumberExprAST.h"
#include "../AST/BinaryExprAST.h"

using namespace std;

static std::map<char, int> BinopPrecedence;

class Parser {
private:
    Lexer lexer;
    static std::map<char, int> BinopPrecedence;
public:
    Parser(Lexer lexer): lexer(lexer) {}
    void parse(unique_ptr<bool> &fatalError);
    unique_ptr<ExprAST> parseVariable(unique_ptr<bool> &fatalError);
    unique_ptr<ExprAST> ParsePrimary(Token token, unique_ptr<bool> &fatalError);
    unique_ptr<ExprAST> parseExpression(Token token, unique_ptr<bool> &fatalError);
    unique_ptr<ExprAST> parseNumberExpression(Token token, unique_ptr<bool> &fatalError);
    unique_ptr<ExprAST> parseBinOpRHS(int exprPrec, unique_ptr<ExprAST> LHS,unique_ptr<bool> &fatalError);
    void parseUnary(Token token, bool ****fatalError);
};

#endif