#include <stdio.h>
#include "minhas_funcoes.h"
#include "regatas_barcos.h"
#define max_regatas 4
#define max_barcos 6

int main(){
    int opcao, continuar = 1;

    Regata regatas[max_regatas];   
    Barco barcos[max_barcos];
    

    printf("BEM VINDO AO PAGO BEM!\n");

    while(continuar){
        
        do {
            printf("O que deseja fazer?\n");
            printf("1 - Cadastrar barco\n");
            printf("2 - Cadastrar regata\n");
            printf("3 - Cadastrar participantes\n");
            printf("4 - Lista de vencedores\n");
            printf("5 - Lista de barcos em determinada regata\n");
            printf("6 - Sair\n");
            printf("Escolha uma opção: ");

            scanf("%d", &opcao);

            if (opcao < 1 || opcao > 6) {
                puts("Opção inválida. Tente novamente.");
            }

        } while (opcao < 1 || opcao > 6);

         switch (opcao) {
            case 1:
                cadastrar_barco(barcos);  
                break;

            case 2:
                cadastrar_regata(regatas);  
                break;

            case 3:
                cadastrar_participantes(regatas, barcos);  
                break;

            case 4:
                lista_regatas_vencedores(regatas);  
                break;

            case 5:
                //desenvolver  
                break;

            case 6:
                continuar = 0;  
                break;

            default:
                puts("Opção inválida.");
                break;
        }
    }

    return 0;
}