/* 
 * 
 * 
 * Date of last modification: 03/17/2023
 */

#include "../include/fatec/str.h"

String strupper(String str){
    for(int count = 0; str[count] != '\0'; count++){
        str[count] = toupper(str[count]);
    }
    return str;
}

String strlower(String str){
    for(int count = 0; str[count] != '\0'; count++){
        str[count] = tolower(str[count]);
    }
    return str;
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

int palindrome(const String str){
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

int count_str(const String str){
    int count;
    for(count = 0; str[count] != '\0'; count++);
    return count;
}

void sswap(String str1, String str2){
    char aux;
    strcpy(&aux, str1);
    strcpy(str1, str2);
    strcpy(str2, &aux);
}

void remove_new_line(char *str){
	int i = strlen(str) - 1;

	if(str[i] == '\n'){
		str[i] = '\0';
	}
}

