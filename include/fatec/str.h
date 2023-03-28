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
 * Date of last modification: 27/03/2023
 */

#ifndef _STR_H
#define _STR_H

#include <string.h>
#include <ctype.h>

//#define MAX_STR_LEN 51

/* Used for colored strings */
#define BLACK_STR     "\033[0;30m"
#define RED_STR       "\033[0;31m"
#define GREEN_STR     "\033[0;32m"
#define YELLOW_STR    "\033[0;33m"
#define BLUE_STR      "\033[0;34m"
#define PURPLE_STR    "\033[0;35m"
#define BLUE_CYAN_STR "\033[0;36m"
#define WHITE_STR     "\033[0;37m"

#define BLACK_BOLD_STR     "\033[1;30m"
#define RED_BOLD_STR       "\033[1;31m"
#define GREEN_BOLD_STR     "\033[1;32m"
#define YELLOW_BOLD_STR    "\033[1;33m"
#define BLUE_BOLD_STR      "\033[1;34m"
#define PURPLE_BOLD_STR    "\033[1;35m"
#define BLUE_CYAN_BOLD_STR "\033[1;36m"
#define WHITE_BOLD_STR     "\033[1;37m"

#define END_COLOR_STR "\033[m"

/* FATEC itoa.
 * 
 * It is a implementation of itoa
 * function.
 * 
 * This macro transforms an integer
 * passed with first argument 
 * into a string passed with second
 * argument according to the base
 * passes with third argument */
#define fitoa(value, str, base){ \
    if(base == 10){\
        sprintf(str, "%d", value);\
        str;\
    }\
    else if(base == 8){\
        sprintf(str, "%o", value);\
        str;\
    }\
    else if(base == 16){\
        sprintf(str, "%x", value);\
        str;\
    }\
    else{\
        NULL;\
    }\
}

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

/* Remove \n of a string */
void remove_new_line(char *str);

#endif // _STR_H
