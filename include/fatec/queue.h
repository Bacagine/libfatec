/* queue.c: Functions and variables for implemente the Queue Algorithm
 * 
 * Development in Java by Professor Andreia Machion <andreia.machion@fatec.sp.gov.br>
 * and adapted for C by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 * 
 * Begin's date: 07/01/2021
 * Date of last modification: 09/01/2021
 */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fatec/fatec.h>

static int *queue     = null;
static int q_first    = 0;
static int q_last     = 0;
static int q_count    = 0;
static int q_capacity = 0; // Queue length

/* Verify if queue is empty */
boolean q_is_empty(void);

/* Verify if queue is full */
boolean q_is_full(void);

/*  */
int next(const int pos);

/* Insert element in queue */
void enqueue(const int i);

/* Remove element of queue */
int dequeue(void);

/* Show queue */
void show_queue(void);
