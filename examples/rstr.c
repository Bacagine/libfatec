#include <stdio.h>
#include <fatec/fatec.h>

int main(void){
    char phrase[MAX_NAME_LEN];
    
    printf("Write a phrase: ");
    rstr(phrase, MAX_NAME_LEN);
    
    puts(phrase);
    
    return 0;
}
