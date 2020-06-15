/* Git Hub: https://github.com/Bacagine/fatec
 * 
 * Copyright (C) 2019 - 2020
 * 
 * fatec.h: Biblioteca criada pelos alunos de ADSM
 * contendo o prototipo das funções e estruturas que
 * foram usadas no primeiro ano do curso
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
 * Versão: 20.06.15
 * 
 * Desenvolvedores: Gustavo Bacagine          <gustavo.bacagine@protonmail.com>
 *                  José Eduardo              <joseeduardoolimpio@gmail.com>
 *                  Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com>
 *                  Caio Elias Emerick Regino <caioregino.147@gmail.com>
 *                  Luiz Dionizio             <luizgdsoares@hotmail.com>
 *                  Profº Ciro Cirne Trindade <ciroct@gmail.com>
 * 
 * Data de início: 02/12/2019
 * Data da última modificação: 18/05/2020 */

// Evita que a biblioteca seja incluida inumeras vezes
#ifndef _FATEC_H
#define _FATEC_H

#include <stdio.h>
#include <stdbool.h>     // Biblioteca usada para manipular variaveis booleanas
#include <locale.h>    /* Biblioteca para poder usar a função setlocale 
                        * usada para colocar acentuação nas palavras */
#include <math.h>    // Biblioteca para usar funções matematicas
#include <limits.h>
#include <string.h> // Biblioteca usada para manipular strings
//#include <strings.h>
#include <ctype.h>

// Verifica se o sistema é do tipo unix like
#ifdef __unix__
    #include <stdlib.h> // Biblioteca usada para ultilizar comandos do Sistema Operacional
    #define clear_terminal() system("clear");
	#define pause() printf("\nPrecione qualquer tecla para continuar..."); getchar();
// Verificar se o sistema é Windows ou se o programa foi compilado para Windows
#elif defined(_WIN32) || defined(WIN32) || defined(__MINGW32__) || defined(_MCS_VER)
    #include <stdlib.h>
    #define clear_terminal() system("cls");
#endif

/* A seguir definições usadas no trabalho 
 * do professor Ciro Cirne Trindade */

// Definições por Profº Ciro Cirne Trindade

/* Nome do arquivo aonde os clientes são cadastrados */
#define ARQ_CLIENTE "clientes.dat"

/* Nome do arquivo aonde as compras são cadastradas */
#define ARQ_COMPRA "compras.dat"

// Definições por Gustavo Bacagine

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

/* A seguir definições usadas nas aulas 
 * do professor Ciro Cirne Trindade */

/* Definição criada por Gustavo Bacagine
 * 
 * Nome do arquivo aonde os alunos são cadastrados */
#define ARQ_ALUNOS "alunos.txt"

/* Definição criada pelo professor
 * Ciro Cirne Trindade
 * 
 * Número de carros à ser cadastrados */
#define NUM_CARROS 20

/* Definição criada pelo professor
 * Ciro Cirne Trindade
 * 
 * Definindo um valor para constante PI */
#define PI 3.1415

/* Definição criada pelo professor
 * Ciro Cirne Trindade
 * 
 * Calculo de uma potência de 2 */
#define SQ(x) ((x) * (x))

/* Definição criada pelo professor
 * Ciro Cirne Trindade
 * 
 * Calculo da área */
#define AREA(x) (PI * SQ(x))

/* Definição criada pelo professor
 * Ciro Cirne Trindade
 * 
 * Printa o valor de x */
#define PRN(x) printf("%lf\n", x)

// Definições adicionais

/* Definição criada por Gustavo Bacagine
 * 
 * Diretorio onde se
 * encontra a lisença 
 * do software */
#define LICENSE "LICENSE"

/* A seguir estruturas usadas no trabalho 
 * do professor Ciro Cirne Trindade */

/* Estrutura criada pelo professor
 * Ciro Cirne Trindade.
 * 
 * Ela representa um cliente */
typedef struct {
    int codigo_cliente;
    char nome_cliente[51];
    char telefone[15];
} cliente;

/* Estrutura criada pelo professor
 * Ciro Cirne Trindade.
 * 
 * Ela representa uma data */
typedef struct {
    int dia;
    int mes;
    int ano;
} data;

/* Estrutura criada pelo professor
 * Ciro Cirne Trindade.
 * 
 * Ela representa uma compra */
typedef struct {
    int numero_compra;
    int codigo_cliente; // código do cliente que realizou a compra
    float valor;
    data dt_compra;
} compra;

/* A seguir estruturas usadas nas aulas 
 * do professor Ciro Cirne Trindade */

/*
 * Considere a estrutura struct circulo
 * definida anteriormente e escreva um
 * programa que dados dois círculos,
 * verifique se eles se sobrepõem. Dois
 * círculos se sobrepõem se a distância
 * entre os centros destes círculos é menor
 * que a soma de seus raios. Distância
 * entre dois pontos, (x 1 , y 1 ) e (x 2 , y 2 ):
 * 
 * d = √ ( x 1 − x 2 )^2 +( y 1 − y 2 )^2 */
struct ponto {
	int x;
	int y;
};

struct circulo {
	struct ponto centro;
	int raio;
};

/* Estrutura criada pelo professor
 * Ciro Cirne Trindade 
 * 
 * Ela representa um processador: frequência e fabricante. */
typedef struct {
	float frequencia;
	char fabricante[21];
} processador;
 
/* Estrutura criada pelo professor
 * Ciro Cirne Trindade 
 * 
 * Ela representam um monitor: tamanho, tipo (LCD, CRT, Plasma, Led)
 * e fabricante. */
typedef enum { LCD, CRT, PLASMA, LED } tipo_monitor;
typedef struct {
	int tamanho;
	tipo_monitor tipo;
	char fabricante[21];
} monitor;  
 
/* Estrutura criada pelo professor
 * Ciro Cirne Trindade 
 * 
 * Ela serve para representar um computador: processador, monitor, capacidade de
 * disco rígido e memória RAM. */
typedef struct {
	processador proc;
	monitor tela;
	int capacidade_hd;
	int ram;
} computador;

/* Estrutura criada pelo professor
 * Ciro Cirne Trindade 
 * 
 * Ela serve para o cadastro 
 * de funcionarios */
struct funcionario {
	char nome[41];
	int departamento;
	float salario;
};

/* Considere as declarações a seguir para representar o cadastro de alunos de uma
 * disciplina e implemente uma função que imprima o número de matrícula, o nome, a
 * turma e a média de todos os alunos aprovados na disciplina.
 * 
 * typedef struct {
 *  char nome[40];
 *  int matricula;
 *  char turma; 
 *  float provas[3];
 * } aluno;
 * 
 * Considere que o critério de aprovação é que a média aritmética das 3 provas seja
 * maior ou igual a 6.
 * A função deve receber como parâmetros o número de alunos da disciplina e um vetor com os
 * dados dos alunos. */
typedef struct {
	char nome[40];
	int matricula;
	char turma;
	float provas[3];
} aluno;

/* Seja uma estrutura para descrever os carros de uma determinada revendedora, contendo os
 * seguintes campos:
 * • marca : string de tamanho 20
 * • ano : inteiro
 * • cor : string de tamanho 10
 * • preco : real
 * a) Escrever a definição da estrutura carro .
 * b) Declarar o vetor vetcarros do tipo da estrutura definida acima, de tamanho 20.
 * Crie um menu para:
 * c) Cadastrar um carro no vetor vetcarros .
 * d) Listar todos os carros com preço menor ou igual a um valor fornecido pelo usuário;
 * e) Listar todos os carros de uma determinada marca fornecida pelo usuário; */

struct carro {
	char marca[21];
	int ano;
	char cor[11];
	float preco;
};

/* A seguir as funções mais usadas pelos alunos 
 * de ADSM da FATEC de Carapicuíba */

/* Função usada para evitar 
 * Buffer Overflow
 * 
 * Você pode se perguntar o motivo
 * para se usar uma função propia para
 * limpar o buffer do terminal ao invés
 * de usar uma função já pronta encontrada
 * na propia linguagem
 * 
 * Existem muitas funções que poderiamos
 * usar como: fflush(), setbuf(), etc...
 * 
 * O motivo para usarmos essa função está
 * no fato de que as funções listadas acima
 * não funcionam em todos os Sistemas Operacionais.
 * O fflush() funciona no Windows mas não funciona no
 * Linux e no MasOS; já o setbuf() funciona tanto no
 * Linux como no Windows, porém não funciona no MasOS.
 * 
 * Está função que usamos funciona em todos os
 * Sistemas Operacionais. Por isso achamos que essa seja
 * a melhor opção a ser usada.
 * 
 * OBS: Essa função não foi 
 * desenvolvida por nós. Percebemos 
 * que muitos programadores 
 * se utilizam dessa função e 
 * passamos a usa-lá em nossos programas */
void clear_buffer(void);

/* Função criada por 
 * Gustavo Bacagine
 * 
 * Ela printa um menu no terminal
 * Foi feita como um exemplo apenas pois,
 * o menu normalmente fica na função main.
 * Você pode usa-lá para criar seus propios menus*/
void menu(void);

/* Função criada por 
 * Gustavo Bacagine
 * 
 * Ela printa no terminal o conteudo
 * do arquivo README.md */
void sobre(void);

/* Função criada por 
 * Gustavo Bacagine
 * 
 * Ela printa no terminal a licença 
 * do software */
void license(void);

/* Função criado pelo Profº Ciro Cirne Trindade
 * 
 * Ela converte os atalhos de itálico do texto passado
 * como argumentos para as tags HTML <i> e </i> */
void italico(char *str);

/* Função criado pelo Profº Ciro Cirne Trindade
 * 
 * Ela converte os atalhos de negrito do texto passado
 * como argumentos para as tags HTML <b> e </b> */
void negrito(char *str);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * 
 * Essa função é baseada na função criada por isrnick
 * O código original pode ser encontrado em:
 * https://www.clubedohardware.com.br/forums/topic/1402340-substituir-um-car%C3%A1cter-por-uma-palavra-em-c/ 
 * 
 * Essa função substitui o caractere da posição dada pelo 2o argumento
 * no texto dado pelo 1o argumento pela tag passada como 3o
 * argumento */
void replace(char *str, int i, const char *newStr);

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
 * 
 * OBS: em andamento */
void listar_compras_data(void);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * E desenvolvida pelos alunos da FATEC de Carapicuíba
 * 
 * Essa função devolve verdadeiro se as duas datas passadas
 * como argumentos são iguais, ou falso, caso contrário.
 * Usada na função listar_compras_data()
 * 
 * OBS: em andamento */
bool datas_iguais(data, data);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * E desenvolvida pelos alunos da FATEC de Carapicuíba
 * 
 * Essa função lista todas as compras feitas por um cliente */
void listar_compras_cliente(void);

/* Função criada por 
 * Gustavo Bacagine
 * 
 * Ela é usada para mostrar
 * os desenvolvedores da 
 * aplicação */
void developers(void);

/* A seguir funções e estruturas usadas nas aulas 
 * e listas de exercicios do professor 
 * Ciro Cirne Trindade */

// Aula 1 Vetores e Matrizes

/* Função criada pelo Profº Ciro Cirne Trindade
 * 
 * Essa função cria uma matriz 4x6 através dos
 * valores passado pelo usuário */
void matriz(void);

/* Função criada pelo Profº Ciro Cirne Trindade
 * 
 * Essa função tratasse de um jogo de batalha
 * naval criado pelo professor Ciro Cirne Trindade 
 * para poder mostrar o uso de matrizes na línguagem
 * C */
void naval(void);

/* Função criada pelo Profº Ciro Cirne Trindade
 * 
 * Essa função simula um caixa eletronico e
 * mostra as notas sacadas pelo usuário 
 * de acordo com o valor desejado */
void notas(void);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função pega uma sequência de n 
 * números inteiros e os imprime em ordem
 * inversa. */
void inverse_num(void);

// Aula 2 Strings

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função receba uma string de 0s e 1s, interprete
 * essa string como um número binário e 
 * informe o valor desse número na base decimal. */
void binario_decimal(void);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função recebe n strings e determina quantas dessas 
 * strings contém uma string qualquer 
 * dada pelo usuário. */
void conta_str(void);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função receba uma string do teclado e 
 * informe quantas letras maiúsculas
 * ela possui. */
void maiusculas(void);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função receba uma string do teclado e informe se 
 * ela é palíndromo ou não. Uma string é 
 * palíndromo quando pode ser lida tanto de 
 * trás para frente quanto de frente para trás 
 * e possui exatamente a mesma sequência de 
 * caracteres. Por exemplo: “ASA”, “SUBI NO 
 * ONIBUS”.
 * 
 * OBS: Desconsidera os espaços. */
void palindromo(void);

// Aula 3 Funções

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função calcula a area de uma esfera */
void area(void);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função imprime uma matriz no terminal */
void imprime_matriz(int, int, int [][*]);
 
/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função cria uma matriz com os valores
 * recebidos pelo usuário */
void recebe_matriz(int, int, int [][*]);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função receba uma matriz A bidimensional
 * de valores reais e um valor real x,
 * e multiplique todos os elementos de A por x. */
 void multiplica_matriz(int, int, double (*)[*], double);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função calcula o dobro de um valor x */
void dobro(int);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função */
int maior(int, int);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função desenha no vídeo um retângulo 
 * formado por asteriscos (*) com a linhas de 
 * altura e c colunas de comprimento. Por exemplo, 
 * se for feita a seguinte chamada a função: retangulo(5, 10);
 * A função deve desenhar no vídeo o seguinte retângulo:
 * **********
 * **********
 * **********
 * **********
 * ********** */
void retangulo(int, int);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função recebe por parâmetro o raio de uma 
 * esfera (um int ) e calcula e devolve 
 * o seu volume ( 4PIR³/3). */
double volume(int);

// Aula 4 Modulos

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função devolve o fatorial de um número 
 * natural passado como argumento */
long long fatorial (int);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função devolve o número real passado como 
 * argumento arredondado para o inteiro mais próximo */
int arredondar_para_int (double);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função devolve o número real passado como 
 * 1o. argumento arredondado com uma precisão dada
 * pelo número inteiro passado como 2o. argumento da função */
double arredondar(double, int);

// Aula 5 Ponteiros

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função recebe uma data no formato ddmmaaaa, 
 * e devolve o dia, o mês e o ano separadamente. */
void separa_data(int, int *, int *, int *);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função recebe o tamanho de um arquivo em bytes e devolve 
 * o tamanho desse arquivo em KB e MB. */
void file_size(int, float *, float *);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função recebe um número decimal e o converte para binário. */
void dec2bin(int *);

// Lista 5 Ponteiros 2019 2º Semestre

/* Função criada por Gustavo Bacagine e José Eduardo.
 *
 * Essa função transforma o tempo digitado pelo usuario em
 * segundos para o formato 00h:00min:00s */
void transforma_segundos(int, int *, int *, int *);

/* Função criada por Gustavo Bacagine e José Eduardo.
 *
 * Essa função calcula o diâmetro, perímetro e área de uma 
 * circunferência. */
void circunferencia(float, float *,float *,float *);

/* Função criada por Gustavo Bacagine e José Eduardo.
 *
 * Essa função recebe como parâmetro uma distância 
 * em metros a devolve, também através de seus parâmetros,
 * essa distância em polegadas, jardas e milhas. */
void converte(float, double *, double *, double *);

// Aula 6 Estruturas

/* Função criada pelo Profº Ciro Cirne Trindade
 * 
 * Essa função serve para verificar se
 * um aluno foi aprovado ou reprovado */
void aprovados(int, aluno []);

/* Função criada pelo Profº Ciro Cirne Trindade
 *
 * Essa função serve para o cadastro de carros */
void cadastrar_carro(int *, struct carro []);

/* Função criada pelo Profº Ciro Cirne Trindade
 *
 * Essa função serve para listar os carros
 * cadastrados */
void listar_por_preco(int, struct carro[], float);

/* Função criada pelo Profº Ciro Cirne Trindade
 *
 * Essa função serve para listar os carros
 * cadastrados por marca */
void listar_por_marca(int, struct carro[], const char *);

// Aula 8 Arquivos

/* Função criada pelo Profº Ciro Cirne Trindade
 *
 * Essa função serve para o cadastro de alunos */
void cadastrar_aluno(void);
 
/* Função criada pelo Profº Ciro Cirne Trindade
 *
 * Essa função serve para listar os alunos
 * cadastrados */
void listar_alunos(void);

/* Função criada pelo Profº Ciro Cirne Trindade
 *
 * Essa função exibe um arquivo */
int exibe_arq(void);

/* A seguir algumas funções adicionais que não
 * foram usadas no curso mas que achamos interessante
 * adicionar */

/* Function created by Anuj Chauhan 
 * (geeksforgeeks.org/c-program-replace-word-text-another-given-word/)
 * 
 * This function replace a string with 
 * another string */
char *replaceWord(const char *str, const char *oldW, const char *newW);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função soma dois numeros inteiros */
int Soma(int n1, int n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função subtração dois numeros inteiros */
int Subtracao(int n1, int n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função multiplicação dois numeros inteiros */
int Multiplicacao(int n1, int n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função divide dois numeros inteiros */
int Divisao(int n1, int n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função soma dois numeros do tipo ponto flutuante */
int Fsoma(float n1, float n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função subtração dois numeros numeros do tipo ponto flutuante */
int Fsubtracao(float n1, float n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função multiplicação dois numeros numeros do tipo ponto flutuante */
int Fmultiplicacao(float n1, float n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função divide dois numeros numeros do tipo ponto flutuante */
int Fdivisao(float n1, float n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função soma dois numeros do tipo double */
int Dsoma(double n1, double n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função subtração dois numeros numeros do tipo double */
int Dsubtracao(double n1, double n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função multiplicação dois numeros numeros do tipo double */
int Dmultiplicacao(double n1, double n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função divide dois numeros numeros do tipo double */
int Ddivisao(double n1, double n2);


/* Função criada por Gustavo Bacagine.
 *
 * Essa função remove um cliente cadastrado no sistema */
void remover_cliente(void);

/* Função criada por Gustavo Bacagine.
 * 
 * Essa função faz um calculo de um número fatorial
 * de maneira recursiva */
int recorsive_fatorial(int n);

/* Função cirada pelo professor Ciro Crine Trindade
 * 
 * Outra maneira de limpar o buffer
 * do terminal. */
void buffer_clean(void);

/* Essa função foi criada por Herbert Schildt
 * Pegamos ela de seu livro "C Completo e Total"
 * 
 * Essa função funciona semelhante à puts
 * printando uma string na saída do terminal. */
void my_puts(char *s);

/* Essa função foi criada por Herbert Schildt
 * Pegamos ela de seu livro "C Completo e Total"
 * 
 * Essa função funciona semelhante à função pow
 * calculando o expoente (e) de um número (n) */
int my_pow(int n, int e);

// Desenvolvimento das funções listadas acima
void clear_buffer(void){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

void italico(char *str){
    int i;        // indice da string
    int num = 1; // usado para verificar quando ocorre a primeira ocorrencia dos caracteres '_' e '*'

    i = 0;
    while(str[i] != '\0'){   // percorre a string
        if (str[i] == '_'){ // e procura pelo sinal de '_'
            num++; /* Quando meu caracter for '_' num será igual a dois
                    * isso serve para que eu possa saber quando o caracter '_'
                    * aparece pela primeira e segunda vez no terminal */
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

void negrito(char *str){
    int i; // indice da string
    int num = 1;

    i = 0;
    while(str[i] != '\0'){   // percorre a string
        if (str[i] == '*'){ // e procura pelo sinal de '*'
            num++; /* Quando meu caracter for '*' num será igual a dois
                    * isso serve para que eu possa saber quando o caracter '*'
                    * aparece pela primeira e segunda vez no terminal */
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

void replace(char *str, int i, const char *newStr){
    char oldStr[101];
    int tamNewStr;

    tamNewStr = strlen(newStr);

    strcpy(oldStr, str + i + 1);
    strcpy(str + i, newStr);
    strcpy(str + i + tamNewStr, oldStr);
}

void cadastrar_cliente(void){
    setlocale(LC_ALL, "Portuguese_Brazil"); // Permite o uso de acentuações e caracteres especiais
    
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
    setlocale(LC_ALL, "Portuguese_Brazil"); // Permite o uso de acentuações e caracteres especiais
    
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
    setlocale(LC_ALL, "Portuguese_Brazil"); // Permite o uso de acentuações e caracteres especiais
    
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
    setlocale(LC_ALL, "Portuguese_Brazil"); // Permite o uso de acentuações e caracteres especiais
    
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
//        fclose(arq_cliente);
        getchar();
        clear_buffer();
       system("clear");
    }
    
    fclose(arq_cliente);
}
/*
void listar_compras_data(void){
    
}

bool datas_iguais(data, data){
    
}
*/
void listar_compras_cliente(void){
    setlocale(LC_ALL, "Portuguese_Brazil"); // Permite o uso de acentuações e caracteres especiais
    
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

void matriz(void){
    setlocale(LC_ALL, "Portuguese_Brazil");
    
    int matriz[4][6], i, j;
    printf("Informe os elementos da matriz 4x6:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 6; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("Conteúdo da matriz:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 6; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void naval(void){
    int inimigo[5][10] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                           { 0, 1, 1, 1, 1, 0, 0, 1, 0, 1 },
                           { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
                           { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
                           { 1, 0, 1, 1, 1, 0, 0, 0, 0, 0 } };
    char tabuleiro[5][10];
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = '.';
            printf("%c", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("Informe as coordenadas do tiro (-1 p/ sair): ");
    scanf("%d %d", &i, &j);
    while (i != -1) {
        if (inimigo[i][j] == 1) {
            tabuleiro[i][j] = 'X';
        }
        else {
            tabuleiro[i][j] = 'O';
        }
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 10; j++) {
                printf("%c", tabuleiro[i][j]);
            }
            printf("\n");
        }
        printf("\nInforme as coordenadas do tiro (-1 p/ sair): ");
        scanf("%d %d", &i, &j);		
    }
}

void notas(void){
    int notas[7] = { 100, 50, 20, 10, 5, 2, 1 };
    int i, valor, qtde;
    printf("Informe um valor em real: R$ ");
    scanf("%d", &valor);
    for (i = 0; i < 7; i++) {
        qtde = valor / notas[i];
        if (qtde > 0) {
            printf("%d nota(s) de R$ %d\n", qtde, notas[i]);
            valor %= notas[i];
        }
    }
}

void inverse_num(void){
    setlocale(LC_ALL, "Portuguese_Brazil");
    
    int n, i;
    printf("Informe o número de elementos da sequência: ");
    scanf("%d", &n);
    int seq[n];
    printf("Informe %d números inteiros:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &seq[i]);
    }
    printf("\nSequência em ordem inversa: ");
    for (i = n - 1; i >= 0; i--) {
        printf("%d ", seq[i]);
    }
    printf("\n");
}

void binario_decimal(void){
    char binario[21];
    int decimal = 0, pot2 = 1, i;
    printf("Informe um numero binario: ");
    scanf("%20[01]", binario);
    for (i = strlen(binario) - 1; i >= 0; i--) {
        decimal += (binario[i] - '0') * pot2;
        pot2 *= 2;
    }
    printf("%s em decimal: %d\n", binario, decimal);
}

void conta_str(void){
    int n, i, cont = 0;
    printf("Informe o numero de strings: ");
    scanf("%d", &n);
    char strings[n][41], str[41];
    printf("Informe as %d strings:\n", n);
    for (i = 0; i < n; i++) {
        printf("%da.) ", i + 1); 
        scanf(" %40[^\n]", strings[i]);
    }
    printf("Informe uma string: ");
    scanf(" %40[^\n]", str);
    for (i = 0; i < n; i++) {
        if (strstr(strings[i], str) != NULL) {
            cont++;
        }
    }
    if (cont > 0) {
        printf("%s aparece em %d strings\n", str, cont);
    }
    else {
        printf("%s nao aparece em nenhuma string\n", str);
    }
}

void maiusculas(void){
    char str[81];
    int i, cont = 0;
    printf("Informe uma string: ");
    scanf("%80[^\n]", str);
    for (i = 0; str[i] != '\0'; i++) {
        //if (str[i] >= 'A' && str[i] <= 'Z') {
        if (isupper(str[i])) {
            cont++;
        }
    }
    printf("\n\"%s\" possui %d letra(s) maiuscula(s)\n", str, cont);    
}

void palindromo(void){
    char str[81], sem_espacos[81], inverso[81];
    int i, j;
    printf("Informe uma string: ");
    scanf("%80[^\n]", str);
    
    // retira os espaços
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            sem_espacos[j++] = str[i];
        }
    }
    sem_espacos[j] = '\0';
    printf("String sem espacos: \"%s\"\n", sem_espacos);
    
    // inverte a string
    for (i = 0, j--; j >= 0; i++, j--) {
        inverso[i] = sem_espacos[j];
    }
    inverso[i] = '\0';
    
    if (strcasecmp(sem_espacos, inverso) == 0) {
        printf("\"%s\" E palindromo\n", str);
    }
    else {
        printf("\"%s\" NAO e palindromo\n", str);
    }    
}

void area(void){
    int raio;
    double area;
    printf("%s - %s\n", __DATE__, __TIME__);
    printf("Informe o raio de uma esfera: ");
    scanf("%d", &raio);
    /*
    area = PI * (raio * raio); // ==> area = 3.1415 * (raio * raio);
    PRN(area); // ==> printf("%lf\n", area);
    */
    PRN(AREA(raio)); // ==> printf("%lf\n", (3.1415 * ((raio) * (raio))));
}

void recebe_matriz(int l, int c, int m[][c]){
    int i, j;
    printf("Informe os elementos da matriz %d x %d:\n", l, c);
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &m[i][j]);
        }
    }
}

void imprime_matriz(int l, int c, int m[][c]){
    int i, j;
    printf("\nConteudo da matriz %d x %d:\n", l, c);
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

void multiplica_matriz(int l, int c, double (*m)[c], double x){
    int i, j;
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            m[i][j] *= x;
        }
    }
}

void dobro(int x){
    x = x * 2;
    printf("Dobro: %d\n", x);
}

int maior(int a, int b) {
    if (a > b)
        return a;
    return b;
}

void retangulo(int a, int c){
    int i, j;
    for (i = 1; i <= a; i++) {
        for (j = 1; j <= c; j++) {
            putchar('*');
        }
        printf("\n");
    }
}

double volume(int r){
    return (4 * M_PI * pow(r, 3)) / 3;
}

long long fatorial (int n){
    long long f = 1;
    int i;
    for (i = n; i > 0; i--) {
        f *= i;
    }
    return f;
} 

int arredondar_para_int (double n){
    return (int) floor(n + 0.5);
}

double arredondar (double n, int p){
    return arredondar_para_int(n * pow(10, p)) / pow(10, p);
}

void dec2bin (int * n){
    int dec = *n, pot10 = 1;
    *n = 0;
    while (dec > 0) {
        *n += (dec % 2) * pot10;
        dec /= 2;
        pot10 *= 10;
    }
}

void separa_data(int dt, int * d, int * m, int * a){
    *d = dt / 1000000;
    *m = (dt / 10000) % 100;
    *a = dt % 10000;
}

void file_size(int b, float * kb, float * mb){
    *kb = b / 1024.0;
    *mb = *kb / 1024;	
}

void transforma_segundos(int s_int, int *h, int *min,int *s){
    *h = s_int / 3600;
    *min = (s_int / 60) % 60;
    *s = s_int % 60;
}

void circunferencia(float r, float *dim,float *per,float *a){
    *dim = 2 * r;
    *per = 2 * M_PI * r;
    *a = M_PI * pow(r,2); // pow e uma função da biblioteca math.h \
                            usada para calcular potenciação
}

void converte(float m, double *pol, double *jards, double *mils){
    *pol = (m * 39.37) / 1.0;
    *jards = (m * 1.0936) / 1.0;
    *mils = (m * 0.00062) / 1.0;
}

void aprovados(int n, aluno a[]){
    int i, j;
    float media;
    printf("\n\n\tAlunos Aprovados\n");
    printf("----------------------------------------------\n");
    printf("Matricula Nome                     Turma Média\n");
    printf("----------------------------------------------\n");
    for (i = 0; i < n; i++) {
        media = 0;
        for (j = 0; j < 3; j++) {
            media += a[i].provas[j];
        }
        media /= 3;
        if (media >= 6) {
            printf("%09d %-25.25s  %c  %5.2f\n", a[i].matricula, a[i].nome,
                a[i].turma, media);			       
        }
    }
    printf("----------------------------------------------\n");
}

void cadastrar_carro(int * n, struct carro c[]){
    if (*n < NUM_CARROS) {
        printf("\nNovo Carro\n");
        printf("Marca: ");
        scanf(" %20[^\n]", c[*n].marca);
        printf("Ano: ");
        scanf("%d", &c[*n].ano);
        printf("Cor: ");
        scanf(" %10[^\n]", c[*n].cor);
        printf("Preco: R$ ");
        scanf("%f", &c[*n].preco);
        (*n)++;
        printf("\nCarro cadastrado com sucesso!\n");
    }
    else {
        printf("\nErro: nao é possivel cadastrar mais nenhum carro!\n");
    }
}

void listar_por_preco(int n, struct carro c[], float preco){
    int i;
    printf("\nCarros com preco menor ou igual a R$ %.2f\n", preco);
    printf("-----------------------------------------------\n");
    printf("Marca                Ano Cor         Preco\n");
    printf("-----------------------------------------------\n");
    for (i = 0; i < n; i++) {
        if (c[i].preco <= preco) {
            printf("%-20.20s %4d %-10.10s %10.2f\n", c[i].marca, c[i].ano, 
                c[i].cor, c[i].preco);
        }
    }
    printf("-----------------------------------------------\n");
}

void listar_por_marca(int n, struct carro c[], const char * marca){
    int i;
    printf("\nCarros da marca %s\n", marca);
    printf("----------------------------\n");
    printf("Ano Cor         Preco\n");
    printf("----------------------------\n");
    for (i = 0; i < n; i++) {
        if (strcasecmp(c[i].marca, marca) == 0) {
            printf("%4d %-10.10s %10.2f\n", c[i].ano, 
                    c[i].cor, c[i].preco);
        }
    }
    printf("----------------------------\n");
}

void cadastrar_aluno(){
    FILE * arq;
    int mat;
    char nome[41];
    printf("\n\nNovo Aluno\n");
    printf("Matricula: ");
    scanf("%d", &mat);
    printf("Nome: ");
    scanf(" %40[^\n]", nome);
    if ((arq = fopen(ARQ_ALUNOS, "a")) == NULL) {
        fprintf(stderr, "\nErro: nao foi possivel abrir o arquivo %s\n", ARQ_ALUNOS);
        return;
    }
    fprintf(arq, "%d %s\n", mat, nome);
    fclose(arq);
}

void listar_alunos(){
    FILE * arq;
    int mat;
    char nome[41];
    if ((arq = fopen(ARQ_ALUNOS, "r")) == NULL) {
        fprintf(stderr, "\nErro: nao ha' nenhum aluno cadastrado!\n");
        return;
    }
    printf("\n\n\t\tAlunos Cadastrados\n");
    printf("-------------------------------------------\n");
    printf("Matricula Nome\n");
    printf("-------------------------------------------\n");
    while (fscanf(arq, "%d %40[^\n]", &mat, nome) > 0) {
        printf("%09d %s\n", mat, nome);
    }
    printf("-------------------------------------------\n");
    fclose(arq);
}

int exibe_arq(void){
    FILE * fp;
    char nomearq[40], ch;
    printf("Entre com o nome do arquivo: ");
    scanf("%39[^\n]", nomearq);
    if ((fp = fopen(nomearq, "r")) == NULL) {
        fprintf(stderr, "Erro de abertura do arquivo %s\n", nomearq);
        return 1;
    }
    while ((ch = fgetc(fp)) != EOF) {
        fputc(ch, stdout);
    }
    fclose(fp);
}

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

int soma(int n1, int n2){
    int soma;
    
    soma = n1 + n2;
    
    return soma;
}

int subtracao(int n1, int n2){
    int sub;
    
    sub = n1 - n2;
    
    return sub;
}

int multiplicacao(int n1, int n2){
    int mult;
    
    mult = n1 * n2;
    
    return mult;
}

int divisao(int n1, int n2){
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
/*
int int recorsive_fatorial(int n){
    
}
*/

void buffer_clean(void){
    while(getchar() != '\n');
}

void my_puts(char* s){
    while(*s){
        putchar(*s++);
    }
}

int my_pow(int n, int e){
    register int t = 1;
    for(; e; e--){
        t = t*n;
    }
    return t;
}

#endif // _FATEC_H
