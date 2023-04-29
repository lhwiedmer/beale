# beale
Um programa que codifica e decodifica mensagens em ASCII

1. Funcionalidades
O programa possue as funções de codificação e decodificação de uma mensagem escrita em ASCII. 
Para codificar uma mensagem, é necessário um arquivo com a mensagem, e um arquivo com um "livro cifra" que será usado na codificação.
Esse processo gera um arquivo com uma mensagem codificada, e caso especificado,
um  arquivo com a lista de chaves gerada para codificar a mensagem original.
Já para decodificar uma mensagem, é necessário um arquivo com a mensagem codificada,
e o usuário deve escolher entre usar o livro cifra utilizado para a codificação 
ou o arquivo de chaves gerados no processo de codificação(caso o usuário não tenha escolhido gerá-lo, apenas a opção com o livro cifra existe).

2. Chamadas de programa
O programa possui apenas 4 formatos de chamada,
caso o formato da chamada seja diferente do aceito o programa acusará erro e terminará com status de saída 4,
e caso um arquivo errado seja utilizado(Ex:livro cifra no lugar do arquivo de chaves) o programa terá um resultado indesejado.
As possíveis chamadas são:
"./beale  -e  -b LivroCifra -m MensagemOriginal -o MensagemCodificada" para codificar uma mensagem.\n
"./beale  -e  -b LivroCifra -m MensagemOriginal -o MensagemCodificada -c ArquivoDeChaves" para codificar uma mensagem criando arquivo de chaves
"./beale  -d  -i MensagemCodificada  -c ArquivoDeChaves  -o MensagemDecodificada" para decodificar uam mensagem com livro cifra
"./beale -d -i MensagemCodificada -b LivroCifra -o MensagemDecodificada" para decodificar uma mensagem com arquivo de chaves.

3. Módulos
O programa possui um arquivo .c main, com o nome de beale.c e e 5 arquivos de header .h com suas implementações
em arquivos .c de mesmo nome.

3.1. lib_lista_pos
Possui uma estrutura de dados chamada nodo_pos e outra chamada lista_pos
e funções que realizam processos com essas estruturas. A estrutura nodo_pos
possui um inteiro pos que representa uma das posições de um caracter no livro cifra
e um ponteiro prox, que aponta para o próximo nodo_pos. 
Já a lista_pos possui um ponteiro ini que aponta para o primeiro 
nodo_pos da lista, e um inteiro tam que conta o número de nodos_pos nela.
Para detalhes sobre as funcionalidades de cada função, leia o arquivo lib_lista_pos.h.

3.2. lib_lista_char 
Possui uma estrutura de dados chamada nodo_char e outra chamada lista_char
e funções que realizam processos com essas estruturas. A estrutura nodo_char
possui um char c que representa um caracter da tabela ASCII, um ponteiro para uma lista_pos,
que guarda todas as posições de c no livro cifra, e um ponteiro para o próximo nodo_char.
Já a estrutura lista_char possui apenas um ponteriro ini que aponta para o primeiro nodo_char da lista.
Para detalhes sobre as funcionalidades de cada função, leia o arquivo lib_lista_char.h.

3.3 gerador_de_chaves
Possui funções que lidam com a lista de chaves. A função gera_lista_de_chaves
usa um livro cifra para gerar uma lista de chaves, logo depois a completa
com todos os caracteres com códigos entre 33 e 126 na tabela ASCII que não estavem na lista,
sendo que cada um desses caracteres recebe em sua lista_pos um número negativo diferente 
a partir de -2, e por fim, retorna a lista produzida. A função escreve_lista_no_arquivo
escreve a lista_char passada por parâmetro em um arquivo(com o nome passado por parâmetro)
de maneira formatada. A função escreve_arquivo_na_lista escreve o conteúdo de um arquivo
com o formato correto(com o nome passado por parâmetro) em uma lista_char e a retorna.
Para mais detalhes sobre erros e retornos de função, leia o arquivo gerador_de_chaves.h.

3.4 codificador
Possui uma função que codifica uma mensagem(presente em um arquivo com o nome passado por parâmetro)
utilizando uma lista_char passada por parâmetro, 
e escreve essa mensagem codificada em um arquivo(com o nome passado por parâmetro).
Para mais detalhes sobre erros e retornos da função, leia o arquivo codificador.h.

3.5 decodificador
Possui uma função que decodifica uma mensagem(presente em um arquivo com o nome passadp por parâmetro)
utilizando um livro_cifra(nome do arquivo passado por parâmetro) caso s == 0 ou 
utilizando um arquivo de chaves(com o nome passado por parâmetro) caso s seja outro valor. Escreve a mensagem
decodificada em um arquivo(com o nome passado por parâmetro. Caso a mensagem original possua o caracter \n
esse caracter é codificado e decoficado como se ele fosse um ' ', então a mensagem decodificada não possui quebras de linha.
Para mais detalhes sobre erros e retornos da função, leia o arquivo decodificador.h.

4. Erros
O programa trata alguns casos de erro, esses casos e suas devidas resoluções sendo:
4.1 Erro de abertura de arquivo: Mostra mensagem de erro e termina o programa com status de saída 1.
4.2 Erro de fechamento de arquivo: Mostra mensagem de erro e termina o programa com status de saída 2.
4.3 Erro de alocação de memória: Mostra mensagem de erro e termina o programa com status de saída 3.
4.4 Erro de chamada de programa: Mostra mensagem de erro e termina o programa com status de saída 4.
4.5 Erro de codificação por conta de caractere que não pertence à Tabela ASCII: Mostra mensagem de erro e termina o programa com status de saída 5.
