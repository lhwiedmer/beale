CFLAGS = -Wall -g -std=c99
objs = beale.o gerador_de_chaves.o codificador.o decodificador.o lib_lista_char.o lib_lista_pos.o 

all: beale

beale: $(objs)

beale.o: beale.c gerador_de_chaves.h codificador.h decodificador.o lib_lista_char.h lib_lista_pos.h
gerador_de_chaves.o: gerador_de_chaves.h gerador_de_chaves.c lib_lista_char.h lib_lista_pos.h
codificador.o: codificador.h codificador.c lib_lista_char.h lib_lista_pos.h
decodificador.o: decodificador.h decodificador.c lib_lista_char.h lib_lista_pos.h
lib_lista_char.o: lib_lista_char.h lib_lista_char.c lib_lista_pos.h
lib_lista_pos.o: lib_lista_pos.c lib_lista_pos.h

clean:
		-rm -f $(objs)

purge: clean
		-rm -f beale

destroy_txt:
		-rm -f *.txt

prepare: purge destroy_txt