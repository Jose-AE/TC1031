#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
using namespace std;
class Persona {
  private:
   string nombre;
   int edad;

  public:
   Persona(string nombre, int edad);
   Persona();
   string getNombre();
   int getEdad();
   void setNombre(string nombre);
   void setEdad(int edad);
   friend ostream &operator<<(ostream &os, const Persona &p) {
      os << "{Nombre: " << p.nombre << ", Edad: " << p.edad << "}";
      return os;
   }
   bool operator>(Persona p) {
      if (this->nombre == p.nombre) {
         return this->edad > p.edad;
      }
      return this->nombre > p.nombre;
   }

   bool operator<(Persona p) {
      if (this->nombre == p.nombre) {
         return this->edad < p.edad;
      }
      return this->nombre < p.nombre;
   }

   bool operator==(Persona p) {
      return (this->nombre == p.nombre) && (this->edad == p.edad);
   }
};

#endif