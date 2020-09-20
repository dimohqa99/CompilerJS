#ifndef COMPILERJS_IFAST_H
#define COMPILERJS_IFAST_H

#include <memory>
#include <iostream>
#include "ExprAST.h"
#include "BodyAST.h"

using namespace std;

class IfAST: public ExprAST {
private:
    unique_ptr<ExprAST> Condition;
    unique_ptr<ExprAST> Body;

public:
    IfAST(unique_ptr<ExprAST> condition, unique_ptr<ExprAST> body)
        : Condition(move(condition)), Body(move(body)) {}

    void print(int level) override {
        printLevel(level);
        cout << "IF" << endl;

        if(Condition.get()) {
            printLevel(level + 1);
            cout << "Condition:" << endl;
            Condition.get()->print(level + 2);
        }

        if(Body.get()) {
            Body.get()->print(level + 1);
        }
    }

    void table(Table &table, int level, unique_ptr<bool> &fatalError) override {
        if (Body.get())
            Body.get()->table(table, level, fatalError);
    }

    void codegen(ofstream &out, Table table) override {
        Condition->codegen(out, table);
        Body->codegen(out, table);
        out << "next" << metks["next"] << ":" << endl;
        metks["next"]++;
    }
};


#endif
