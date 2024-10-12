//chamada das funcões usadas do arquivo contendo as structs e do arquivo contendo as constantes
#include <stdio.h>
#include "minhas_funcoes.h"
#include "regatas_barcos.h"
#include "constantes.h"
#include <locale.h>
#include <windows.h>


int main(){

    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL,"pt_BR.UTF-8");

    //criacao da variavel para continuar o loop do menu
    int opcao = 0, continuar = 1;

    //chamada das structs, cada uma com a quantidade respectiva de regatas, barcos e a quantidade total de participantes
    Regata regatas[TOTAL_REGATAS];   
    Barco barcos[TOTAL_BARCOS];
    Participante participantes[TOTAL_REGATAS * TOTAL_BARCOS_POR_REGATA];

    //exibicao do menu com as opcoes possiveis
    printf("BEM VINDO AO PAGO BEM!\n");

    while(continuar){
        
        do {
            printf("O que deseja fazer?\n");
            printf("1 - Cadastrar barco\n");
            printf("2 - Cadastrar regata\n");
            printf("3 - Cadastrar participantes\n");
            printf("4 - Lista de vencedores\n");
            printf("5 - Lista de barcos em determinada regata\n");
            printf("6 - Salvar Dados Cadastrados\n");
            printf("7 - Carregar Dados Salvos\n");
            printf("8 - Mostrar Dados Carregados\n");
            printf("9 - Sair\n");
            printf("Escolha uma opção: ");

            scanf("%d", &opcao);

            if (opcao < 1 || opcao > 9) {
                puts("Opção inválida. Tente novamente.");
            }

        } while (opcao < 1 || opcao > 9);

        //criacao do switch para mapear escolhas do usuario
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
                salvarDados(regatas, barcos, participantes, TOTAL_REGATAS, TOTAL_BARCOS, TOTAL_REGATAS * TOTAL_BARCOS_POR_REGATA);
                break;

            case 7:
                carregarDados(regatas, barcos, participantes, TOTAL_REGATAS, TOTAL_BARCOS, TOTAL_REGATAS * TOTAL_BARCOS_POR_REGATA);
                break;

            case 8:
                listar_barcos(barcos);
                listar_regata(regatas);
                listar_participantes(participantes,TOTAL_PARTICIPANTES);
                break;

            case 9:
                continuar = 0;
                break;

            default:
                puts("Opção inválida.");
                break;
        }
    }

    return 0;
}