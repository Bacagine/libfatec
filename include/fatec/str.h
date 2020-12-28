/* Git Hub: https://github.com/Bacagine/fatec
 * 
 * Copyright (C) 2019 - 2020
 * 
 * str.h: Biblioteca criada pelos alunos de ADSM
 * contendo o prototipo de funções usadas para manipulação
 * de strings
 * 
 * fatec.h é um software livre; você pode redistribui-lo e/ou
 * modificalo sob os termos da Licença GNU Lesser General Public
 * publicada pela Free Software Foundation; ou
 * versão 2 da licença ou (a seu critério) qualquer versão posterior.
 * 
 * Você deve ter recebido uma copia da Licença GNU Lesser General Public
 * junto com o fatec.h; case contrario, veja:
 * <http://www.gnu.org/licenses/>.
 * 
 * Developers: Gustavo Bacagine          <gustavo.bacagine@protonmail.com>
 *             Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com>
 * 
 * Begin's date: 20/07/2020
 * Date of last modification: 21/07/2020
 */

#ifndef _STR_H
#define _STR_H

#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 51

typedef char * string;
typedef unsigned char byte;

/* Função criada por Gustavo Bacagine 
 * e Lucas Pereira de Matos
 * 
 * Transforma uma string minuscula em maiuscula */
string strupper(string str);

/* Função criada por Gustavo Bacagine
 * 
 * Transforma uma string maiuscula em minuscula */
string strlower(string str);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * 
 * Essa função é baseada na função criada por isrnick
 * O código original pode ser encontrado em:
 * https://www.clubedohardware.com.br/forums/topic/1402340-substituir-um-car%C3%A1cter-por-uma-palavra-em-c/ 
 * 
 * Essa função substitui o caractere da posição dada pelo 2o argumento
 * no texto dado pelo 1o argumento pela tag passada como 3o
 * argumento */
void replace(string str, int i, const string new_str);

/* Função criada por Gustavo Bacagine
 * 
 * Verifica se uma string é um
 * palindromo */
int palindrome(const string str);

/* Função criada por Gustavo Bacagine
 * 
 * Conta o tamanho de um string */
int count_str(const string str);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função recebe n strings e determina quantas dessas 
 * strings contém uma string qualquer 
 * dada pelo usuário. */
//void conta_str(void);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função receba uma string do teclado e 
 * informe quantas letras maiúsculas
 * ela possui. */
//void maiusculas(void);

/* Função criada por Gustavo Bacagine
 * 
 * Ela inverte os valores de duas strings
 * passadas como argumento */
void sswap(string str1, string str2);

/* Função criada por Gustavo Bacagine
 * 
 * Ela inverte uma string */
void inverse(const string str, string new_str);

#endif // _STR_H
