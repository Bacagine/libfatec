#include "../include/fatec/physics.h"

double vm(double space, double time){
    return space / time;
}

double fr(double mass, double aceleration){
    return mass * aceleration;
}

double weight(double mass, double gravity){
    return mass * gravity;
}

double ec(double mass, double vm){
    return (mass * pow(vm, 2)) / 2;
}

double epg(double mass, double gravity, double heigth){
    return mass * gravity * heigth;
}

double epe(double k, double x){
    return (k * pow(x, 2)) / 2;
}

double em(double ec, double ep){
    return ec + ep;
}

double im(double force, double time){
    return force * time;
}

double qm(double mass, double velocity){
    return mass * velocity;
}

double pressure(double force, double area){
    return force / area;
}

double density(double mass, double volume){
    return mass / volume;
}
