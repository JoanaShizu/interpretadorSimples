#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "parser.h"

typedef struct {
    Parser *parser;
} Interpreter;

Interpreter* init_interpreter(Parser *parser);
int visit(AST *node);
int interpret(Interpreter *interpreter);

#endif
