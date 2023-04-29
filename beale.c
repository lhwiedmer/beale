#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <getopt.h>
#include "lib_lista_pos.h"
#include "lib_lista_char.h"
#include "gerador_de_chaves.h"
#include "codificador.h"
#include "decodificador.h"

void erro_de_chamada() {
	printf("Chamada do programa esta errada.\nOs possiveis usos sao:\n");
	printf("./beale  -e  -b LivroCifra -m MensagemOriginal -o MensagemCodificada para codificar uma mensagem.\n");
	printf("./beale  -e  -b LivroCifra -m MensagemOriginal -o MensagemCodificada -c ArquivoDeChaves para codificar uma mensagem criando arquivo de chaves.\n");
	printf("./beale  -d  -i MensagemCodificada  -c ArquivoDeChaves  -o MensagemDecodificada para decodificar uam mensagem com livro cifra.\n");
	printf("./beale -d -i MensagemCodificada -b LivroCifra -o MensagemDecodificada para decodificar uma mensagem com arquivo de chaves.\n");
}

int main(int argc, char** argv) {
	if ((argc < 8) || (argc > 10)) {
		erro_de_chamada();
		return 4;
	}
	srand(time(NULL));
	char op;
	char b_flag = 0; char e_flag = 0; char m_flag = 0;
	char o_flag = 0; char c_flag = 0; char d_flag = 0;
	char i_flag = 0; char* n_arq_livro; char* n_arq_orig;
	char* n_arq_criado; char* n_arq_chaves; char* n_arq_cod;
	while ((op = getopt(argc, argv, "eb:m:o:c:di:")) != -1) {
		switch (op) {
		case 'e':
			if (e_flag) {
				erro_de_chamada();
				return 4;
			}
			e_flag = 1;
			break;
		case 'b':
			if (b_flag) {
				erro_de_chamada();
				return 4;
			}
			n_arq_livro = optarg;
			b_flag = 1;
			break;
		case 'm':
			if (m_flag) {
				erro_de_chamada();
				return 4;
			}
			n_arq_orig = optarg;
			m_flag = 1;
			break;
		case 'o':
			if (o_flag) {
				erro_de_chamada();
				return 4;
			}
			n_arq_criado = optarg;
			o_flag = 1;
			break;
		case 'c':
			if (c_flag) {
				erro_de_chamada();
				return 4;
			}
			n_arq_chaves = optarg;
			c_flag = 1;
			break;
		case 'd':
			if (d_flag) {
				erro_de_chamada();
				return 4;
			}
			d_flag = 1;
			break;
		case 'i':
			if (i_flag) {
				erro_de_chamada();
				return 4;
			}
			n_arq_cod = optarg;
			i_flag = 1;
			break;
		default:
			erro_de_chamada();
			return 4;
		}
	}
	if (d_flag == e_flag) {
		erro_de_chamada();
		return 4;
	}
	if (i_flag == m_flag) {
		erro_de_chamada();
		return 4;
	}
	if ((d_flag) && (b_flag) && (c_flag)) {
		erro_de_chamada();
		return 4;
	}
	if ((e_flag) && (b_flag) && (m_flag) && (o_flag)) { 
		struct lista_char* lista;
		lista = gera_lista_de_chaves(n_arq_livro);
		codifica(n_arq_orig, n_arq_criado, lista);
		if (c_flag)
			escreve_lista_no_arquivo(n_arq_chaves, lista);
		lista = destroi_lista_char(lista);
		return 0;
	}
	if ((d_flag) && (i_flag) && (o_flag)) {
		if (c_flag) {
			decodifica(n_arq_cod, n_arq_chaves, n_arq_criado, 1);
			return 0;
		}
		if (b_flag) {
			decodifica(n_arq_cod, n_arq_livro, n_arq_criado, 0);
			return 0;
		}
	}
 	erro_de_chamada();
	return 4;
}