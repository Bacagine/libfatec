/* Git Hub: https://github.com/Bacagine/fatec
 * 
 * Copyright (C) 2019 - 2020
 * 
 * fatec.h: Library was created by ADSM students
 * having the prototype of functions and structures that
 * was used during the course.
 * 
 * this is a free software; you can redistribute and/or
 * change under the Licence GNU Lesser General Public terms
 * published by Free Software Foundation; or
 * version 2 of the licence or (by your criteria) any previous version.
 * 
 * You must have received a copy of the Licence GNU Lesser General Public
 * with the software; otherwise, see:
 * <http://www.gnu.org/licenses/>.
 * 
 * Developers: Gustavo Bacagine          <gustavo.bacagine@protonmail.com>
 *             José Eduardo              <joseeduardoolimpios@gmail.com>
 *             Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com>
 *             Caio Elias Emerick Regino <caioregino.147@gmail.com>
 *             Luiz Dionizio             <luizgdsoares@hotmail.com>
 *             Profº Ciro Cirne Trindade <ciroct@gmail.com>
 * 
 * Begin's date: 12/02/2019
 * Date of the last modification: 09/01/2020 */

#ifndef _FATEC_H
#define _FATEC_H

#ifndef _STDIO_H
    #include <stdio.h>
#endif // _STDIO_H

#ifndef _LOCALE_H
    #include <locale.h>
#endif // _LOCALE_H

#ifndef _STRING_H
    #include <string.h>
#endif // _STRING_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

// Verify if the system is the unix like
#ifdef __unix__
    #define UNIX
//    #include <stdlib.h>
    #define clear_terminal() printf("\033\143");
    #define stay() printf("\nPress enter to continue..."); getchar();
// Verify if the system is a Windows or if the program was compiled for Windows
#elif defined(_WIN32) || defined(WIN32) || defined(__MINGW32__) || defined(_MCS_VER)
    #define WIN
    #include <stdlib.h>
    #define clear_terminal() system("cls");
    #define stay("pause");
#endif // __unix__

// Definitions by Gustavo Bacagine

/* Version of libfatec */
#define __FATEC_VERSION__ "20.12.28"

/* Description of the library */
#define FATEC_DESCRIPTION "libfatec is a library created by ADSM students having\n\
the prototypo of the functions and structures that was used during the course.\n"

/* Error message in case 
 * user type an 
 * invalid option */
#define MENU_ERROR "ERROR: Invalid option!"

/* Max length for
 * a name */
#define MAX_NAME_LEN 51

/* Max length that
 * the name characters
 * of a file can have */
#define MAX_FILE_LEN 257

/* Max length for
 * a line */
#define MAX_LINE_LEN 100000

/* Following the most used functions by ADSM
 * students of Carapicuíba's FATEC */

/* Function used to avoid 
 * Buffer Overflow
 * 
 * Você pode se perguntar o motivo
 * para se usar uma função propia para
 * limpar o buffer do terminal ao invés
 * de usar uma função já pronta encontrada
 * na propia linguagem
 * 
 * Existem muitas funções que poderiamos
 * usar como: fflush(), setbuf(), etc...
 * 
 * O motivo para usarmos essa função está
 * no fato de que as funções listadas acima
 * não funcionam em todos os Sistemas Operacionais.
 * O fflush() funciona no Windows mas não funciona no
 * Linux e no MasOS; já o setbuf() funciona tanto no
 * Linux como no Windows, porém não funciona no MasOS.
 * 
 * Está função que usamos funciona em todos os
 * Sistemas Operacionais. Por isso achamos que essa seja
 * a melhor opção a ser usada.
 * 
 * OBS: Essa função não foi 
 * desenvolvida por nós. Percebemos 
 * que muitos programadores 
 * se utilizam dessa função e 
 * passamos a usa-lá em nossos programas */
void clear_buffer(void);

/* Function created by professor Ciro Cirne Trindade
 * 
 * Other way to clean the terminal
 * buffer. */
void buffer_clean(void);

/* Function created by Gustavo Bacagine
 * 
 * Ela printa um menu no terminal
 * Foi feita como um exemplo apenas pois,
 * o menu normalmente fica na função main.
 * Você pode usa-lá para criar seus propios menus*/
//void menu(void);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função receba uma string de 0s e 1s, interprete
 * essa string como um número binário e 
 * informe o valor desse número na base decimal. */
//void binario_decimal(void);

/* This function was created by Herbert Schildt
 * We took it in his book "C Completo e Total"
 * and we did an adaptation that make the function jumps one
 * line at the end of the string.
 * 
 * This function works similar to 'puts()'
 * printing a string in the terminal exit. */
void print(const char *str);

/* Function created by Gustavo Bacagine
 * 
 * This function works similiar to 'fputs()'
 * printing a string in a file or in
 * a exit of your choice */
void fprint(FILE *__stream, const char *str);

/* Function created by Gustavo Bacagine
 * 
 * It shows the content of one
 * file in the beginning until the end */
int cat(const char *file);

/* Function created by Gustavo Bacagine
 * 
 * It shows the content of one
 * file in the end until the beginning */
//int tac(const char *file);

/* Function created by Gustavo Bacagine
 * 
 * It shows the 10 first lines
 * of a file */
int head(const char *file);

/* Function created by Gustavo Bacagine
 * 
 * It shows the 10 last lines
 * of a file */
//int tail(const char *file);

/* Function created by Gustavo Bacagine
 * 
 * It copies the content of a file
 * to the other */
int cp(const char *ori, const char *dest);

/* Function created by Gustavo Bacagine
 * 
 * It clears the terminal (similar to the linux
 * clear command) */
void clear(void);

/* Function created by Gustavo Bacagine
 * 
 * It creat a directory with permissions escolhida
 * pelo developer.
 * Received como 1º argument a string vector with the name of directories,
 * como 2º argument the number of umask and como 3º the quantidade */
void mkfolders(const char folder[][MAX_FILE_LEN], const int umask, const int qtd);

/* Function created by Gustavo Bacagine
 * 
 * It search a word in a file
 * Received como 1º argument the word a ser
 * procurada and como 2º the file onde será
 * procurada. */
int grep(const char *word, const char *file);

/* Function created by Gustavo Bacagine
 * 
 * Ela move um arquivo para outro lugar, ela
 * pode ser usada também para renomear arquivos.
 * Recebe como 1º argumento o nome do arquivo
 * e como 2º o destino para onde ele deve ser 
 * movido. */
int mv(const char *ori, const char *dest);

/* Function created by Gustavo Bacagine
 * 
 * Remove varios arquivos e diretorios
 * vazios */
void rm(const char arqs[][MAX_FILE_LEN], const int qtd);

/* Function created by Gustavo Bacagine
 * 
 * Recebe uma string como parametro
 * e cria um arquivo com o nome da
 * string passada */
int touch(const char *str);

/* Function created by Gustavo Bacagine
 * 
 * Ela inverte os valores de x e y */
void swap(int *x, int *y);

/* Função criada pela professora Andreia Machion
 * e modificada por Gustavo Bacagine
 * 
 * Uma forma alternativa para ler uma string
 * digitada pelo usuario */
void rstr(char *str, int length);

/* Function created by Gustavo Bacagine
 * 
 * Armazena o valor de uma string em
 * uma variavel apartir de um arquivo
 * ou da entrada especificada */
void frstr(char *str, int length, FILE *__stream);

/* Function created by 
 * Gustavo Bacagine
 * 
 * Ela é usada para mostrar
 * os desenvolvedores da 
 * aplicação */
/*void developers(const int qtd, const char names[][MAX_NAME_LEN], 
                const char emails[][MAX_NAME_LEN], int year, 
                const char *university, const char *city, 
                const char *desc);*/

#endif // _FATEC_H
