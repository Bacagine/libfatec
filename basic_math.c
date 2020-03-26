/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/fatec                                     *
 *                                                                                *
 * Copyright (C) 2019 - 2020                                                      *
 *                                                                                *
 * basic_math.c: Arquivo com o desenvolvimento das funções básicas de matematicas *
 * da biblioteca fatec.h                                                          *
 *                                                                                *
 * fatec.c é um software livre; você pode redistribui-lo e/ou modificalo sob os   *
 * termos da Licença GNU Lesser General Public publicada pela Free Software       *
 * Foundation; ou versão 2 da licença ou (a seu critério) qualquer                *
 * versão posterior.                                                              *
 *                                                                                *
 * Você deve ter recebido uma copia da Licença GNU Lesser General Public junto    *
 * com o fatec.c; caso contrario, veja: <http://www.gnu.org/licenses/>.           *
 *                                                                                *
 * Desenvolvedores: Gustavo Bacagine          <gustavo.bacagine@protonmail.com>   *
 *                  José Eduardo              <joseeduardoolimpio@gmail.com>      *
 *                  Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com> *
 *                  Caio Elias Emerick Regino <caioregino.147@gmail.com>          *
 *                  Luiz Dionizio             <luizgdsoares@hotmail.com>          *
 *                  Profº Ciro Cirne Trindade <ciroct@gmail.com>                  *
 *                                                                                *
 * Data: 21/02/2020                                                               *
 * Data da última modificação: 21/02/2020                                         *
 **********************************************************************************/

#include <stdio.h>
#include "fatec.h"

int Isoma(int n1, int n2){
    int soma;
    
    soma = n1 + n2;
    
    return soma;
}

int Isubtracao(int n1, int n2){
    int sub;
    
    sub = n1 - n2;
    
    return sub;
}

int Imultiplicacao(int n1, int n2){
    int mult;
    
    mult = n1 * n2;
    
    return mult;
}

int Idivisao(int n1, int n2){
    int div;
    
    div = n1 / n2;
    
    return div;
}

int Fsoma(float n1, float n2){
    float soma;
    
    soma = n1 + n2;
    
    return soma;
}


int Fsubtracao(float n1, float n2){
    float sub;
    
    sub = n1 - n2;
    
    return sub;
}

int Fmultiplicacao(float n1, float n2){
    float mult;
    
    mult = n1 * n2;
    
    return mult;
}


int Fdivisao(float n1, float n2){
    float div;
    
    div = n1 / n2;
    
    return div;
}

int Dsoma(double n1, double n2){
    double soma;
    
    soma = n1 + n2;
    
    return soma;
}


int Dsubtracao(double n1, double n2){
    double sub;
    
    sub = n1 - n2;
    
    return sub;
}

int Dmultiplicacao(double n1, double n2){
    double mult;
    
    mult = n1 * n2;
    
    return mult;
}


int Ddivisao(double n1, double n2){
    double div;
    
    div = n1 / n2;
    
    return div;
}
