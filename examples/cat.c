#include <stdio.h>
#include <fatec/fatec.h>

int main(void){
    char filename[MAX_NAME_LEN];
    
    printf("Write the name of file: ");
    scanf("%s", filename);
    
    cat(filename);
    
    return 0;
}
