/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/fatec                                     *
 *                                                                                *
 * Copyright (C) 2019 - 2020                                                      *
 *                                                                                *
 * Trab01.c: Arquivo com o desenvolvimento do prototipo das funções usadas no 1º  *
 * Trabalho de Línguagem de Programação encontradas na biblioteca fatec.h         *
 *                                                                                *
 * Esse arquivo fonte é um software livre; você pode redistribui-lo e/ou          *
 * modificalo sob os termos da Licença GNU Lesser General Public publicada pela   *
 * Free Software Foundation; ou versão 2 da licença ou (a seu critério) qualquer  *
 * versão posterior.                                                              *
 *                                                                                *
 * Você deve ter recebido uma copia da Licença GNU Lesser General Public junto    *
 * com o fatec.h; caso contrario, veja: <http://www.gnu.org/licenses/>.           *
 *                                                                                *
 * Desenvolvedores: Gustavo Bacagine          <gustavo.bacagine@protonmail.com>   *
 *                  José Eduardo              <joseeduardoolimpio@gmail.com>      *
 *                  Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com> *
 *                  Caio Elias Emerick Regino <caioregino.147@gmail.com>          *
 *                  Luiz Dionizio             <luizgdsoares@hotmail.com>          *
 *                  Profº Ciro Cirne Trindade <ciroct@gmail.com>                  *
 *                                                                                *
 * Data: 02/12/2019                                                               *
 * Data da última modificação: 25/12/2019                                         *
 **********************************************************************************/

#include <stdio.h>
#include "fatec.h"

void italico(char *str){ // função que converte os atalhos de itálico do texto passado \
                           como argumentos para as tags HTML <i> e </i>
    int i;        // indice da string
    int num = 1; // usado para verificar quando ocorre a primeira ocorrencia dos caracteres '_' e '*'

        i = 0;
        while(str[i] != '\0'){   // percorre a string
            if (str[i] == '_'){ // e procura pelo sinal de '_'
                num++; // Quando meu caracter for '_' num será igual a dois \
                                        isso serve para que eu possa saber quando o caracter '_' \
                                        aparece pela primeira e segunda vez no terminal

                if(num %2 == 0){
                    replace(str, i, "<i>"); // substitui o sinal de '_' pela tag <i>
                    i+=2;                  // --> não percorre os caracteres 'i' e '>' após a substituição
                }
                else if(num %2 != 0){
                    replace(str, i, "</i>"); // substitui o sinal de '_' pela tag </i>
                    i+=2;
                }
            }
        i++;
        }
}

void negrito(char *str){ // função que converte os atalhos de negrito do texto passado \
                           como argumentos para as tags HTML <b> e </b>
    int i; // indice da string
    int num = 1;

        i = 0;
        while(str[i] != '\0'){   // percorre a string
            if (str[i] == '*'){ // e procura pelo sinal de '*'
                num++; // Quando meu caracter for '*' num será igual a dois \
                                        isso serve para que eu possa saber quando o caracter '*' \
                                        aparece pela primeira e segunda vez no terminal

                if(num %2 == 0){             // caso o sinal apareça pela 1º vez
                    replace(str, i, "<b>"); // substitui o sinal de '*' pela tag <b>
                    i+=2;                  // --> não percorre os caracteres 'b' e '>' após a substituição
                }
                else if(num %2 != 0){         // caso o sinal apareça pela 2º vez
                    replace(str, i, "</b>"); // substitui o sinal de '*' pela tag </b>
                    i+=2;
                }
            }
        i++;
        }
}

