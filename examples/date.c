#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fatec/fatec.h>
#include <fatec/date.h>

int main(void){
    date *today = (date *) malloc(sizeof(date));
    struct tm *current_time = (struct tm *) malloc(sizeof(struct tm));
    
    today->day   = current_time->tm_mday;
    today->month = current_time->tm_mon;
    today->year  = current_time->tm_year;
    
    get_date(&today->day, &today->month, &today->year);
    get_time(&current_time->tm_hour, &current_time->tm_min, &current_time->tm_sec);
    
    printf("Totay is: %02d/%02d/%d\n", today->day, today->month, today->year);
    printf("Current Time: %02d:%02d:%02d\n", current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
    
    free_ptr(today);
    free_ptr(current_time);
    
    return 0;
}
