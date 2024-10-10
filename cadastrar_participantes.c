#include <stdio.h>
#include "minhas_funcoes.h"
#include "regatas_barcos.h"
#include "constantes.h"


//Verificar se a regata esta no sistema
int verificar_existe_regata(Regata regata[], int numero_regata){
    for(int i=0; i<TOTAL_REGATAS; i++){
        if(regata[i].numero_regata == numero_regata){
            return 1;
        }
    }
    return 0;
}

//verificar se o barco esta no sistema
int verificar_existe_barco(Barco barco[], int numero_barco){
    for(int i=0; i<TOTAL_BARCOS; i++){
        if(barco[i].numero_barco == numero_barco){
            return 1;
        }
    }
    return 0;
}

//verificar se o barco ja esta cadastrado naquela regata
int verificar_participante(Participante participantes[], int total_participantes, int numero_regata, int numero_barco) {

    for (int i = 0; i < total_participantes; i++) {
        if (participantes[i].numero_regata == numero_regata && participantes[i].numero_barco == numero_barco) {
            return 1; 
        }
    }
    return 0; 
}

//verificar se a regata já atingiu o limite de participantes
int contar_barcos_por_regata(Participante participantes[], int num_participantes, int numero_regata) {
    int count = 0;
    for (int i = 0; i < num_participantes; i++) {
        if (participantes[i].numero_regata == numero_regata) {
            count++;
        }
    }
    return count;
}

//cadastrar os participantes
void cadastro_participantes(Participante participante[], Regata regata[], Barco barco[], int *total_participantes) {
    int numero_regata, numero_barco;

    printf("Digite o número da regata: ");
    scanf("%d", &numero_regata);

    printf("Digite o número do barco: ");
    scanf("%d", &numero_barco);

    if(verificar_existe_regata(regata, numero_regata) && verificar_existe_barco(barco, numero_barco)){

        if (verificar_participante(participante, *total_participantes, numero_regata, numero_barco)) {
            puts("Esse barco já está cadastrado para esta regata.");
            return;
        }

        // Verifica se o número máximo de participantes foi atingido
        if (contar_barcos_por_regata(participante, *total_participantes, numero_regata) >= TOTAL_BARCOS_POR_REGATA) {
            puts("Essa regata já possui o número máximo de barcos (4).");
            return;
        }

        // Registra o novo participante
        participante[*total_participantes].numero_regata = numero_regata;
        participante[*total_participantes].numero_barco = numero_barco;

        printf("Digite a hora de chegada (hh:mm): ");
        scanf("%s", participante[*total_participantes].hora_chegada);

        (*total_participantes)++; 
        puts("Participante cadastrado com sucesso!");

    } else {
        puts("O número da regata digitada e o número do barco digitado não constam no sistema. Lembre-se de cadastrá-los antes de cadastrar os participantes");
    }
}


void cadastrar_participantes(Participante participante[], Regata regata[], Barco barco[]) {
    int total_participantes = 0, continuar = 1, opcao;

    while(continuar){
        cadastro_participantes(participante, regata, barco, &total_participantes);

        printf("Deseja cadastrar outro participante? (1 - Sim, 0 - Não): ");
        scanf("%d", &continuar);
    }

    puts("Participantes cadastrados:");
    for (int i = 0; i < total_participantes; i++) {
        printf("Regata: %d, Barco: %d, Hora de Chegada: %s\n", 
               participante[i].numero_regata, 
               participante[i].numero_barco, 
               participante[i].hora_chegada);
    }
}