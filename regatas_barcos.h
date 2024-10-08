#ifndef REGATAS_BARCOS_H
#define REGATAS_BARCOS_H

typedef struct {
    int numero_barco;
    char nome_barco[50];
    int ano_fabricacao;
} Barco;
typedef struct {
    int numero_regata;
    char data[11];  // "dd/mm/yyyy"
    char hora_inicio[6];  // "hh:mm"
    int codigo_barco_vencedor;  // Código do barco vencedor
} Regata;
typedef struct {
    int numero_regata;
    int numero_barco;
    char hora_chegada[6];
}Participante;

#endif