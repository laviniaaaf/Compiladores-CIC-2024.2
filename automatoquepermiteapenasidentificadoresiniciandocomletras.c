#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARACTERES 36 

int Letra(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int Numero(char c) {
    return c >= '0' && c <= '9';
}

int IdentificadorValido(const char *str) {
    if (!Letra(str[0])) {
        return 0; 
    }

    for (int i = 1; str[i] != '\0'; i++) {
        if (!Letra(str[i]) && !Numero(str[i])) {
            return 0;
        }
    }

    return 1; 
}

int main() {

    const char caracteres[NUM_CARACTERES] = "abcdefghijklmnopqrstuvwxyz0123456789";

    srand((unsigned int)time(NULL)); 

    int num_identificadores = rand()%20; 

    for (int i = 0; i < num_identificadores; i++) {
        int tamanho_identificador = rand() % 20;  // gera um número aleatório entre 0-19

        char identificador[tamanho_identificador + 1]; 
        identificador[0] = caracteres[rand() % NUM_CARACTERES]; 
        for (int j = 1; j < tamanho_identificador; j++) {
            identificador[j] = caracteres[rand() % NUM_CARACTERES];
        }
        identificador[tamanho_identificador] = '\0'; 

        if (IdentificadorValido(identificador)) {
            printf("%s\n", identificador);
        }
    }

    return 0;
}
