#include <stdio.h>
#include <stdlib.h>
#include <fatec/fatec.h>
#include <fatec/str.h>

int main(void){
    String istr = (String) malloc(sizeof(char));
    int i = 10;
    
    fitoa(i, istr, 10)
    
    printf("%s\n", istr);
    
    free_ptr(istr);
    
    return 0;
}
