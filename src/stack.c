/* stack.c: Implementing the Stack Algorithm in C
 * 
 * Development by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 * 
 * Begin's date: 30/12/2020
 * Date of last modification: 07/01/2021
 */

#include <stdio.h>
#include "../include/fatec/stack.h"

boolean s_is_empty(void){
    return s_top == -1;
}

boolean s_is_full(void){
    return s_top == s_length-1;
}

void push(int stack[], const int elemento){
    stack[++s_top] = elemento;
}

int pop(int stack[]){
    return stack[s_top--];
}

int show_stack(int stack[]){
    if(s_is_empty()){
        return s_top;
    }
    else{
        int i;
        for(i = 0; i < s_top+1; i++){
            printf("Element %d = %d\n", i+1, stack[i]);
        }
        return 0;
    }
}
