/* queue.c: Implementing queue algorithm in C
 * 
 * Development in Java by Professor Andreia Machion <andreia.machion@fatec.sp.gov.br>
 * and adapted for C by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 * 
 * Begin's date: 07/01/2021
 * Date of last modification: 11/02/2021
 */

#include <stdio.h>
#include "../include/fatec/queue.h"

bool q_is_empty(void){
    return q_count == 0;
}

bool q_is_full(void){
    return q_count == q_capacity;
}

int next(const int pos){
    return (pos + 1) % q_capacity;
}

void enqueue(const int i){
    queue[q_last] = i;
    q_last = next(q_last);
    q_count++;
}

int dequeue(void){
    int i = queue[q_first];
    q_first = next(q_first);
    q_count--;
    return i;
}

void show_queue(void){
    int i;
    if(q_is_empty()){
        for(i = 0; i < q_capacity; i++){
            printf("_ ");
        }
        puts("");
    }
    else if(q_is_full()){
        for(i = 0; i < q_capacity; i++){
            printf("%d ", queue[i]);
        }
        puts("");
    }
    else if(q_first < q_last){
        for(i = 0; i < q_first; i++){
            printf("_ ");
        }

        for(i = q_first; i < q_last; i++){
            printf("%d ", queue[i]);
        }

        for(i = q_last; i < q_capacity; i++){
            printf("_ ");
        }

        puts("");
    }
    else{
        for(i = 0; i < q_last; i++){
            printf("%d ", queue[i]);
        }

        for(i = q_last; i < q_first; i++){
            printf("_ ");
        }

        for(i = q_first; i < q_capacity; i++){
            printf("%d ", queue[i]);
        }

        puts("");
    }
}
