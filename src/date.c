/* Git Hub: https://github.com/Bacagine/fatec
 * 
 * Copyright (C) 2019 - 2020
 * 
 * date.c: 
 * 
 * fatec.h é um software livre; você pode redistribui-lo e/ou
 * modificalo sob os termos da Licença GNU Lesser General Public
 * publicada pela Free Software Foundation; ou
 * versão 2 da licença ou (a seu critério) qualquer versão posterior.
 * 
 * Você deve ter recebido uma copia da Licença GNU Lesser General Public
 * junto com o fatec.h; case contrario, veja:
 * <http://www.gnu.org/licenses/>.
 * 
 * Developers: Gustavo Bacagine          <gustavo.bacagine@protonmail.com>
 *             Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com>
 * 
 * Begin's date: 20/07/2020
 * Date of last modification: 11/02/2021
 */

#include "../include/fatec/date.h"

int compara_datas(date dt1, date dt2){
    int d1, d2;
    
    d1 = dt1.year * 10000 + dt1.month * 100 + dt1.day;
    d2 = dt2.year * 10000 + dt2.month * 100 + dt2.day;
    
    /* Verifica se as datas 
     * são iguais */
    bool dts_iguais = d1 == d2;
    /* Verifica se a primeira 
     * data é menor que a 
     * segunda */
    bool dt1_menor = d1 < d2;
    
    /* Se as datas forem iguais a
     * função retorna 0 */
    if(dts_iguais == true){
        return 0;
    }
    /* Se a primeira data for menor 
     * que a data escolhida pelo
     * usuário a função retorna -1 */
    else if(dt1_menor == true){
        return -1;
    }
    /* Se a primeira data for maior
     * que a segunda data a função
     * retorna 1 */
    else{
        return 1;
    }
}

bool datas_iguais(date dt1, date dt2){
    int d1, d2;
    
    d1 = dt1.year * 10000 + dt1.month * 100 + dt1.day;
    d2 = dt2.year * 10000 + dt2.month * 100 + dt2.day;
    
    return d1 == d2;
}

int leap_year(int year){
    /* A is a leap year quando é divisivel to
     * 4 or to 400 but not to 100 */
    bool leap = (year % 4 == 0 || year % 400 == 0)
                 && year % 100 != 0;
    if(leap == true){
        return 0;
    }
    return 1;
}

int valida_dia(date dt){
    if(!valida_mes(dt.month) && !valida_ano(dt.year)){
        if(dt.month == 1 || dt.month == 3  ||
           dt.month == 5 || dt.month == 7  ||
           dt.month == 8 || dt.month == 10 ||
           dt.month == 12){
            if(dt.day >= 1 && dt.day <= 31){
                return 0;
            }
        }
        else if(dt.month == 4 || dt.month == 6 ||
                dt.month == 9 || dt.month == 11){
            if(dt.day >= 1 && dt.day <= 30){
                return 0;
            }
        }
        else if(dt.month == 2){
            /* Verifica se o ano é
             * bissexto */
            if(!leap_year(dt.year)){
                if(dt.day >= 1 && dt.day <= 28){
                    return 0;
                }
            }
            else{
                if(dt.day >= 1 && dt.day <= 29){
                    return 0;
                }
            }
        }
    }
    return 1;
}

int valida_mes(int month){
    if(month > 12 || month < 1){
        return 1;
    }
    else{
        return 0;
    }
}

int valida_ano(int year){
    if(year > 0){
        return 0;
    }
    return 1;
}

int valida_data(date dt){
    if(!valida_dia(dt) && !valida_mes(dt.month) && !valida_ano(dt.year)){
        return 0;
    }
    return 1;
}
/*
void  listar_por_data(date dt_inicial, date dt_final){
    
}
*/
void  separa_data(int dt, int * d, int * m, int * a){
    *d = dt / 1000000;
    *m = (dt / 10000) % 100;
    *a = dt % 10000;
}

void  get_date(int *day, int *month, int *year){
    time_t tm_now;
 
    time(&tm_now);
    
    struct tm *local = localtime(&tm_now);
    
    *day = local->tm_mday;
    *month = local->tm_mon + 1; // month begin in 0 and end in 11
    *year = local->tm_year + 1900; // year begin in 
}

void  get_time(int *hour, int *minute, int *second){
    time_t tm_now;
    
    time(&tm_now);
    
    struct tm *local = localtime(&tm_now);
    
    *hour = local->tm_hour;
    *minute = local->tm_min;
    *second = local->tm_sec;
}
