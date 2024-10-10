#include <stdio.h>
#include "minhas_funcoes.h"
#include "regatas_barcos.h"
#include "constantes.h"

//evitar comportamentos inesperados do sistema
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int verificar_regata(Regata regatas[], int num) {
    for (int i = 0; i < TOTAL_REGATAS; i++) {
        if (regatas[i].numero_regata == num) {
            return i;  
        }
    }
    return -1;  
}
// Função para listar as regatas
void listar_regata(Regata *regata) {

    for (int i = 0; i < TOTAL_REGATAS; i++) {
        printf("Exibindo informações da regata %d:\n", i + 1);
        printf("Número da Regata: %d\n", regata[i].numero_regata);
        printf("Data: %s\n", regata[i].data);
        printf("Hora de Início: %s\n", regata[i].hora_inicio);
        printf("Código do Barco Vencedor: %d\n\n", regata[i].codigo_barco_vencedor);  
        printf("------------------------------------------\n");
    }
}
// Função para buscar regata por número
void buscar_regata(Regata regata[]) {
    int num;
    puts("Digite o número da regata que deseja buscar:");
    scanf("%d", &num);
    
    int indice = verificar_regata(regata, num);
    
    if (indice != -1) {
        printf("Regata encontrada:\n");
        printf("Número: %d\n", regata[indice].numero_regata);
        printf("Data: %s\n", regata[indice].data);
        printf("Hora de Início: %s\n", regata[indice].hora_inicio);
        printf("Código do barco vencedor: %d\n", regata[indice].codigo_barco_vencedor); 
    } else {
        puts("Regata não encontrada.");
    }
}
// Função para editar regata
void editar_regata(Regata regata[]) {

    int num;
    puts("Digite o número da regata que deseja editar:");
    scanf("%d", &num);
    
    int indice = verificar_regata(regata, num);
    
    if (indice != -1) {
        printf("Editando regata número: %d\n", num);

        getchar(); 

        puts("Digite a nova data (dd/mm/aaaa):");
        scanf("%[^\n]%*c", regata[indice].data);
        
        puts("Digite a nova hora de início (hh:mm):");
        scanf("%[^\n]%*c", regata[indice].hora_inicio);

        puts("Digite o novo código do barco vencedor:");
        scanf("%d", &regata[indice].codigo_barco_vencedor);  

        puts("Informações atualizadas com sucesso!");
    } else {
        puts("Regata não encontrada.");
    }
}

// Função para cadastrar regatas
void cadastrar(Regata regata[]) {
    for (int i = 0; i < TOTAL_REGATAS; i++) {
        int num_regata;

        do {
            puts("Digite o número da regata: ");
            scanf("%d", &num_regata);
            limpar_buffer(); 

            // Verifique se o número da regata já existe
            if (verificar_regata(regata, num_regata) != -1) {
                puts("O número da regata já consta no sistema. Certifique-se de que está digitando o número correto!");
            }
        } while (verificar_regata(regata, num_regata) != -1); // Se já existe, pede novamente

        regata[i].numero_regata = num_regata;

        puts("Digite a data no formato (dd/mm/aaaa): ");
        scanf("%[^\n]%*c", regata[i].data);

        puts("Digite a hora de início (hh:mm): ");
        scanf("%[^\n]%*c", regata[i].hora_inicio);

        puts("Digite o código do barco vencedor: ");
        scanf("%d", &regata[i].codigo_barco_vencedor);  
    }
}

// Função principal de controle para cadastrar e gerenciar regatas
void cadastrar_regata(Regata regatas[]) {
    int opcao_cadastrar_regata, continuar_cadastrar_regatas = 0;
    cadastrar(regatas);

    while (continuar_cadastrar_regatas == 0) {
        do {
            printf("O que deseja fazer?\n");
            printf("1 - Listar regatas cadastradas\n");
            printf("2 - Buscar regata específica\n");
            printf("3 - Editar informações de uma regata específica\n");
            printf("4 - Sair\n");
            printf("Escolha uma opção: ");
            scanf("%d", &opcao_cadastrar_regata);

            if (opcao_cadastrar_regata < 1 || opcao_cadastrar_regata > 4) {
                puts("Opção inválida. Tente novamente.");
            }
        } while (opcao_cadastrar_regata < 1 || opcao_cadastrar_regata > 4);

        switch (opcao_cadastrar_regata) {
            case 1:
                listar_regata(regatas);
                break;
            case 2:
                buscar_regata(regatas);
                break;
            case 3:
                editar_regata(regatas);
                break;
            case 4:
                continuar_cadastrar_regatas = 1;
                break;
        }
    }
}
