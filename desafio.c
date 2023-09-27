#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    unsigned char armarios = 0;
    srand(time(NULL)); 

    int opcao;
    while (1) {
        printf("Menu:\n");
        printf("1. Ocupar armário\n");
        printf("2. Liberar armário\n");
        printf("3. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
                if (armarios == 0xFF) {
                    printf("Todos os armários estão ocupados.\n");
                } else {
                    int armario_aleatorio;
                    do {
                        armario_aleatorio = rand() % 8;
                    } while ((armarios & (1 << armario_aleatorio)) != 0);

                    armarios |= (1 << armario_aleatorio);
                    printf("Armário %d ocupado.\n", armario_aleatorio + 1);
                }
                break;
            case 2: 
                if (armarios == 0) {
                    printf("Todos os armários estão livres.\n");
                } else {
                    int posicao;
                    printf("Digite o número do armário a ser liberado (1-8): ");
                    scanf("%d", &posicao);

                    if (posicao < 1 || posicao > 8) {
                        printf("Número de armário inválido.\n");
                    } else {
                        int bit = posicao - 1;
                        if (armarios & (1 << bit)) {
                            armarios &= ~(1 << bit);
                            printf("Armário %d liberado.\n", posicao);
                        } else {
                            printf("Armário %d já está livre.\n", posicao);
                        }
                    }
                }
                break;
            case 3: 
                printf("Obrigado por usar o programa!\n");
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

        printf("Status dos armários:\n");
        for (int i = 0; i < 8; i++) {
            if (armarios & (1 << i)) {
                printf("Armário %d: Ocupado\n", i + 1);
            } else {
                printf("Armário %d: Livre\n", i + 1);
            }
        }
    }

    return 0;
}
