#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

Lexer* init_lexer(char *text) {
    Lexer *lexer = (Lexer *)malloc(sizeof(Lexer));
    lexer->text = text;
    lexer->pos = 0;
    lexer->current_char = text[lexer->pos];
    return lexer;
}

void advance(Lexer *lexer) {
    lexer->pos++;
    if (lexer->pos > strlen(lexer->text) - 1) {
        lexer->current_char = '\0';
    } else {
        lexer->current_char = lexer->text[lexer->pos];
    }
}

void skip_whitespace(Lexer *lexer) {
    while (lexer->current_char != '\0' && isspace(lexer->current_char)) {
        advance(lexer);
    }
}

int integer(Lexer *lexer) {
    int result = 0;
    while (lexer->current_char != '\0' && isdigit(lexer->current_char)) {
        result = result * 10 + lexer->current_char - '0';
        advance(lexer);
    }
    return result;
}

Token* get_next_token(Lexer *lexer) {
    while (lexer->current_char != '\0') {
        if (isspace(lexer->current_char)) {
            skip_whitespace(lexer);
            continue;
        }
        if (isdigit(lexer->current_char)) {
            Token *token = (Token *)malloc(sizeof(Token));
            token->type = TOKEN_INTEGER;
            token->value = integer(lexer);
            return token;
        }
        if (lexer->current_char == '+') {
            advance(lexer);
            Token *token = (Token *)malloc(sizeof(Token));
            token->type = TOKEN_PLUS;
            token->value = 0;
            return token;
        }
        if (lexer->current_char == '-') {
            advance(lexer);
            Token *token = (Token *)malloc(sizeof(Token));
            token->type = TOKEN_MINUS;
            token->value = 0;
            return token;
        }
        if (lexer->current_char == '*') {
            advance(lexer);
            Token *token = (Token *)malloc(sizeof(Token));
            token->type = TOKEN_MUL;
            token->value = 0;
            return token;
        }
        if (lexer->current_char == '/') {
            advance(lexer);
            Token *token = (Token *)malloc(sizeof(Token));
            token->type = TOKEN_DIV;
            token->value = 0;
            return token;
        }
        if (lexer->current_char == '(') {
            advance(lexer);
            Token *token = (Token *)malloc(sizeof(Token));
            token->type = TOKEN_LPAREN;
            token->value = 0;
            return token;
        }
        if (lexer->current_char == ')') {
            advance(lexer);
            Token *token = (Token *)malloc(sizeof(Token));
            token->type = TOKEN_RPAREN;
            token->value = 0;
            return token;
        }
        Token *token = (Token *)malloc(sizeof(Token));
        token->type = TOKEN_UNKNOWN;
        token->value = 0;
        return token;
    }
    Token *token = (Token *)malloc(sizeof(Token));
    token->type = TOKEN_EOF;
    token->value = 0;
    return token;
}
