#include "minhas_funcoes.h"
#include <stdio.h>
#include "regatas_barcos.h"
#include "constantes.h"

//verificar se o barco esta no sistema
int verificar_numero(Barco barco[], int num){
    for(int i=0; i<TOTAL_BARCOS; i++){

        if(barco[i].numero_barco == num){
            return 1;
        }
    }
    return 0;
}

void cadastro(Barco barco[]){

    for(int i = 0; i < TOTAL_BARCOS; i++) {
        int num;
        int retorno_scanf;

        //uso do do-while para verificar se o codigo digitado é um inteiro e verificar se já existe um barco com aquele numero
        do {
            printf("Digite o codigo do barco %d: ", i + 1);

            //verificar se a entrada é válida
            retorno_scanf = scanf("%d", &num);

            //se a entrada não for um número inteiro
            if (retorno_scanf != 1) {
                printf("Entrada inválida. Por favor, insira um número.\n");

                while (getchar() != '\n');
            }
        } while (retorno_scanf != 1 || verificar_numero(barco, num));

        //caso seja, o barco é adicionado no sistema:
        barco[i].numero_barco = num;

        printf("Digite o nome do barco: ");
        scanf(" %[^\n]%*c", barco[i].nome_barco);

        printf("Digite o ano de fabricação do barco: ");
        scanf("%d", &barco[i].ano_fabricacao);
    }
}

//funcao que loopa entre os structs e exibe todos os barcos cadastrados:
void listar_barcos(Barco barco[]){

    for(int i=0; i<TOTAL_BARCOS; i++){

        printf("\nExibindo informações do barco %d:\n", i + 1); 
        printf("Número do barco: %d\n", barco[i].numero_barco);
        printf("Nome do barco: %s\n", barco[i].nome_barco);
        printf("Ano de fabricação: %d\n", barco[i].ano_fabricacao);
        printf("------------------------------------------\n");
    }
}

//funcao para buscar um barco pelo numero dele
void buscar_barco(Barco barco[]){
   int num_barco;

    puts("Digite o número do barco que deseja acessar:");
    scanf("%d", &num_barco);

    //se o barco existir no sistema, ele procura por ele e exibe as informacoes dele atraves do indice
    if (verificar_numero(barco, num_barco)) {
        for (int i = 0; i < TOTAL_BARCOS; i++) {
            if (barco[i].numero_barco == num_barco) {
                printf("Número do barco: %d\n", barco[i].numero_barco);
                printf("Nome do barco: %s\n", barco[i].nome_barco);
                printf("Ano de fabricação do barco: %d\n", barco[i].ano_fabricacao);
                return;
            }
        }
    }

    //caso contrario exibe uma mensagem de erro
    else{
        printf("Barco não foi encontrado!");
    }
}

//funcao para editar informações de um barco
void editar_barco(Barco barco[]) {
    int num_barco, novo_num;
    
    puts("Digite o número do barco a ser editado (considere 1 para o primeiro barco): "); //nesse caso, o usuario procura o barco pelo seu indice
    scanf("%d", &num_barco);

    num_barco--;  // Subtrai 1 para mapear para o índice correto no array

    // Verifica se o índice é válido
    if (num_barco >= 0 && num_barco < TOTAL_BARCOS) {
        printf("Barco selecionado: %d\n", barco[num_barco].numero_barco);
        
        //validacao para garantir que o novo número do barco nao seja duplicado
        do {
            printf("Digite o novo número do barco %d (atualmente %d): ", num_barco + 1, barco[num_barco].numero_barco);
            scanf("%d", &novo_num);
    
            // Verifica apenas se o novo número é diferente do atual
            if (novo_num != barco[num_barco].numero_barco && verificar_numero(barco, novo_num)) {
            printf("Número já cadastrado. Por favor, insira outro.\n");
    }
        } while (novo_num != barco[num_barco].numero_barco && verificar_numero(barco, novo_num));
        
        barco[num_barco].numero_barco = novo_num;

        // Limpa o buffer após a leitura de número
        while (getchar() != '\n'); 

        // Solicita o novo nome do barco
        printf("Digite o novo nome do barco %d (atualmente %s): ", num_barco + 1, barco[num_barco].nome_barco);
        scanf("%[^\n]%*c", barco[num_barco].nome_barco);

        // Solicita o novo ano de fabricação do barco
        printf("Digite o novo ano de fabricação do barco %d (atualmente %d): ", num_barco + 1, barco[num_barco].ano_fabricacao);
        scanf("%d", &barco[num_barco].ano_fabricacao);

        printf("Barco %d atualizado com sucesso!\n", num_barco + 1);
    } 
    else {
        printf("Barco não encontrado. Por favor, insira um número válido.\n");
    }
}

//funcao que cadastra o barco e exibe a quantidade de opcoes que o usuario tem dentro do sistema de cadastrar barcos.
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

            if (opcao_cadastrar_barco < 1 || opcao_cadastrar_barco > 4) {
                puts("Opção inválida. Tente novamente.");
            }
        }while (opcao_cadastrar_barco < 1 || opcao_cadastrar_barco > 4);

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