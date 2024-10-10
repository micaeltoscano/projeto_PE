#include <stdio.h>
#include "minhas_funcoes.h"
#include "regatas_barcos.h"
#include "constantes.h"


void lista_regatas_vencedores(Regata regatas[]){

     for (int i = 0; i < TOTAL_REGATAS; i++) {
        printf("Exibindo as regatas realizadas e seus vencedores:\n");
        printf("Número da Regata: %d\n", regatas[i].numero_regata);
        printf("Código do Barco Vencedor: %d\n\n", regatas[i].codigo_barco_vencedor);  
        printf("------------------------------------------\n");
    }
}