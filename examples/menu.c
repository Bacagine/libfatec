#include <stdio.h>
#include <fatec/fatec.h>

#define QTD_MENU_OPTIONS  4
#define LINE_LEN         22

static char *options[QTD_MENU_OPTIONS] = {
    "Op 1", "Opcao 2",
    "Op 3", "Sair"
};

int main(void){
    size_t op = 0;
    
    do{
        clear_terminal();
        
        fmenu("Fatec Menu", QTD_MENU_OPTIONS, options, '*', LINE_LEN, true);
        scanf("%zd", &op);
        clear_buffer();
        
        switch(op){
            case 1: puts("You choice the op 1"); stay(); break;
            case 2: puts("You choice the op 2"); stay(); break;
            case 3: puts("You choice the op 3"); stay(); break;
            case 4: printf("Exiting. . .\n"); break;
            default: fprintf(stderr, "Error: Invalid option!\n"); stay(); break;
        }
    } while(op != QTD_MENU_OPTIONS);
    
    return 0;
}
