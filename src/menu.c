/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/fatec                                     *
 *                                                                                *
 * Copyright (C) 2019 - 2020                                                      *
 *                                                                                *
 * menu.c: Arquivo com o menu da aplicação fatec.h                                *
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

void menu(void){
    setlocale(LC_ALL, "Portuguese"); // Permite o uso de acentuações e caracteres especiais
    
    int op; // Opção a ser escolhida pelo usuário
    
    system("clear"); // Limpa o terminal
    do{
        printf("************************************\n");
        printf("*       BEM VINDO AO FATEC.H       *\n");
        printf("************************************\n");
        printf("* 1) Sobre                         *\n");
        printf("* 2) Licença                       *\n");
        printf("* 3) Desenvolvedores               *\n");
        printf("* 4) Sair                          *\n");
        printf("************************************\n");
        scanf("%d", &op);
        
        switch(op){
            case 1:
                sobre();                           // Informações sobre a aplicação
                break;
            case 2:
                license();                      // Mostra a licença da aplicação
                break;
            case 3:
                developers();                // Mostra os desenvolvedores da aplicação
                break;
            case 4:
                system("clear");          // Limpa o terminal antes de sair da aplicação
                printf("Tchau Programador...\n\n");  // Da tchau ao usuário
                break;
            default:
                system("clear");      // Limpa o termianl
                puts(ERROR);         // Exibe uma mensagem de erro
                getchar();          // Pausa a mensagem de erro no terminal
                clear_buffer();    // Limpa o buffer caso o usuário digite algo
                system("clear");  // Limpa o termianl antes de voltar para o menu
            
        }
    } while(op != 4); /* Enquanto o usuário não 
                       * digitar o número 4 
                       * será exibido o menu */
}

void sobre(void){
    FILE *arq;
    char ch;
    
    if((arq = fopen("README.md", "r")) == NULL){
        system("clear");
        fprintf(stderr, "ERRO!");
        clear_buffer();
        getchar();
        system("clear");
    }
    
    system("clear");
    while ((ch = fgetc(arq)) != EOF) {
		fputc(ch, stdout);
	}
	clear_buffer();
    getchar();
    system("clear");
    
    fclose(arq);
}

void license(void){
    FILE *arq;
    char ch;
    
    if((arq = fopen(LICENSE, "r")) == NULL){
        system("clear");
        fprintf(stderr, "ERRO!");
        clear_buffer();
        getchar();
        system("clear");
    }
    
    system("clear");
    while ((ch = fgetc(arq)) != EOF){
		fputc(ch, stdout);
	}
	clear_buffer();
    getchar();
    system("clear");
    
    fclose(arq);
}
