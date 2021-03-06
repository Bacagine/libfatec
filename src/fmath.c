/* 
 * 
 * 
 * 
 * Date of last modification: 11/02/2021
 */

#include "../include/fatec/fmath.h"

double sum(double n1, double n2){
    return n1 + n2;
}

double subtraction(double n1, double n2){
    return n1 - n2;
}

double multiplication(double n1, double n2){
    return n1 * n2;
}

double division(double n1, double n2){
    return n1 / n2;
}

long long factorial(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    else{
        return n * factorial(n - 1);
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

int esphere_volume(int raio){
    return (4 * PI * my_pow(raio, 3)) / 3;
}

void transform_seconds(int s_int, int *h, int *min, int *s){
    *h = s_int / 3600;
    *min = (s_int / 60) % 60;
    *s = s_int % 60;
}

void circunference(float r, float *dim, float *per, float *a){
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
    return factorial(n);
}

int arranjos(int n, int k){
    int r = n - k;
    return factorial(n) / factorial(r);
}

int combinacao(int n, int k){
    int r = n - k;
    return factorial(n) / factorial(k) * factorial(r);
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
