#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef struct AST {
    Token *token;
    struct AST *left;
    struct AST *right;
} AST;

AST* init_ast(Token *token);

typedef struct {
    Lexer *lexer;
    Token *current_token;
} Parser;

Parser* init_parser(Lexer *lexer);
void eat(Parser *parser, TokenType type);
AST* factor(Parser *parser);
AST* term(Parser *parser);
AST* expr(Parser *parser);
AST* parse(Parser *parser);

#endif
