%{
#include <stdio.h>
#include <stdlib.h>

FILE *output_file;
%}

%%
[1-9][0-9]*  {fprintf(output_file, "Número\n");}
[ \t\n]+     { /* Ignorar espaços em branco e quebr*/}
.            {fprintf(output_file, "Erro\n");}
%%

int main(int argc, char **argv){
    if (argc != 2){
        fprintf(stderr, "Uso: %s <arquivo_entrada>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL){
        perror("Não foi pessível abrir o arquivo de entrada!!");
        exit(EXIT_FAILURE);
    }

    output_file = fopen("tokens.txt", "w");
    if(output_file == NULL){
        perror("Não foi pessível criar o arquivo de saída!!");
        fclose(input_file);
        exit(EXIT_FAILURE);
    }

    yyin = input_file;
    yylex();

    fclose(input_file);
    fclose(output_file);

    return 0;
}