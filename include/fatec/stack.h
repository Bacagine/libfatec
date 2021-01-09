/* stack.h: Functions and variables for implemente the
 * Stack Algorithm in C
 * 
 * Development by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 * 
 * Begin's date: 30/12/2020
 * Date of last modification: 09/01/2021
 */

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <fatec/fatec.h>

#define STACK_FULL  "The stack is full!"
#define STACK_EMPTY "The stack is empty!"

static int s_top    = -1; // Top of stack
static int s_length =  0;

/* Verify if stack is empty */
boolean s_is_empty(void);

/* Verify if stack is full */
boolean s_is_full(void);

/* Insert a new element on stack */
void push(int stack[], const int elemento);

/* Remove a element on stack */
int pop(int stack[]);

/* Show stack elements
 * Return -1 if stack is empty
 * and 0 if stack is not empty */
int show_stack(int stack[]);
