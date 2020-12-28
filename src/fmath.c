/* 
 * 
 * 
 * 
 * Date of last modification: 18/08/2020
 */

#include "../include/fatec/fmath.h"

int soma(int n1, int n2){
    return n1 + n2;
}

int subtracao(int n1, int n2){
    return n1 - n2;
}

int multiplicacao(int n1, int n2){
    return n1 * n2;
}

int divisao(int n1, int n2){
    return n1 / n2;
}

float fsoma(float n1, float n2){
    return n1 + n2;
}

float fsubtracao(float n1, float n2){
    return n1 - n2;
}

float fmultiplicacao(float n1, float n2){
    return n1 * n2;
}

float fdivisao(float n1, float n2){
    return n1 / n2;
}

double dsoma(double n1, double n2){
    return n1 + n2;
}

double dsubtracao(double n1, double n2){
    return n1 - n2;
}

double dmultiplicacao(double n1, double n2){
    return n1 * n2;
}

double ddivisao(double n1, double n2){
    return n1 / n2;
}

long long fatorial(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    else{
        return n * fatorial(n - 1);
    }
}

int my_pow(int n, int e){
    int aux = 1;
    while(e){
         aux *= n;
         e--;
    }
    return aux;
}
/*
int bin2dec(const int bin){
    
    return 0;
}

int dec2bin(const int dec){
    //int bin;
    for(int count = 0; bin >= 2; count++){
        //bin = dec / 2;
        
    //}
    return 0;
}
*/
int area(int raio){
    return 4 * PI * my_pow(raio, 2);
}

int volume_esfera(int raio){
    return (4 * PI * my_pow(raio, 3)) / 3;
}

void transforma_segundos(int s_int, int *h, int *min, int *s){
    *h = s_int / 3600;
    *min = (s_int / 60) % 60;
    *s = s_int % 60;
}

void circunferencia(float r, float *dim, float *per, float *a){
    *dim = 2 * r;
    *per = 2 * PI * r;
    *a = PI * my_pow(r, 2);
}

void converte(float m, double *pol, double *jards, double *mils){
    *pol = (m * 39.37) / 1.0;
    *jards = (m * 1.0936) / 1.0;
    *mils = (m * 0.00062) / 1.0;
}

void file_size(int b, float * kb, float * mb){
    *kb = b / 1024.0;
    *mb = *kb / 1024;
}

void bhaskara(double *x1, double *x2, double a, double b, double c){
    *x1 = (abs(b) + sqrt(my_pow(b, 2) - 4 * a * c)) / 2 * a;
    *x2 = (abs(b) - sqrt(my_pow(b, 2) - 4 * a * c)) / 2 * a ;
}

double hipotenusa(const double cat1, const double cat2){
    return sqrt((double) my_pow(cat1, 2) + (double) my_pow(cat2, 2));
}
/*
int mdc(int n1, int n2){
    return ;
}
*/
double imc(const double height, const char sexo){
    if(!strcmp(&sexo, "M") || !strcmp(&sexo, "m")){
        return 72.7 * height - 58;
    }
    else if(!strcmp(&sexo, "F") || !strcmp(&sexo, "f")){
        return 61.1 * height - 44.7;
    }
    return 1;
}

int permutation(int n){
    return fatorial(n);
}

int arranjos(int n, int k){
    int r = n - k;
    return fatorial(n) / fatorial(r);
}

int combinacao(int n, int k){
    int r = n - k;
    return fatorial(n) / fatorial(k) * fatorial(r);
}

int primo(int n){
    if(n % 1 == 0 && n % n == 0){
        return 0;
    }
    return 1;
}

double my_sqrt(double n){
    double count = 0;
    while(count < n){ // for(;count < n; count++)
        if(my_pow(count, 2) == n){
            return count;
        }
        count++;
    }
}
