#ifndef COMPILERJS_WHILEAST_H
#define COMPILERJS_WHILEAST_H

#include "ExprAST.h"

class WhileAST: public ExprAST {
private:
    unique_ptr<ExprAST> Condition;
    unique_ptr<ExprAST> Body;

public:
    WhileAST(unique_ptr<ExprAST> condition, unique_ptr<ExprAST> body)
        : Condition(move(condition)), Body(move(body))  {}
    void print(int level) override {
        printLevel(level);
        cout << "While" << endl;

        if (Condition.get())
            printLevel(level + 1);
            cout << "Condition:" << endl;
            Condition.get()->print(level + 2);
        if (Body.get())
            Body.get()->print(level + 1);
    }
};


#endif
