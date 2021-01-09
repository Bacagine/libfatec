/* Git Hub: https://github.com/Bacagine/fatec
 * 
 * Copyright (C) 2019 - 2021
 * 
 * data.h: Biblioteca criada pelos alunos de ADSM
 * contendo o prototipo de funções e estruturas usadas
 * para manipulação de datas
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
 * Desenvolvedores: Gustavo Bacagine          <gustavo.bacagine@protonmail.com>
 *                  Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com>
 * 
 * Data de ínicio: 20/07/2020
 * Data da última modificação: 09/01/2021
 */

#ifndef _FDATE_H
#define _FDATE_H

#include <time.h>
#include <stdbool.h>
#include <fatec/fatec.h>

/* Structure created by Gustavo Bacagine
 * 
 * It represents a date */
typedef struct{
    int day;
    int month;
    int year;
} date;

/* Function created by Gustavo Bacagine and
 * Lucas Pereira de Matos
 * 
 * This function returns a negative value
 * if the first date for menor que a second,
 * 0 if as duas dates são iguais, or a positive
 * value if the first date for maior que 
 * the second */
int compara_datas(date dt1, date dt2);

/* Function created by Gustavo Bacagine
 * 
 * Essa função compara se as duas datas
 * passadas pelo usuário são iguais ou
 * não. */
boolean datas_iguais(date dt1, date dt2);

/* Function created by Gustavo Bacagine
 * 
 * This function verify if year is a 
 * leap year or not. Return 0 in positive
 * case or 1 in negative case */
int leap_year(int year);

/* Function created bu Gustavo Bacagine
 * 
 * This function verify
 * if a day is valid or
 * not */
int valida_dia(date dt);

/* Função criada por Gustavo Bacagine
 * 
 * Essa função verifica se um valor
 * dado para um mês é valido e,
 * retorna 0 em caso positivo ou
 * 1 em caso negativo */
int valida_mes(int month);

/* Function created by Gustavo Bacagine
 * 
 * This function verify if year is valid.
 * Return 0 in positive case or 1 in
 * negative case */
int valida_ano(int year);

/* Função criada por Gustavo Bacagine
 * 
 * Recebe uma data e verifica se ela é
 * valida. Retorna 0 caso seja valida ou
 * 1 caso seja inválida */
int valida_data(date dt);

/* Function created by Gustavo Bacagine
 * 
 * Essa função faz uma listagem entre
 * o periodo das duas datas passadas
 * como argumentos. */
//void listar_por_data(date , date);

/* Function created by professor Ciro Cirne Trindade.
 *
 * Essa função recebe uma data no formato ddmmaaaa, 
 * e devolve o dia, o mês e o ano separadamente. */
void separa_data(int, int *, int *, int *);

/* Function created by Gustavo Bacagine
 * 
 * This function get a date of system */
void get_date(int *day, int *month, int *year);

/* Function created by Gustavo Bacagine
 * 
 * This function get a time of system */
void get_time(int *hour, int *minute, int *second);

#endif // _FDATE_H
