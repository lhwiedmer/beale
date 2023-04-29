#ifndef CODIFICADOR
#define CODIFICADOR
#include "lib_lista_pos.h"
#include "lib_lista_char.h"

/* Codifica uma mensagem presente no arquivo de nome
 * n_arq_orig, e escreve a mensagem codificada 
 * no arquivo de nome n_arq_cod. 
 * Em caso de erro de abertura de arquivo, termina o programa com saída 1.
 * Em caso de erro de fechamento de arquivo, termina o programa com saída 2. 
 * Em caso de erro por caracter nao aceito, termina o programa com saída 5.*/
void codifica(char* n_arq_orig, char* n_arq_cod, struct lista_char* lista);

#endif