#include <stdio.h>
#include "minhas_funcoes.h"
#include "regatas_barcos.h"
#include "constantes.h"


int converter_para_minutos(const char* hora) {
    int h, m;
    sscanf(hora, "%d:%d", &h, &m);
    return h * 60 + m;
}

int indice_regata(Regata regata[],  int n_regata) {
    // Percorre todas as regatas
    for (int i = 0; i < TOTAL_REGATAS; i++) {
        // Verifica se o número da regata corresponde
        if (regata[i].numero_regata == n_regata) {
            // Retorna a hora de início da regata encontrada
            return i;
        }
    }
}

int indice_participante(Participante participante[], int n_regata){
    for (int i = 0; i < TOTAL_REGATAS; i++) {
        if (participante[i].numero_regata == n_regata) {
            return i;
        }
    }

    return -1;
}

// Função para calcular o tempo levado e exibir barcos que participaram da regata
void listar_participantes_com_tempo(Participante participante[], Regata regata[]) {
    int n_regata;

    printf("Digite o numero da regata: ");
    scanf("%d", &n_regata);

    // Verifica se a regata existe no sistema
    int indice_regata = verificar_regata(regata, n_regata);
    
    if (indice_regata != -1) {
        int inicio_regata = converter_para_minutos(regata[indice_regata].hora_inicio);

        printf("Participantes da regata %d:\n", n_regata);
        printf("-----------------------------------\n");

        // Flag para verificar se algum participante foi encontrado
        int participante_encontrado = 0;
        // Percorre todos os participantes e verifica quem participou da regata
        for (int i = 0; i < TOTAL_PARTICIPANTES; i++) {
            if (participante[i].numero_regata == n_regata) {
                participante_encontrado = 1; // Marca que encontramos um participante

                int chegada_minutos = converter_para_minutos(participante[i].hora_chegada);
                int total_tempo = chegada_minutos - inicio_regata;

                // Ajustar para o caso em que a chegada foi no dia seguinte
                if (total_tempo < 0) {
                    total_tempo += 24 * 60; // Adiciona 24 horas em minutos
                }

                // Converter o tempo total em horas e minutos
                int horas = total_tempo / 60;
                int minutos = total_tempo % 60;

                // Imprimir o barco e o tempo de chegada
                printf("Numero do barco: %d \n", participante[i].numero_barco);
                printf("Tempo de chegada: %02d:%02d horas\n", horas, minutos);
                printf("-----------------------------------\n");
            }
        }

        // Caso não tenha participantes na regata
        if (!participante_encontrado) {
            printf("Nenhum participante encontrado para a regata %d.\n", n_regata);
        }
    } else {
        puts("Não foi possível encontrar a regata.");
    }
}
