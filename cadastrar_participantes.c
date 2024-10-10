#include <stdio.h>
#include <string.h>
#include "minhas_funcoes.h"
#include "regatas_barcos.h"
#include "constantes.h"

// Verificar se a regata está no sistema
int verificar_existe_regata(Regata regata[], int numero_regata) {
    for (int i = 0; i < TOTAL_REGATAS; i++) {
        if (regata[i].numero_regata == numero_regata) {
            return 1;
        }
    }
    return 0;
}

// Verificar se o barco está no sistema
int verificar_existe_barco(Barco barco[], int numero_barco) {
    for (int i = 0; i < TOTAL_BARCOS; i++) {
        if (barco[i].numero_barco == numero_barco) {
            return 1;
        }
    }
    return 0;
}

// Verificar se o barco já está cadastrado naquela regata
int verificar_participante(Participante participantes[], int total_participantes, int numero_regata, int numero_barco) {
    for (int i = 0; i < total_participantes; i++) {
        if (participantes[i].numero_regata == numero_regata && participantes[i].numero_barco == numero_barco) {
            return 1;
        }
    }
    return 0;
}

// Verificar se a regata já atingiu o limite de participantes
int contar_barcos_por_regata(Participante participantes[], int num_participantes, int numero_regata) {
    int count = 0;
    for (int i = 0; i < num_participantes; i++) {
        if (participantes[i].numero_regata == numero_regata) {
            count++;
        }
    }
    return count;
}


// Cadastrar os participantes
void cadastro_participantes(Participante participante[], Regata regata[], Barco barco[], int *total_participantes) {
    int numero_regata, numero_barco;

    printf("Digite o número da regata: ");
    scanf("%d", &numero_regata);

    printf("Digite o número do barco: ");
    scanf("%d", &numero_barco);

    // Verifica se a regata e o barco existem
    if (!verificar_existe_regata(regata, numero_regata) || !verificar_existe_barco(barco, numero_barco)) {
        puts("O número da regata ou do barco digitado não constam no sistema. Tente novamente.");
        return; // Retorna sem realizar o cadastro
    }

    // Verifica se o barco já está cadastrado para esta regata
    if (verificar_participante(participante, *total_participantes, numero_regata, numero_barco)) {
        puts("Esse barco já está cadastrado para esta regata.");
        return; // Encerrar a execução de uma função e retornar
    }

    // Verifica se o número máximo de participantes foi atingido
    if (contar_barcos_por_regata(participante, *total_participantes, numero_regata) >= TOTAL_BARCOS_POR_REGATA) {
        puts("Essa regata já possui o número máximo de barcos (4).");
        return;
    }

    // Registrar o novo participante
    participante[*total_participantes].numero_regata = numero_regata;
    participante[*total_participantes].numero_barco = numero_barco;

    char hora_chegada[6]; // String para armazenar a hora de chegada
    printf("Digite a hora de chegada (hh:mm): ");
    scanf("%s", hora_chegada);

    // Verifica se a hora está no formato correto
    if (!verificar_formato_horario(hora_chegada)) {
        puts("Formato de hora inválido. A hora deve estar no formato hh:mm.");
        return; // Retorna se o formato for inválido
    }

    // Armazena a hora de chegada
    strcpy(participante[*total_participantes].hora_chegada, hora_chegada);

    (*total_participantes)++;
    puts("Participante cadastrado com sucesso!");
}

void cadastrar_participantes(Participante participante[], Regata regata[], Barco barco[]) {
    int total_participantes = 0, continuar = 1;

    while (continuar) {
        cadastro_participantes(participante, regata, barco, &total_participantes);

        // Perguntar se deseja cadastrar outro participante
        if (total_participantes < TOTAL_BARCOS_POR_REGATA) {
            printf("Deseja cadastrar outro participante? (1 - Sim, 0 - Não): ");
            scanf("%d", &continuar);
        } else {
            puts("Limite de participantes atingido.");
            continuar = 0; // Encerra o loop se o limite for atingido
        }
    }

    // Exibir participantes cadastrados
    puts("Participantes cadastrados:");
    for (int i = 0; i < total_participantes; i++) {
        printf("Regata: %d, Barco: %d, Hora de Chegada: %s\n", 
               participante[i].numero_regata, 
               participante[i].numero_barco, 
               participante[i].hora_chegada);
    }
}


