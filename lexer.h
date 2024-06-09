#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_INTEGER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MUL,
    TOKEN_DIV,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_EOF,
    TOKEN_UNKNOWN
} TokenType;

typedef struct {
    TokenType type;
    int value;
} Token;

typedef struct {
    char *text;
    int pos;
    char current_char;
} Lexer;

Lexer* init_lexer(char *text);
void advance(Lexer *lexer);
void skip_whitespace(Lexer *lexer);
int integer(Lexer *lexer);
Token* get_next_token(Lexer *lexer);

#endif