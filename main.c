#include "lexer.h"
#include "parser.h"
#include "interpreter.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    char text[] = "3 + 5 * (10 - 6)";

    Lexer *lexer = init_lexer(text);
    Parser *parser = init_parser(lexer);
    Interpreter *interpreter = init_interpreter(parser);

    int result = interpret(interpreter);
    printf("Resultado: %d\n", result);

    // Limpeza de memória
    free(lexer);
    free(parser);
    free(interpreter);

    return 0;
}
