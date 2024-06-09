#include "interpreter.h"
#include <stdio.h>
#include <stdlib.h>

Interpreter* init_interpreter(Parser *parser) {
    Interpreter *interpreter = (Interpreter *)malloc(sizeof(Interpreter));
    interpreter->parser = parser;
    return interpreter;
}

int visit(AST *node) {
    if (node->token->type == TOKEN_INTEGER) {
        return node->token->value;
    } else if (node->token->type == TOKEN_PLUS) {
        return visit(node->left) + visit(node->right);
    } else if (node->token->type == TOKEN_MINUS) {
        return visit(node->left) - visit(node->right);
    } else if (node->token->type == TOKEN_MUL) {
        return visit(node->left) * visit(node->right);
    } else if (node->token->type == TOKEN_DIV) {
        return visit(node->left) / visit(node->right);
    } else {
        fprintf(stderr, "Erro de interpretação: token inesperado\n");
        exit(EXIT_FAILURE);
    }
}

int interpret(Interpreter *interpreter) {
    AST *tree = parse(interpreter->parser);
    return visit(tree);
}
