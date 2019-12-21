/* Git Hub: https://github.com/Bacagine/fatec
 * 
 * Copyright (C) 2019
 * 
 * fatec.h: Biblioteca criada pelos alunos de ADSM
 * contendo o prototipo das funções e estruturas que
 * foram usadas no primeiro ano do curso
 * 
 * fatec.h is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with the fatec.h; if not, see
 * <http://www.gnu.org/licenses/>.
 * 
 * Desenvolvedores: Gustavo Bacagine          <gustavo.bacagine@protonmail.com>
 *                  José Eduardo              <joseeduardoolimpio@gmail.com>
 *                  Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com>
 *                  Caio Elias Emerick Regino <caioregino.147@gmail.com>
 *                  Luiz Dionizio             <luizgdsoares@hotmail.com>
 *                  Profº Ciro Cirne Trindade <ciroct@gmail.com>
 * 
 * Data: 02/12/2019
 * Data da última modificação: 21/12/2019 */

#ifndef _FATEC_H
#define _FATEC_H

#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

/* Nome do arquivo aonde os clientes são cadastrados */
#define ARQ_CLIENTE "clientes.dat"

/* Nome do arquivo aonde as compras são cadastradas */
#define ARQ_COMPRA "compras.dat"

/* Mensagem de erro caso 
 * o usuario digite uma 
 * opção inválida */
#define ERROR "ERRO! Opção inválida!"

/* Mensagem a ser 
 * mostrada após o 
 * cadasto do cliente */
#define CLIENT_SUCESS "Cliente cadastrado com sucesso!" 

/* Mensagem a ser 
 * mostrada caso 
 * não haja nenhum
 * cliente cadastrado */
#define NOT_CLIENT "Erro! Não há nenhum cliente cadastrado!"

/* Mensagem a ser 
 * mostrada após o 
 * cadastro da compra */
#define BUY_SUCESS "Compra cadastrada com sucesso!" 

/* Mensagem a ser 
 * mostrada caso 
 * não haja nenhuma
 * compra cadastrada */
#define NOT_BUY "Erro! Não há nenhuma compra cadastrada!" 

/* Estrutura criada pelo professor
 * Ciro Cirne Trindade.
 * que representa um cliente */
typedef struct {
    int codigo_cliente;
    char nome_cliente[51];
    char telefone[15];
} cliente;

/* Estrutura criada pelo professor
 * Ciro Cirne Trindade.
 * que representa uma data */
typedef struct {
    int dia;
    int mes;
    int ano;
} data;

/* Estrutura criada pelo professor
 * Ciro Cirne Trindade.
 * que representa uma compra */
typedef struct {
    int numero_compra;
    int codigo_cliente; // código do cliente que realizou a compra
    float valor;
    data dt_compra;
} compra;

/* Função usada para evitar 
 * Buffer Overflow
 * 
 * OBS: Essa função não foi 
 * desenvolvida por nós. Percebemos 
 * que muitos programadores 
 * se utilizam dessa função e 
 * passamos a usa-lá em nossos programas */
void clear_buffer(void);

/* Função criada por 
 * Gustavo Bacagine */
void menu(void);

/* Função criado pelo Profº Ciro Cirne Trindade
 * 
 * Ela converte os atalhos de itálico do texto passado
 * como argumentos para as tags HTML <i> e </i> */
void italico(char *);

/* Função criado pelo Profº Ciro Cirne Trindade
 * 
 * Ela converte os atalhos de negrito do texto passado
 * como argumentos para as tags HTML <b> e </b> */
void negrito(char *);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * 
 * OBS: Nós não desenvolvemos essa função. Encontramos ela
 * no site: (colocar o link aqui mais tarde)
 * 
 * Essa função substitui o caractere da posição dada pelo 2o argumento
 * no texto dado pelo 1o argumento pela tag passada como 3o
 * argumento(<i>, </i>, <b> ou </b>) */
void replace(char *, int, const char *);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * E desenvolvida pelos alunos da FATEC de Carapicuíba
 * 
 * Essa função cadastra um novo cliente no arquivo clientes.dat */
void cadastrar_cliente(void);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * E desenvolvida pelos alunos da FATEC de Carapicuíba
 * 
 * Essa função exibe uma listagem no formato de tabela
 * mostrando o código, nome e telefone de todos os
 * clientes cadastrados */
void listar_clientes(void);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * E desenvolvida pelos alunos da FATEC de Carapicuíba
 * 
 * Essa função consulta os clientes por nome */
void consultar_cliente(void);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * E desenvolvida pelos alunos da FATEC de Carapicuíba
 * 
 * Essa função cadastra uma nova compra no arquivo compras.dat */
void cadastrar_compra(void);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * E desenvolvida pelos alunos da FATEC de Carapicuíba
 * 
 * Essa função lista todas as compras feitas em uma data
 * OBS: em andamento */
void listar_compras_data(void);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * E desenvolvida pelos alunos da FATEC de Carapicuíba
 * 
 * Essa função devolve verdadeiro se as duas datas passadas
 * como argumentos são iguais, ou falso, caso contrário.
 * Usada na função listar_compras_data()
 * OBS: em andamento */
bool datas_iguais(data, data);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * E desenvolvida pelos alunos da FATEC de Carapicuíba
 * 
 * Essa função lista todas as compras feitas por um cliente */
void listar_compras_cliente(void);

/* Função usada para mostrar
 * os desenvolvedores da 
 * aplicação */
void developers(void);

#endif
