#include <iostream>
#include <memory>
#include "Lexer/Lexer.h"
#include "Parser/Parser.h"
#include "Table/Table.h"

int main() {
    string filepath = "/home/nitro/university/CompilerJS/js/min.js";
    ifstream file = ifstream(filepath);
    Lexer lexer(file);

    /*while (true) {
        Token token = lexer.getNextToken();
        token.print();

        if (token.type == E0F) {
            break;
        }
    }*/
    Parser parser(lexer);

    unique_ptr<bool> fatalError(new bool(false));

    unique_ptr<ExprAST> main = parser.parse(fatalError);
    cout << "TREE: " << endl;
    main.get()->print(0);

    cout << "TABLE: " << endl;

    auto table = main.get()->createTable(fatalError);
    table.print();

    if (*fatalError) {
        cout << endl << "Fix error plz" << endl;
        return 0;
    }

    main.get()->codegenInit(table);

    return 0;
}
