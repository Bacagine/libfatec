/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/fatec                                     *
 *                                                                                *
 * Copyright (C) 2019 - 2020                                                      *
 *                                                                                *
 * others.c: Arquivo com *
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
 * Data: 25/12/2019                                                               *
 * Data da última modificação: dd/mm/aaaa                                         *
 **********************************************************************************/

#include <stdio.h>
#include "fatec.h"

char *replaceWord(const char *str, const char *oldW, const char *newW){ 
    char *result; 
    int i, count = 0; 
    int newWlen = strlen(newW); 
    int oldWlen = strlen(oldW); 
  
    /* Counting the number of times old word 
     * occur in the string */
    for (i = 0; str[i] != '\0'; i++){ 
        if (strstr(&str[i], oldW) == &str[i]){ 
            count++; 
  
            // Jumping to index after the old word. 
            i += oldWlen - 1; 
        } 
    } 
  
    // Making new string of enough length 
    result = (char *)malloc(i + count * (newWlen - oldWlen) + 1); 
  
    i = 0; 
    while (*str){ 
        // compare the substring with the result 
        if (strstr(str, oldW) == str){ 
            strcpy(&result[i], newW); 
            i += newWlen; 
            str += oldWlen; 
        } 
        else
            result[i++] = *str++; 
    } 
  
    result[i] = '\0'; 
    return result; 
}
