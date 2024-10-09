%{
#include <stdio.h>
#include <stdlib.h>

FILE *output_file;
%}

%%
[1-9][0-9]*        {fprintf(output_file, "Número: %s\n", yytext);}              // Números naturais
[a-z]+             {fprintf(output_file, "Identificador: %s\n", yytext);}         // Identificadores (letras minúsculas)
=                  {fprintf(output_file, "Comando de atribuição: %s\n", yytext);}       // Comando de atribuição
\+                 {fprintf(output_file, "Operador soma: %s\n", yytext);}             // Operador de soma
[ \t\n]+           { /* Ignorar espaços em branco e de quebras  */ }
.                  {fprintf(output_file, "Erro: %s\n", yytext);}                  // Qualquer outro caractere não reconhecido
%%

int main(int argc, char **argv){
    if (argc != 2){
        fprintf(stderr, "Uso: %s <arquivo_entrada>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL){
        perror("Não foi possível abrir o arquivo de entrada!");
        exit(EXIT_FAILURE);
    }

    output_file = fopen("tokens.txt", "w");
    if(output_file == NULL){
        perror("Não foi possível criar o arquivo de saída!");
        fclose(input_file);
        exit(EXIT_FAILURE);
    }

    yyin = input_file;  
    yylex();  

    fclose(input_file);
    fclose(output_file);

    return 0;
}
