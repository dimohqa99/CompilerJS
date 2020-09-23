#ifndef COMPILERJS_STRINGEXPRAST_H
#define COMPILERJS_STRINGEXPRAST_H

#include "ExprAST.h"

class StringExprAST: public ExprAST {
private:
    string Value;

public:
    StringExprAST(string value): Value(value) {}

    void print(int level) override {
        printLevel(level);
        cout << "String: " << Value << endl;
    }

    IdentifierType getType(unique_ptr<bool> &fatalError) override {
        return STR;
    }

    int getLength(unique_ptr<bool> &fatalError) override {
        return Value.length();
    }

    void codegenString(ofstream &out, string name) override {
        string buffer = Value;
        int i = 0;
        while (i != buffer.length()) {
            if (i == buffer.length()) {
                out << "movl $" << i << ", %ebx" << endl;
                out << "movb $" << 0 << ", " << name <<  "(, %ebx, 1)" << endl;
                continue;
            }
            out << "movl $" << i << ", %ebx" << endl;
            out << "movb $" << +buffer[i] << ", " << name << "(, %ebx, 1)" << endl;
            i++;
        }
    }

    string getNameClass() override {
        return "String";
    }
};


#endif
