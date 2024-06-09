#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

AST* init_ast(Token *token) {
    AST *ast = (AST *)malloc(sizeof(AST));
    ast->token = token;
    ast->left = NULL;
    ast->right = NULL;
    return ast;
}

Parser* init_parser(Lexer *lexer) {
    Parser *parser = (Parser *)malloc(sizeof(Parser));
    parser->lexer = lexer;
    parser->current_token = get_next_token(lexer);
    return parser;
}

void eat(Parser *parser, TokenType type) {
    if (parser->current_token->type == type) {
        parser->current_token = get_next_token(parser->lexer);
    } else {
        fprintf(stderr, "Erro de sintaxe: esperado token %d\n", type);
        exit(EXIT_FAILURE);
    }
}

AST* factor(Parser *parser) {
    Token *token = parser->current_token;
    if (token->type == TOKEN_INTEGER) {
        eat(parser, TOKEN_INTEGER);
        return init_ast(token);
    } else if (token->type == TOKEN_LPAREN) {
        eat(parser, TOKEN_LPAREN);
        AST *node = expr(parser);
        eat(parser, TOKEN_RPAREN);
        return node;
    } else {
        fprintf(stderr, "Erro de sintaxe: token inesperado\n");
        exit(EXIT_FAILURE);
    }
}

AST* term(Parser *parser) {
    AST *node = factor(parser);
    while (parser->current_token->type == TOKEN_MUL || parser->current_token->type == TOKEN_DIV) {
        Token *token = parser->current_token;
        if (token->type == TOKEN_MUL) {
            eat(parser, TOKEN_MUL);
        } else if (token->type == TOKEN_DIV) {
            eat(parser, TOKEN_DIV);
        }
        AST *new_node = init_ast(token);
        new_node->left = node;
        new_node->right = factor(parser);
        node = new_node;
    }
    return node;
}

AST* expr(Parser *parser) {
    AST *node = term(parser);
    while (parser->current_token->type == TOKEN_PLUS || parser->current_token->type == TOKEN_MINUS) {
        Token *token = parser->current_token;
        if (token->type == TOKEN_PLUS) {
            eat(parser, TOKEN_PLUS);
        } else if (token->type == TOKEN_MINUS) {
            eat(parser, TOKEN_MINUS);
        }
        AST *new_node = init_ast(token);
        new_node->left = node;
        new_node->right = term(parser);
        node = new_node;
    }
    return node;
}

AST* parse(Parser *parser) {
    return expr(parser);
}
