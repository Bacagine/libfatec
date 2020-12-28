/* 
 * 
 * 
 * Date of last modification: 14/08/2020
 */

#include "../include/fatec/str.h"

char *strupper(char *str){
    for(int count = 0; str[count] != '\0'; count++){
        str[count] = toupper(str[count]);
    }
    return str;
}

char *strlower(char *str){
    for(int count = 0; str[count] != '\0'; count++){
        str[count] = tolower(str[count]);
    }
    return str;
}
/*
void replace(char *str, int i, const char *newStr){
    char aux;
    strcpy(&aux, str);
    strcat(&aux, &newStr[i + 1]);
    strcpy(str, &aux);
}
*/
int palindrome(const string str){
    char rts[MAX_STR_LEN];
    int count;
    for(count = strlen(str); count >= 0; count--){
        strcpy(rts, &str[count]);
    }
    
    if(!strcmp(rts, str)){
        return 0;
    }
    else{
        return 1;
    }
}

int count_str(const string str){
    int count;
    for(count = 0; str[count] != '\0'; count++);
    return count;
}

void sswap(char *str1, char *str2){
    char aux;
    strcpy(&aux, str1);
    strcpy(str1, str2);
    strcpy(str2, &aux);
}
