#ifndef DECODIFICADOR
#define DECODIFICADOR
#include "lib_lista_char.h"
#include "lib_lista_pos.h"
#include "gerador_de_chaves.h"

/* Caso s == 0, decodifica a mensagem presente 
 * em n_arq_cod, utilizando n_arq_l como um livro cifra.
 * Caso s tenha outro valor, n_arq_l é utilizado como 
 * um arquivo de chaves. Nos dois casos cria um arquivo 
 * com o nome passado em n_arq_dec, contendo a mensagem decodificada. 
 * Em caso de erro de abertura de arquivo, termina o programa com saída 1.
 * Em caso de erro de fechamento de arquivo, termina o programa com saída 2.*/
void decodifica(char* n_arq_cod, char* n_arq_l, char* n_arq_dec, int s);

#endif