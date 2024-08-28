#include <stdio.h>
#include <stdlib.h>

char alfabeto[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char *estados[] = {"q0", "q1"}; 

int Numero(char c) {
    int i;
    for (i = 0; i < sizeof(alfabeto); i++) {
        if (c == alfabeto[i]) {
            return 1;
        }
    }
    return 0;
}

int AFD(char *str) {
    char *estado_atual = estados[0]; 
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (!Numero(str[i])) {
            printf(" \n Entrada inválida! \n");
            return 0;
        }

        if (estado_atual == estados[0] && Numero(str[i])) {
            estado_atual = estados[1];
        } else if (estado_atual == estados[1] && Numero(str[i])) {
            estado_atual = estados[1];
        }
    }

    if (estado_atual == estados[1]) {
        printf("\n Entrada Válida! \n");
        return 1;
    } else {
        printf("\n Entrada inválida! \n");
        return 0;
    }
}

int main() {
    
    printf("Digite uma entrada: \n");
    
    char entrada[100];
    
    scanf("%s", entrada);
    
    if (AFD(entrada)) {
        printf("Saida: %s \n", entrada);
    }

    return 0;
}
