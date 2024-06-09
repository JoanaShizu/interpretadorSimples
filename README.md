<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <h1>Interpretador Simples</h1>
    <p>Este projeto implementa um interpretador simples de expressões matemáticas em C. O interpretador é capaz de analisar e avaliar expressões matemáticas básicas, como adição, subtração, multiplicação e divisão.</p>

  <h2>Estrutura do Projeto</h2>
    <p>O projeto é composto pelos seguintes arquivos:</p>
    <ul>
        <li><code>main.c</code>: Ponto de entrada do programa.</li>
        <li><code>lexer.c</code> e <code>lexer.h</code>: Implementação do analisador léxico (lexer).</li>
        <li><code>parser.c</code> e <code>parser.h</code>: Implementação do analisador sintático (parser).</li>
        <li><code>interpreter.c</code> e <code>interpreter.h</code>: Implementação do interpretador.</li>
    </ul>

  <h2>Pré-requisitos</h2>
    <ul>
        <li>GCC (compilador de C)</li>
        <li>Visual Studio Code (ou outro editor de texto de sua preferência)</li>
        <li>Extensão C/C++ da Microsoft (para Visual Studio Code)</li>
    </ul>

  <h2>Como Compilar e Executar</h2>

  <h3>Compilação Manual</h3>
    <ol>
        <li>Abra o terminal e navegue até o diretório do projeto:
            <pre><code>cd caminho/para/o/diretorio/do/projeto</code></pre>
        </li>
        <li>Compile o projeto usando o GCC:
            <pre><code>gcc -g main.c lexer.c parser.c interpreter.c -o main.exe</code></pre>
        </li>
        <li>Execute o programa:
            <pre><code>./main.exe</code></pre>
        </li>
    </ol>

  <h3>Compilação e Execução no Visual Studio Code</h3>
    <ol>
        <li>Certifique-se de que você possui a extensão C/C++ da Microsoft instalada.</li>
        <li>Abra o projeto no Visual Studio Code.</li>
        <li>Utilize a tarefa de build para compilar o projeto:
            <ul>
                <li>Pressione <code>Ctrl+Shift+B</code> para compilar.</li>
            </ul>
        </li>
        <li>Execute o projeto com o depurador:
            <ul>
                <li>Pressione <code>F5</code> para iniciar a depuração.</li>
            </ul>
        </li>
    </ol>

  <h2>Como Funciona</h2>
    <ol>
        <li><strong>Lexer</strong>: Converte o texto de entrada em uma sequência de tokens.</li>
        <li><strong>Parser</strong>: Constrói uma árvore de análise sintática (AST) a partir dos tokens.</li>
        <li><strong>Interpreter</strong>: Avalia a AST para executar as operações.</li>
    </ol>

  <h2>Exemplo de Uso</h2>
    <p>O arquivo <code>main.c</code> contém um exemplo simples de como usar o interpretador:</p>
    <pre><code>
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
  
  free(lexer);
  free(parser);
  free(interpreter);

  return 0;
}
    </code></pre>

</body>
</html>
