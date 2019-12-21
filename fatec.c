/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/fatec                                     *
 *                                                                                *
 * Copyright (C) 2019                                                             *
 *                                                                                *
 * fatec.c: Biblioteca com o prototipo das funções e com estruturas que foram     *
 * usadas no primeiro ano do curso de ADSM                                        *
 * 
 * fatec.c is free software; you can redistribute it and/or modify it under the   *
 * terms of the GNU Lesser General Public License as published by the Free        *
 * Software Foundation; either version 2 of the License, or (at your option) any  *
 * later version.                                                                 *
 * 
 * You should have received a copy of the GNU Lesser General Public License along *
 * with the GNU C Library; if not, see <http://www.gnu.org/licenses/>.            *
 *                                                                                *
 * Desenvolvedores: Gustavo Bacagine          <gustavo.bacagine@protonmail.com>   *
 *                  José Eduardo              <joseeduardoolimpio@gmail.com>      *
 *                  Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com> *
 *                  Caio Elias Emerick Regino <caioregino.147@gmail.com>          *
 *                  Luiz Dionizio             <luizgdsoares@hotmail.com>          *
 *                  Profº Ciro Cirne Trindade <ciroct@gmail.com>                  *
 *                                                                                *
 * Data: 02/12/2019                                                               *
 * Data da última modificação: 21/12/2019                                         *
 **********************************************************************************/

#include <stdio.h>
#include "fatec.h"

void clear_buffer(void){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

void menu(void){
    
    setlocale(LC_ALL, "Portuguese"); // Permite o uso de acentuações e caracteres especiais
    
    int op; // Opção a ser escolhida pelo usuário
    
    system("clear"); // Limpa o terminal
    do{
        printf("*************MENU*************\n");
        printf("* 1) Opção 1                 *\n");
        printf("* 2) Opção 2                 *\n");
        printf("* 3) Desenvolvedores         *\n");
        printf("* 4) Sair                    *\n");
        printf("******************************\n");
        scanf("%d", &op);
        
        switch(op){
            
            case 1:
                //function_1();                  //
                break;
            case 2:
                //function_2();               //
                break;
            case 3:
                developers();              // Mostra os desenvolvedores da aplicação
                break;
            case 4:
                system("clear");        // Limpa o terminal antes de sair da aplicação
                break;
            default:
                system("clear");     // Limpa o termianl
                puts(ERROR);        // Exibe uma mensagem de erro
                getchar();         // Pausa a mensagem de erro no terminal
                clear_buffer();   // Limpa o buffer caso o usuário digite algo
                system("clear"); // Limpa o termianl antes de voltar para o menu
            
        }
    } while(op != 4); // Enquanto o usuário não digitar o número x \
                         será exibido o menu
}

void replace(char *str, int index, const char *tag){
    
    char cptexto[101]; // Copia do texto digitado pelo usuario que não deve ser alterado
    int lentag;       // Tamanho da minha tag
    
    lentag = strlen(tag); // Atribui ao lentag a quantidade de caracteres \
                             que tem na minha variavel tag
    
    strcpy(cptexto, str + index + 1); // Atribui tudo o que vem depois do caracter encontrado \
                                         ('_' ou '*') a variavel cptexto; em outras palavras, copia \
                                         tudo que vem depois do caracteres '_' ou '*'
                                                                                          
    strcpy(str + index, tag);      // substitui o atalho pela tag no texto a partir da posição do caractere de atalho
    
    strcpy(str + index + lentag, cptexto); // copia o texto para printalo no terminal depois da tag ter substituido o atalho
}

void cadastrar_cliente(void){
     
    setlocale(LC_ALL, "Portuguese"); // Permite o uso de acentuações e caracteres especiais
    
    FILE *arq;       // Declarando uma variavel de arquivo
    cliente client; //  Declarando uma estrutura do tipo cliente
    
    if((arq = fopen(ARQ_CLIENTE, "ab")) == NULL) {
        system("clear");     // Limpa o terminal ao entrar aqui
        fprintf(stderr, "Erro: não foi possível abrir o arquivo clientes.dat!\n");
        getchar();         // Pausa a mensagem de erro no terminal
        clear_buffer();   // Limpa o buffer
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    fseek(arq, 0, SEEK_END); // Desloca o indicador de posição para o final do arquivo
    
    client.codigo_cliente = ftell(arq) / sizeof(cliente) + 1; /* Pega o número atual de 
                                                               * clientes cadastradas em bytes
                                                               * divide pelo tamanho da estrutura 
                                                               * clientes em bytes e soma + 1 */
    system("clear"); // Limpa o terminal quando o usuario escolhe a opção Cadastrar Clientes
    fprintf(stdout, "********Novo Cliente********\n");
    fprintf(stdout, "Codigo do cliente: %d\n", client.codigo_cliente); // Mostra o código do cliente que será cadastrado
    fprintf(stdout, "Nome do cliente: ");
    scanf(" %50[^\n]", client.nome_cliente);
    fprintf(stdout, "Número de telefone: ");
    scanf(" %14[^\n]", client.telefone);
    
    fwrite(&client, sizeof(cliente), 1, arq);
    fclose(arq);            // Fecha o arquivo clientes.dat
    
    system("clear");      // Limpa o terminal ao termino do cadastro do cliente
    puts(CLIENT_SUCESS); // Mostra a mensagem que foi definida em CLIENT_SUCESS
    getchar();          /* Pausa a mensagem que está definida em
                         * CLIENT_SUCESS no terminal */
    clear_buffer();   // Limpa o buffer
    system("clear"); // Limpa o terminal antes de voltar para o menu
}

void listar_clientes(void){
    
    setlocale(LC_ALL, "Portuguese"); // Permite o uso de acentuações e caracteres especiais
    
    FILE *arq;       // Declarando uma variavel de arquivo
    cliente client; //  Declarando uma estrutura do tipo cliente
    
    if((arq = fopen(ARQ_CLIENTE, "rb")) == NULL) {
        system("clear");      // Limpa o terminal ao entrar aqui
        puts(NOT_CLIENT);    // Mostra a mensagem que foi definida em NOT_CLIENT
        getchar();          /* Pausa a mensagem que está definida em
                             * NOT_CLIENT no terminal */
        clear_buffer();   // Limpa o buffer
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }

    /* CONTEUDO COM OS CLIENTES CADASTRADOS */
    system("clear"); // Limpa o terminal antes de mostrar os clientes cadastrados
    fprintf(stdout, "\t\t\tClientes Cadastrados\n");
    fprintf(stdout, "*****************************************************************************\n");
    fprintf(stdout, "#Código     Nome do Cliente                                     Telefone\n");
    fprintf(stdout, "*****************************************************************************\n");
    while (fread(&client, sizeof(cliente), 1, arq) > 0) {
            fprintf(stdout, "%06d      %-50.50s %+14.14s\n", client.codigo_cliente,
                                                             client.nome_cliente,
                                                             client.telefone);
    }
    fprintf(stdout, "*****************************************************************************\n");
    fclose(arq);            // Fecha o arquivo clientes.dat
    
    getchar();            /* Pausa o arquivo de cadastros 
                           * no terminal para que o usuario
                           * possa ver as compras cadastradas */
    clear_buffer();    // Limpa o buffer
    system("clear");  // Limpa o terminal antes de voltar para o menu
}

void consultar_cliente(void){
    
    setlocale(LC_ALL, "Portuguese"); // Permite o uso de acentuações e caracteres especiais
    
    FILE *arq;       // Declarando uma variavel de arquivo
    cliente client; //  Declarando uma estrutura do tipo cliente
    int count;
    
    char nome_cliente[51];
    
    system("clear"); // Limpa o terminal ao entrar aqui
    
    fprintf(stdout, "********Consultar Cliente********\n");
    fprintf(stdout, "Digite o nome do cliente: ");
    scanf(" %50[^\n]", nome_cliente);
    
    if((arq = fopen(ARQ_CLIENTE, "rb")) == NULL) {
        system("clear");      // Limpa o terminal ao entrar aqui
        puts(NOT_CLIENT);    // Mostra a mensagem que foi definida em NOT_CLIENT
        getchar();          /* Pausa a mensagem que está definida em
                             * NOT_CLIENT no terminal */
        clear_buffer();   // Limpa o buffer
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    
    system("clear"); // Limpa o terminal
    fprintf(stdout, "*****************************************************************************\n");
    fprintf(stdout, "#Código     Nome do Cliente                                     Telefone\n");
    fprintf(stdout, "*****************************************************************************\n");
    // Busca o nome digitado no arquivo clientes.dat
    count = 0;
    while(fread(&client, sizeof(cliente), 1, arq) > 0){
        if(strstr(client.nome_cliente, nome_cliente) != NULL){ //Compara o nome digitado com os que existem no arquivo
            //for(i = 0; nome_cliente[i] == ' '; i++){    
                fprintf(stdout, "%06d      %-50.50s %+14.14s\n", client.codigo_cliente,
                                                                 client.nome_cliente,
                                                                 client.telefone);
                count++;
            //}
        }
    }
    fprintf(stdout, "*****************************************************************************\n");
    
    // MENSAGEM DE ERRO CASO NÃO TENHA UM CLIENTE COM O NOME DIGITADO
    if(count == 0){
        system("clear");       // Limpa o terminal ao entrar aqui
        fprintf(stdout, "ERRO! Não há nenhum cliente cadastrado com esse nome\n");
    }
    
    fclose(arq);           // Fecha o arquivo clientes.dat
    
    getchar();           /* Pausa o arquivo de cadastros 
                          * no terminal para que o usuario
                          * possa ver as compras cadastradas */
    clear_buffer();   // Limpa o buffer 
    system("clear"); // Limpa o terminal antes de voltar para o menu
}

void cadastrar_compra(void){
    
    setlocale(LC_ALL, "Portuguese"); // Permite o uso de acentuações e caracteres especiais
    
    FILE *arq_cliente, *arq_compra;         // Declarando uma variavel de arquivo
    cliente client; //  Declarando uma estrutura do tipo cliente
    compra buy;       // Declarando uma estrutura do tipo compra
    data date;       // Declarando uma estrutura do tipo data
    int count;
    
    if((arq_compra = fopen(ARQ_COMPRA, "ab")) == NULL) {
        //system("cls");       // Limpa o terminal ao entrar aqui no Windows
        system("clear");      // Limpa o terminal ao entrar aqui
        fprintf(stderr, "Erro: não foi possível abrir o arquivo compras.dat!\n");
        getchar();          // Pausa a mensagem de erro no terminal
        clear_buffer();    // Limpa o buffer
        //system("cls");  // Limpa o terminal antes de voltar para o menu no Windows
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    fseek(arq_compra, 0, SEEK_END); // Desloca o indicador de posição para o final do arquivo
    
    buy.numero_compra = ftell(arq_compra) / sizeof(compra) + 1; /* Pega o número atual de 
                                                          * compras cadastradas em bytes
                                                          * divide pelo tamanho da estrutura 
                                                          * compra em bytes e soma + 1 */
//     system("cls");  // Limpa o terminal quando o usuario escolhe a opção Cadastrar Compras no Windows
    system("clear");  // Limpa o terminal quando o usuario escolhe a opção Cadastrar Compras
    fprintf(stdout, "********Nova Compra********\n");
    fprintf(stdout, "Número da compra: %d\n", buy.numero_compra); // Mostra o Número da compra que será cadastrada
    fprintf(stdout, "Código do cliente: ");
    scanf("%d", &buy.codigo_cliente);
    
    if((arq_cliente = fopen(ARQ_CLIENTE, "rb")) == NULL) {
//         system("cls");      // Limpa o terminal ao entrar aqui no Windows
        system("clear");      // Limpa o terminal ao entrar aqui
        fprintf(stderr, "Erro: não nenhum cliente cadastrado!\n");
        getchar();          // Pausa a mensagem de erro no terminal
        clear_buffer();    // Limpa o buffer
//         system("cls"); // Limpa o terminal antes de voltar para o menu
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    
    // NÃO SEI COMO ARRUMAR ISSO
    while (fread(&client, sizeof(cliente), 1, arq_cliente) > 0){
        if(client.codigo_cliente == buy.codigo_cliente){
            printf("\n%s\n\n", client.nome_cliente);
            printf("Data da compra\n");
            printf("--------------\n");
            printf("Dia: ");
            scanf("%d", &buy.dt_compra.dia);
            printf("Mês: ");
            scanf("%d", &buy.dt_compra.mes);
            printf("Ano: ");
            scanf("%d", &buy.dt_compra.ano);
            printf("Valor da compra: R$ ");
            scanf("%f", &buy.valor);
            
            while(buy.valor <= 0){
                fprintf(stderr, "Valor inválido!\n");
                fprintf(stderr, "Por favor, digite um número maior que 0:\n");
                printf("\nValor da compra: R$ ");
                scanf("%f", &buy.valor); 
            }
            
            fwrite(&buy, sizeof(compra), 1, arq_compra);
            fclose(arq_compra);             // Fecha o arquivo compras.dat
            system("clear");      // Limpa o terminal após o termino do cadastrado da compra
            puts(BUY_SUCESS);    // Mostra a mensagem que foi definida em BUY_SUCESS
            getchar();         /* Pausa a mensagem que está definida em
                                * BUY_SUCESS no terminal */
            clear_buffer();     // Limpa o buffer
            system("clear"); // Limpa o terminal antes de voltar para o menu
        }
    }
    if(client.codigo_cliente != buy.codigo_cliente){
            system("clear");
            printf("Não existe nenhum cliente com esse código\n");
            printf("Compra interrompida!\n");
//             fclose(arq_cliente);
            getchar();
            clear_buffer();
           system("clear");
    }
    
    fclose(arq_cliente);
}

void listar_compras_data(void){
    
}

bool datas_iguais(data, data){
    
}

void listar_compras_cliente(void){
    
    setlocale(LC_ALL, "Portuguese"); // Permite o uso de acentuações e caracteres especiais
    
    FILE *arq;         // Declarando uma variavel de arquivo
    compra buy;       // Declarando uma estrutura do tipo compra
    
    int cod_cliente;
    int count;
    
    system("clear");
    fprintf(stdout, "********Consultar Compra por Cliente********\n");
    fprintf(stdout, "Digite o código do cliente: ");
    scanf("%d", &cod_cliente);
    
    if((arq = fopen(ARQ_COMPRA, "rb")) == NULL) {
        system("clear");      // Limpa o terminal ao entrar aqui
        puts(NOT_BUY);       // Mostra a mensagem que foi definida em NOT_BUY
        getchar();          /* Pausa a mensagem que está definida em
                             * NOT_BUY no terminal */
        clear_buffer();   // Limpa o buffer
        system("clear"); // Limpa o terminal antes de voltar para o menu
        return;
    }
    
    system("clear");
        fprintf(stdout, "*******************************************************************************\n");
        fprintf(stdout, "#Número da compra     Código do Cliente           Valor              Data\n");
        fprintf(stdout, "*******************************************************************************\n");
    // Lê o arquivo e busca pelo nome digitado
    count = 0;
    while(fread(&buy, sizeof(compra), 1, arq) > 0){
        if((buy.codigo_cliente == cod_cliente) != 0){
            fprintf(stdout, "%06d                %06d                      %.2f\
             %02d/%02d/%02d\n", buy.numero_compra, buy.codigo_cliente, buy.valor,
                                buy.dt_compra.dia,buy.dt_compra.mes, buy.dt_compra.ano);
            
            count++;
        }
    }
    fprintf(stdout, "*******************************************************************************\n");
    
    if(count == 0){
        system("clear");
        fprintf(stdout, "ERRO! Não há nenhuma compra realizada por esse cliente\n");
    }
    
    fclose(arq);            // Fecha o arquivo compras.dat
    
    getchar();            /* Pausa o arquivo de cadastros 
                           * no terminal para que o usuario
                           * possa ver as compras cadastradas */
    clear_buffer();    // Limpa o buffer
    system("clear");  // Limpa o terminal antes de voltar para o menu
}

void developers(void){
    
    setlocale(LC_ALL, "Portuguese");

    system("clear"); // Limpa o terminal ao entrar aqui
    
    fprintf(stdout, "************************DESENVOLVEDORE(S)************************\n");    
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "* Instituição  -          Cidade                 -         aaaa *\n");
    fprintf(stdout, "*---------------------------------------------------------------*\n");
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "* Gustavo Bacagine          <gustavo.bacagine@protonmail.com>   *\n");
    fprintf(stdout, "* Nome                      <meu_email@algumacoisa.com>         *\n");
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "* Aqui deverá vir uma breve explicação sobre a aplicação        *\n");
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "*****************************************************************\n");
    
    getchar();         /* Pausa essa mensagem no terminal */
    clear_buffer();   // Limpa o buffer
    system("clear"); // Limpa o terminal antes de voltar para o menu

}
