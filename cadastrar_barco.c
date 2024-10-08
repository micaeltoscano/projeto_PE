#include "minhas_funcoes.h"
#include <stdio.h>
#include "regatas_barcos.h"
#define quantidade 6


int verificar_numero(Barco barco[], int num){

    for(int i=0; i<quantidade; i++){

        if(barco[i].numero_barco == num){
            return 1;
        }
    }
    return 0;
}

void cadastro(Barco barco[]){

    for(int i=0; i< quantidade; i++){
        int num;

        do{
        printf("Digite o codigo do codigo do %d barco : ", i+1);
        scanf("%d", &num);
        } while(verificar_numero(barco, num));

        barco[i].numero_barco = num;

        puts("Digite o nome do barco: ");
        scanf(" %[^\n]%*c", barco[i].nome_barco);

        puts("Digite o ano de fabricação do barco: ");
        scanf("%d", &barco[i].ano_fabricacao);
    }
}

void listar_barcos(Barco barco[]){

    for(int i=0; i<quantidade; i++){
        printf("Exibindo informações do barco %d\n: ", i);
        printf("Número do barco %d: %d\n", i, barco[i].numero_barco);
        printf("Nome do barco %d: %s\n", i, barco[i].nome_barco);
        printf("Ano de fabricação do barco %d: %d\n", i, barco[i].ano_fabricacao);
        printf("------------------------------------------");
    }
}

void buscar_barco(Barco barco[]){
   int num_barco;

    puts("Digite o número do barco que deseja acessar:");
    scanf("%d", &num_barco);

    if (verificar_numero(barco, num_barco)) {
        for (int i = 0; i < quantidade; i++) {
            if (barco[i].numero_barco == num_barco) {
                printf("Número do barco: %d\n", barco[i].numero_barco);
                printf("Nome do barco: %s\n", barco[i].nome_barco);
                printf("Ano de fabricação do barco: %d\n", barco[i].ano_fabricacao);
                return;
            }
        }
    }
    else{
        printf("Barco não foi encontrado!");
    }
}

void editar_barco(Barco barco[]){
    int num_barco;

    puts("Digite o indice do barco a ser editado: (considere 0 para o primeiro barco) ");
    scanf("%d", &num_barco);

    if (num_barco >= 0 && num_barco < quantidade) {
        printf("Digite o novo número do barco %d: (O número cadastrado atualmente é: %d)\n", num_barco, barco[num_barco].numero_barco);
        scanf("%d", &barco[num_barco].numero_barco);

        while (getchar() != '\n');

        printf("Digite o novo nome do barco %d: (O nome cadastrado atualmente é: %s)\n", num_barco, barco[num_barco].nome_barco);
        scanf("%[^\n]%*c", barco[num_barco].nome_barco);

        printf("Digite o novo ano de fabricacao do barco %d: (O ano cadastrado atualmente é: %d)\n", num_barco, barco[num_barco].ano_fabricacao);
        scanf("%d", &barco[num_barco].ano_fabricacao);
    } 
    else {
        printf("Barco não encontrado\n");
    }
}

void cadastrar_barco(Barco barco[]){

    int opcao_cadastrar_barco, continuar_cadastrar_barco = 0;

    cadastro(barco);

    puts("Todos os barcos foram cadastrados!");

    while(continuar_cadastrar_barco == 0){

        do {
            printf("O que deseja fazer?\n");
            printf("1 - Listar barcos cadastrados\n");
            printf("2 - Buscar barco especifico \n");
            printf("3 - Editar informações de um barco em especifico \n");
            printf("4 - Sair \n");
            printf("Escolha uma opção: ");

            scanf("%d", &opcao_cadastrar_barco);

            if (opcao_cadastrar_barco < 1 || opcao_cadastrar_barco > 5) {
                puts("Opção inválida. Tente novamente.");
            }
        }while (opcao_cadastrar_barco < 1 || opcao_cadastrar_barco > 5);

        switch(opcao_cadastrar_barco) {
            case 1:
                listar_barcos(barco);
                break;
            case 2:
                buscar_barco(barco);
                break;
            case 3:
                editar_barco(barco);
                break;
            case 4:
                continuar_cadastrar_barco = 1;
                break;
        }
    }
}