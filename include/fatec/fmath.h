/* Git Hub: https://github.com/Bacagine/fatec
 * 
 * Copyright (C) 2019 - 2020
 * 
 * my_math.h: Biblioteca criada pelos alunos de ADSM
 * contendo o prototipo de funções usadas para calculos
 * matematicos
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
 * Desenvolvedor: Gustavo Bacagine          <gustavo.bacagine@protonmail.com>
 * 
 * Data de ínicio: 20/07/2020
 * Data da última modificação: 17/08/2020
 */

#ifndef _FMATH_H
#define _FMATH_H

#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3.1415

/* Structure created by professor Ciro Cirne Trindade
 * 
 * represents a point */
typedef struct{
    int x;
    int y;
} point;

/* Function created by Gustavo Bacagine.
 *
 * Essa função soma dois numeros inteiros */
int soma(int n1, int n2);

/* Function created by Gustavo Bacagine.
 *
 * Essa função subtração dois numeros inteiros */
int subtracao(int n1, int n2);

/* Function created by Gustavo Bacagine.
 *
 * Essa função multiplicação dois numeros inteiros */
int multiplicacao(int n1, int n2);

/* Function created by Gustavo Bacagine.
 *
 * Essa função divide dois numeros inteiros */
int divisao(int n1, int n2);

/* Function created by Gustavo Bacagine.
 *
 * Essa função soma dois numeros do tipo ponto flutuante */
float fsoma(float n1, float n2);

/* Function created by Gustavo Bacagine.
 *
 * Essa função subtração dois numeros numeros do tipo ponto flutuante */
float fsubtracao(float n1, float n2);

/* Function created by Gustavo Bacagine.
 *
 * Essa função multiplicação dois numeros numeros do tipo ponto flutuante */
float fmultiplicacao(float n1, float n2);

/* Function created by Gustavo Bacagine.
 *
 * Essa função divide dois numeros numeros do tipo ponto flutuante */
float fdivisao(float n1, float n2);

/* Function created by Gustavo Bacagine.
 *
 * Essa função soma dois numeros do tipo double */
double dsoma(double n1, double n2);

/* Function created by Gustavo Bacagine.
 *
 * Essa função subtração dois numeros numeros do tipo double */
double dsubtracao(double n1, double n2);

/* Function created by Gustavo Bacagine.
 *
 * Essa função multiplicação dois numeros numeros do tipo double */
double dmultiplicacao(double n1, double n2);

/* Function created by Gustavo Bacagine.
 *
 * Essa função divide dois numeros numeros do tipo double */
double ddivisao(double n1, double n2);

/* Function created by Gustavo Bacagine.
 * 
 * Essa função faz um calculo de um número fatorial
 * de maneira recursiva */
long long fatorial(int n);

/* Function created by Gustavo Bacagine
 * 
 * Essa função funciona semelhante à função pow
 * calculando o expoente (e) de um número (n) */
int my_pow(int n, int e);

/* Function created by Gustavo Bacagine
 * 
 * Essa função transforma um número
 * binario em decimal */
//int bin2dec(const int bin);

/* Function created by Gustavo Bacagine
 * 
 * Essa função transforma um número
 * decimal em binario */
//int dec2bin(const int dec);

/* Function created by Gustavo Bacagine
 * 
 * Calcula a area de uma esfera */
int area(int raio);

/* Function created by Gustavo Bacagine
 * 
 * Calcula o volume de uma esfera */
int volume_esfera(int raio);

// Lista 5 Ponteiros 2019 2º Semestre

/* Function created by Gustavo Bacagine and José Eduardo.
 *
 * Essa função transforma o tempo digitado pelo usuario em
 * segundos para o formato 00h:00min:00s */
void transforma_segundos(int, int *, int *, int *);

/* Function created by Gustavo Bacagine and José Eduardo.
 *
 * Essa função calcula o diâmetro, perímetro e área de uma 
 * circunferência. */
void circunferencia(float, float *,float *,float *);

/* Function created by Gustavo Bacagine and José Eduardo.
 *
 * Essa função recebe como parâmetro uma distância 
 * em metros a devolve, também através de seus parâmetros,
 * essa distância em polegadas, jardas e milhas. */
void converte(float, double *, double *, double *);

/* Function created by professor Ciro Cirne Trindade.
 *
 * Essa função recebe o tamanho de um arquivo em bytes e devolve 
 * o tamanho desse arquivo em KB e MB. */
void file_size(int, float *, float *);

/* Function created by professor Ciro Cirne Trindade.
 *
 * Essa função pega uma sequência de n 
 * números inteiros e os imprime em ordem
 * inversa. */
//void inverse_num(int *nums);

/* Function created by Gustavo Bacagine
 * 
 *  */
void bhaskara(double *x1, double *x2, double a, double b, double c);

/* Function created by Gustavo Bacagine
 * 
 *  */
double hipotenusa(const double cat1, const double cat2);

/* Function created by Gustavo Bacagine
 * 
 * Calcula o Maximo Divisor Comum entre
 * dois numeros inteiros */
int mdc(int n1, int n2);

/* Function created by Gustavo Bacagine
 * 
 * Calcula o Peso Ideal de uma pessoa
 * Recebe como 1º argumento a altura e
 * como 2º o sexo da pessoa */
double imc(const double height, const char sexo);

/* Function created by Gustavo Bacagine
 * 
 * This function  */
int permutation(int n);

/* Function created by Gustavo Bacagine
 * 
 * This function  */
int arranjos(int n, int k);

/* Function created by Gustavo Bacagine
 * 
 * This function  */
int combinacao(int n, int k);

/* Function created by Gustavo Bacagine
 * 
 * Verifica se um numero é primo ou não */
int primo(int n);

/* Function created by Gustavo Bacagine
 * 
 * This function  */
double my_sqrt(double n);

#endif // _FMATH_H
