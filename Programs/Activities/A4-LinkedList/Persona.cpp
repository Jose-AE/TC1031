#include "Persona.h"

Persona::Persona(string nombre, int edad){
    this->nombre=nombre;
    this->edad=edad;
}
Persona::Persona(){
    this->nombre="";
    this->edad=0;
}
string Persona::getNombre(){
    return nombre;
}
int Persona::getEdad(){
    return edad;
}
void Persona::setNombre(string nombre){
    this->nombre=nombre;
}
void Persona::setEdad(int edad){
    this->edad=edad;
}