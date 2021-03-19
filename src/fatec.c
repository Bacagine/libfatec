/* Git Hub: https://github.com/Bacagine/fatec
 * 
 * Copyright (C) 2019 - 2021
 * 
 * fatec.c: Arquivo com o desenvolvimento do prototipo das funções da biblioteca
 * fatec.h
 * 
 * fatec.c é um software livre; você pode redistribui-lo e/ou modificalo sob os
 * termos da Licença GNU Lesser General Public publicada pela Free Software
 * Foundation; ou versão 2 da licença ou (a seu critério) qualquer
 * versão posterior.
 * 
 * Você deve ter recebido uma copia da Licença GNU Lesser General Public junto
 * com o fatec.c; caso contrario, veja: <http://www.gnu.org/licenses/>.
 * 
 * Desenvolvedores: Gustavo Bacagine          <gustavo.bacagine@protonmail.com>
 *                  José Eduardo              <joseeduardoolimpio@gmail.com>
 *                  Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com>
 *                  Caio Elias Emerick Regino <caioregino.147@gmail.com>
 *                  Luiz Dionizio             <luizgdsoares@hotmail.com>
 *                  Profº Ciro Cirne Trindade <ciroct@gmail.com>
 *                  Profª Andreia Machion     <andreia.machion@fatec.sp.gov.br>
 * 
 * Data: 02/12/2019
 * Data da última modificação: 12/02/2021
 */

#include "../include/fatec/fatec.h"

void clear_buffer(void){
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

void buffer_clean(void){
    while(getchar() != '\n');
}

int cat(const char * file){
    FILE *fp;
	char line[MAX_LINE_LEN];
	//for(int count = 0; count < qtd; count++){
        if((fp = fopen(file, "r")) == NULL){
            return 1;
        }
        while(fgets(line, MAX_LINE_LEN, fp) != NULL){
            fputs(line, stdout);
        }
        fclose(fp);
    //}
    return 0;
}
/* Em andamento
int tac(const char * file){
    FILE *fp;
	char line[MAX_LINE_LEN];
	//for(int count = 0; count < qtd; count++){
        if((fp = fopen(file, "r")) == NULL){
            return 1;
        }
        while(fgets(line, MAX_LINE_LEN, fp) != NULL){
            fputs(line, stdout);
        }
        fclose(fp);
    //}
    return 0;
}
*/
int head(const char * file){
    FILE *fp;
	//for(int count = 0; count < qtd; count++){
        if((fp = fopen(file, "r")) == NULL){
            return 1;
        }
        int count = 0;
        char line[MAX_LINE_LEN];
        //for(int count = 0; count < qtd; count++){
            while(fgets(line, MAX_LINE_LEN, fp) && count != 10){
                fputs(line, stdout);
                count++;
            }
        fclose(fp);
	//}
    return 0;
}
/* Em andamento
int tail(const char * file){
    FILE *fp;
    //for(int count = 0; count < qtd; count++){
        if((fp = fopen(file, "r")) == NULL){
            return 1;
        }
        
        int count = 10;
        char line[MAX_LINE_LEN];
        while(fgets(line, MAX_LINE_LEN, fp) != NULL);
        while(fgets(line, MAX_LINE_LEN, fp) && count != 0){
            fputs(line, stdout);
            count--;
        }
        fclose(fp);
    //}
    return 0;
}
*/
int cp(const char * ori, const char * dest){
    FILE *fp_ori, *fp_dest;
	if((fp_ori = fopen(ori, "r"))  == NULL){
		return 1;
	}
	
	char line[MAX_LINE_LEN];
	fp_dest = fopen(dest, "w");
	
	while(fgets(line, MAX_LINE_LEN, fp_ori) != NULL){
		fputs(line, fp_dest);
	}

	fclose(fp_ori);
	fclose(fp_dest);
    
    return 0;
}

void clear(void){
    #ifdef UNIX
		printf("\033\143");
	#elif defined(WIN)
		printf("\x0");
	#endif
}

void mkfolders(const char * folder[MAX_FILE_LEN], const int umask, const int qtd){
    int a;
    for(int count = 0; count < qtd; count++){
        a = mkdir(folder[count], umask);
    }
}

int grep(const char * word, const char * file){
    FILE *fp;
    
    if((fp = fopen(file, "r")) == NULL){
        return 1;
    }
    
    char line[MAX_LINE_LEN];
    
    while(fgets(line, MAX_LINE_LEN, fp) != NULL){
        if(strstr(word, line)){
            fputs(line, stdout);
        }
    }
    fclose(fp);
    return 0;
}

int mv(const char * ori, const char * dest){
    FILE *fp_ori, *fp_dest;
    if((fp_ori = fopen(ori, "r")) == NULL){
        return 1;
    }
    
    char line[MAX_LINE_LEN];
    fp_dest = fopen(dest, "w");
    while(fgets(line, MAX_LINE_LEN, fp_ori) != NULL){
        fputs(line, fp_dest);
    }
    
    fclose(fp_ori);
    fclose(fp_dest);
    remove(ori);
    
    return 0;
}

void rm(const char * arqs[MAX_FILE_LEN], const int qtd){
    for(int count = 0; count < qtd; count++){
        remove(arqs[count]);
    }
}

int touch(const char * str){
    FILE *fp;
    if((fp = fopen(str, "w")) == NULL){
        return 1;
    }
    return 0;
}

void swap(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void rstr(char * str, int length){
    int count, ch;

    count = 0;
    while(count < length-1 && (ch = getchar()) != '\n'){
        str[count] = ch;
        count++;
    }
    str[count] = '\0';
}


/*
void rstr(char * str, int length){
    for(int i = 0; str[i] < length; i++){
        if(i <= length){
            str[i] = getchar();
        }
        else{
            clear_buffer();
        }
    }
}
*/
void frstr(char * str, int length, FILE* __stream){
    int count, ch;
    
    count = 0;
    while(count < length-1 && (ch = getc(__stream)) != '\n' && ch != EOF){
        str[count] = ch;
        count++;
    }
    str[count] = '\0';
}

/* Em fase de testes
void developers(const int qtd, const char names[][MAX_NAME_LEN],
                const char emails[][MAX_NAME_LEN], int year,
                const char * university, const char * city,
                const char * desc){
    setlocale(LC_ALL, "");

    clear_terminal();
    if(qtd > 0 && qtd == 1){
        fprintf(stdout, "************************DESENVOLVEDOR*************************\n");
    }
    else{
        fprintf(stdout, "************************DESENVOLVEDORE(S)************************\n");
    }
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "* %s  -                %s            -         %d *\n", university, city, year);
    fprintf(stdout, "*---------------------------------------------------------------*\n");
    fprintf(stdout, "*                                                               *\n");
    for(int count = 0; count < qtd; count++){
        fprintf(stdout, "* %s          <%s>   *\n", names[count], emails[count]);
    }
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "* %s *", desc);
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "*****************************************************************\n");
    
    stay();
}
*/
/*
long file_size(const char * file){
    FILE *fp;
    
    long size;
    
    if((fp = fopen(file, "rb")) == NULL){
        fprintf(stderr, "Error: '%s' no such file or direcotry!\n", file);
        return -1;
    }
    
    fread();
    
//    size = ;
    
    fclose(fp);
    
    return size;
}
*/

void print_line(const char simbol, const int length, bool bold){
    int i;
    if(bold == true){
        for(i = 0; i < length; i++){
            printf("\033[1m%c\033[m", simbol);
        }
    }
    else{
        for(i = 0; i < length; i++){
            putchar(simbol);
        }
    }
}

void fmenu(const char * menu_title, const int qtd_options,
          char * msg_options[qtd_options], const char menu_simbol,
          int line_length, bool bold){
    int i;
    
    print_line(menu_simbol, line_length/2, bold);
    if(bold == true){
        printf("\033[1m %s \033[1m", menu_title);
    }
    else{
        printf(" %s ", menu_title);
    }
    print_line(menu_simbol, line_length/2, bold);
    putchar('\n');
    
    if(bold == true){
        for(i = 0; i < qtd_options; i++){
            printf("\033[1m%c %d) %-25.25s\t %c\033[1m\n", menu_simbol, i+1, msg_options[i], menu_simbol);
        }
    }
    else{
        for(i = 0; i < qtd_options; i++){
            printf("%c %d) %-25.25s\t %c\n", menu_simbol, i+1, msg_options[i], menu_simbol);
        }
    }
    
    if(line_length % 2 == 0){
        line_length += strlen(menu_title)+2;
    }
    else{
        line_length +=strlen(menu_title)+1;
    }
    
    print_line(menu_simbol, line_length, bold);
    putchar('\n');
}

void free_ptr(void *ptr){
    free(ptr);
    ptr = NULL;
}
