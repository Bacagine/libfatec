/* Git Hub: https://github.com/Bacagine/fatec
 * 
 * Copyright (C) 2019 - 2021
 * 
 * str.h: Biblioteca criada pelos alunos de ADSM
 * contendo o prototipo de funções usadas para manipulação
 * de Strings
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
 * Date of last modification: 09/01/2021
 */

#ifndef _STR_H
#define _STR_H

#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 51

typedef char * String;

/* Função criada por Gustavo Bacagine 
 * e Lucas Pereira de Matos
 * 
 * Transforma uma String minuscula em maiuscula */
String strupper(String str);

/* Função criada por Gustavo Bacagine
 * 
 * Transforma uma String maiuscula em minuscula */
String strlower(String str);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * e desenvolvida por Gustavo Bacagine
 * 
 * Essa função substitui o caractere da posição dada pelo 2o argumento
 * no texto dado pelo 1o argumento pela tag passada como 3o
 * argumento */
void replace(String txt, int i, const String str);

/* Função criada por Gustavo Bacagine
 * 
 * Verifica se uma String é um
 * palindromo */
int palindrome(const String str);

/* Função criada por Gustavo Bacagine
 * 
 * Conta o tamanho de um String */
int count_str(const String str);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função recebe n Strings e determina quantas dessas 
 * Strings contém uma String qualquer 
 * dada pelo usuário. */
//void conta_str(void);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função receba uma String do teclado e 
 * informe quantas letras maiúsculas
 * ela possui. */
//void maiusculas(void);

/* Função criada por Gustavo Bacagine
 * 
 * Ela inverte os valores de duas Strings
 * passadas como argumento */
void sswap(String str1, String str2);

/* Função criada por Gustavo Bacagine
 * 
 * Ela inverte uma String */
void inverse(const String str, String new_str);

#endif // _STR_H
