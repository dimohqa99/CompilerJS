#ifndef COMPILATOR_LEXER_H
#define COMPILATOR_LEXER_H

#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include "Token.h"
#include "../EnumSwitch/TokenTypeSwitch.h"

using namespace std;

const string reserved_words[] = {
        "this",         "new",      "function",  "var",
        "for",          "if",       "else",     "true",
        "false",        "return",   "undefined","null",
        "instanceof",   "in",       "do",       "default",
        "void",         "while",    "break",    "case",
        "typeof",       "continue", "Infinity", "NaN",
        "delete",       "switch",   "try",      "catch",
        "throw",        "finally",  "with",     "debugger",
        "const",        "let"
};

const string oper[] = {
        "{",    "}",    ".",    ">=",   "+",
        "<<",   "!",    "=",    ">>=",  ";", "/",
        "==",   "-",    ">>",   "~",    "+=", "/=",
        ">>>=", "(",    ",",    "!=",   "*",
        ">>>",  "&&",   "-=",   "&=",   ")",
        "<",    "===",  "%",    "&",    "||",
        "*=",   "|=",   "[",    ">",    "!==",
        "++",   "|",    "?",    "%=",   "^=", "\\",
        "--",   "^",    ":",    "<<=",  "]",    "<="
};

class Lexer {
private:
    int row;
    int col;
    ifstream file;
public:
    Lexer(string filepath) {
        row = 1;
        col = 1;
        file = ifstream(filepath);
    }
    virtual Token getNextToken();
    TokenType identificator(ifstream &file, string &buffer);
    TokenType op(ifstream &file, string &buffer);
    TokenType number(ifstream &file, string &buffer);
    TokenType realNumber(ifstream &file, string &buffer);
    TokenType stroka(ifstream &file, string &buffer);
    bool singleLineComment(ifstream &file);
    bool multiLineComment(ifstream &file);
};


#endif //COMPILATOR_LEXER_H
