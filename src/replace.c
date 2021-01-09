/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/fatec                                     *
 *                                                                                *
 * Copyright (C) 2019 - 2020                                                      *
 *                                                                                *
 * replace.c: Arquivo com o desenvolvimento do prototipo da função replace usada  *
 * no 1º Trabalho de Línguagem de Programação encontradas na biblioteca fatec.h   *
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
 * Data da última modificação: 17/02/2020                                         *
 **********************************************************************************/

#include "../include/fatec/str.h"

void replace(String txt, int i, const String str){
    char aux[strlen(txt)];
    
    int count;
    
    /* Copy all text before index
     * that will modified */
    for(count = 0; count < i; count++){
        aux[count] = txt[count];
    }
    aux[count] = '\0';
        
    strcat(aux, str);
    
    /* IMPORTANT: DON'T MODIFIED THIS PART OF CODE! IT IS WORKING  */
    for(count = strlen(aux); count < strlen(txt)+strlen(str); count++){
        aux[count] = txt[count-strlen(str)+1];
    }
    
    strcpy(txt, aux);
}
