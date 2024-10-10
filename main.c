#include <stdio.h>
#include "minhas_funcoes.h"
#include "regatas_barcos.h"
#include "constantes.h"

int main(){
    int opcao, continuar = 1;

    Regata regatas[TOTAL_REGATAS];   
    Barco barcos[TOTAL_BARCOS];
    Participante participantes[TOTAL_REGATAS * TOTAL_BARCOS_POR_REGATA];

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
                cadastrar_participantes(participantes, regatas, barcos);  
                break;

            case 4:
                lista_regatas_vencedores(regatas);  
                break;

            case 5:
                listar_participantes_com_tempo(participantes, regatas);
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