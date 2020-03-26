/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/fatec                                     *
 *                                                                                *
 * Copyright (C) 2019 - 2020                                                      *
 *                                                                                *
 * aulas.c: Arquivo com o desenvolvimento do prototipo das funções usadas nas     *
 * aulas e listas de exercicios de Línguagem de Programação encontradas na        *
 * biblioteca fatec.h                                                             *
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
