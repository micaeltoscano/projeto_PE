#include <stdio.h>
#include <string.h>
#include "minhas_funcoes.h"
#include "regatas_barcos.h"
#include "constantes.h"

void salvarDados(Regata regatas[], Barco barcos[], Participante participantes[], int totalRegatas, int totalBarcos, int totalParticipantes) {
    FILE *file = fopen("dados.txt", "w");
    //caso o arquivo não possa ser aberto o programa exibe uma mensagem de erro.
    if (file == NULL) {
        printf("Erro ao tentar escrever o arquivo.\n");
        return;
    }


    // Salvar barcos
    for (int i = 0; i < totalBarcos; i++) {
        fprintf(file, "Código do Barco %d: %d\n", i, barcos[i].numero_barco);
        fprintf(file, "Nome do Barco %d: %s\n", i, barcos[i].nome_barco);
        fprintf(file, "Ano de fabricação do barco %d: %d\n", i, barcos[i].ano_fabricacao);
        
    }

    // Salvar regatas
    for (int i = 0; i < totalRegatas; i++) {
        fprintf(file, "Número da Regata %d: %d\n", i, regatas[i].numero_regata);
        fprintf(file, "Data da Regata %d: %s\n", i, regatas[i].data);
        fprintf(file, "Hora de Início da Regata %d: %s\n", i, regatas[i].hora_inicio);
        fprintf(file, "Código do Barco Vencedor da Regata %d: %d\n", i, regatas[i].codigo_barco_vencedor);
    }

    // Salvar participantes
    for (int i = 0; i < totalParticipantes; i++) {
        fprintf(file, "Número da Regata do Participante %d: %d\n", i, participantes[i].numero_regata);
        fprintf(file, "Número do Barco do Participante %d: %d\n", i, participantes[i].numero_barco);
        fprintf(file, "Hora de Chegada do Participante %d: %s\n", i, participantes[i].hora_chegada);
    }

    fclose(file);
}

void carregarDados(Regata regatas[], Barco barcos[], Participante participantes[], int totalRegatas, int totalBarcos, int totalParticipantes) {
    FILE *file = fopen("dados.txt", "r");
    if (file == NULL) {
        printf("Erro ao ler o arquivo. \n");
        return;
    }

    for (int i = 0; i < totalBarcos; i++) {
        fscanf(file, "Código do Barco %d: %d\n", &i, &barcos[i].numero_barco);
        fscanf(file, "Nome do Barco %d: %[^\n]\n", &i, &barcos[i].nome_barco);
        fscanf(file, "Ano de fabricação do barco %d: %d\n", &i, &barcos[i].ano_fabricacao);  
        
    }     
    

    for (int i = 0; i < totalRegatas; i++){
        fscanf(file, "Número da Regata %d: %d\n", &i, &regatas[i].numero_regata);
        fscanf(file, "Data da Regata %d: %[^\n]\n", &i, &regatas[i].data);
        fscanf(file, "Hora de Início da Regata %d: %[^\n]\n", &i, &regatas[i].hora_inicio);
        fscanf(file, "Código do Barco Vencedor da Regata %d: %d\n", &i, &regatas[i].codigo_barco_vencedor);
    
    }
    for (int i = 0; i < totalParticipantes; i++) {
        fscanf(file, "Número da Regata do Participante %d: %d\n", &i, &participantes[i].numero_regata);
        fscanf(file, "Número do Barco do Participante %d: %d\n", &i, &participantes[i].numero_barco);
        fscanf(file, "Hora de Chegada do Participante %d: %[^\n]\n", &i, &participantes[i].hora_chegada);
        }

    fclose(file);
}
