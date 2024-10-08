#include <stdio.h>
#include "minhas_funcoes.h"
#include "regatas_barcos.h"
#define max_barcos 4
#define max_regatas 3
#define quantidade_barcos 6


int verificar_existe_regata(Regata regata[], int numero_regata){
    for(int i=0; i<max_regatas; i++){
        printf("AAAAAA: %d\n", regata[i].numero_regata);
        if(regata[i].numero_regata == numero_regata){
            return 1;
        }
    }
    return 0;
}

int verificar_existe_barco(Barco barco[], int numero_barco){
    for(int i=0; i<quantidade_barcos; i++){
        if(barco[i].numero_barco == numero_barco){
            return 1;
        }
    }
    return 0;
}

int verificar_participante(Participante participantes[], int total_participantes, int numero_regata, int numero_barco) {

    for (int i = 0; i < total_participantes; i++) {
        if (participantes[i].numero_regata == numero_regata && participantes[i].numero_barco == numero_barco) {
            return 1; 
        }
    }
    return 0; 
}

int contar_barcos_por_regata(Participante participantes[], int num_participantes, int numero_regata) {
    int count = 0;
    for (int i = 0; i < num_participantes; i++) {
        if (participantes[i].numero_regata == numero_regata) {
            count++;
        }
    }
    return count;
}

void cadastro_participantes(Participante participante[], Regata regata[], Barco barco[], int *total_participantes){
    int numero_regata, numero_barco;

    if(*total_participantes > (max_barcos * max_regatas)){
        puts("O número máximo de participantes foi alcançado! ");
        return;
    }

    printf("Digite o número da regata: ");
    scanf("%d", &numero_regata);

    printf("Digite o número do barco: ");
    scanf("%d", &numero_barco);

    if(verificar_existe_regata(regata, numero_regata) && verificar_existe_barco(barco, numero_barco)){

        if (verificar_participante(participante, *total_participantes, numero_regata, numero_barco)) {
            puts("Esse barco já está cadastrado para esta regata.");
            return;
                    }

        if (contar_barcos_por_regata(participante, *total_participantes, numero_regata) >= max_barcos) {
            puts("Essa regata já possui o número máximo de barcos (4).");
            return;
                    }

        participante[*total_participantes].numero_regata = numero_regata;
        participante[*total_participantes].numero_barco = numero_barco;

        printf("Digite a hora de chegada (hh:mm): ");
        scanf("%s", participante[*total_participantes].hora_chegada);

        (*total_participantes)++; 
        puts("Participante cadastrado com sucesso!");

    }

    else{
        puts("O número da regata digitada e o número do barco digitado não constam no sistema. Lembre-se de cadastrá-los antes de cadastrar os participantes");
    }

}

void cadastrar_participantes(Regata regata[], Barco barco[]) {
    Participante participante[max_barcos * max_regatas];
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