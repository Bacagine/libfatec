/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/fatec                                     *
 *                                                                                *
 * Copyright (C) 2019 - 2020                                                      *
 *                                                                                *
 * developers.c: Arquivo com o que mostra os desenvolvedores da aplicação fatec.h *
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

void developers(void){
    
    setlocale(LC_ALL, "Portuguese_Brazil");

    system("clear"); // Limpa o terminal ao entrar aqui
    
    fprintf(stdout, "************************DESENVOLVEDORE(S)************************\n");    
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "* FATEC  -                Carapicuíbe            -         2019 *\n");
    fprintf(stdout, "*---------------------------------------------------------------*\n");
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "* Gustavo Bacagine          <gustavo.bacagine@protonmail.com>   *\n");
    fprintf(stdout, "* José Eduardo              <joseeduardoolimpio@gmail.com>      *\n");
    fprintf(stdout, "* Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com> *\n");
    fprintf(stdout, "* Caio Elias Emerick Regino <caioregino.147@gmail.com>          *\n");
    fprintf(stdout, "* Luiz Dionizio             <luizgdsoares@hotmail.com>          *\n");
    fprintf(stdout, "* Profº Ciro Cirne Trindade <ciroct@gmail.com>                  *\n");
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "* fatec.h é uma Biblioteca criada pelos alunos de ADSM contendo *\n");
    fprintf(stdout, "* o prototipo das funções e estruturas que foram usadas no      *\n");
    fprintf(stdout, "* primeiro ano do curso                                         *\n");
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "*****************************************************************\n");
    
    getchar();         /* Pausa essa mensagem no terminal */
    clear_buffer();   // Limpa o buffer
    system("clear"); // Limpa o terminal antes de voltar para o menu

}
