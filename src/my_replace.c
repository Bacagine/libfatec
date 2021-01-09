#include <stdio.h>
#include <string.h>

#define null NULL

typedef char * String;

void replace(String txt, int i, const String str);

int main(void){
    char str[51] = "Ola Mundo!!!";
    
    puts(str);
    
    replace(str, 2, "o");
    
    puts(str);
    
    return 0;
}

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
