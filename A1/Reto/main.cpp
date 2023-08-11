// 5.- Clases y objetos: Escribe un programa que tenga una clase Persona con los
// atributos nombre y edad y los métodos imprimirPersona y cumplirAnios, escribe
// tu clase Main en la cual se solicite al usuario ingresar el nombre y la edad
// inicial y le permita a través de un menú imprimir el nombre o cumplir años
// hasta que el usuario decida salir del programa.

#include <iostream>
#include "persona.h"

using namespace std;

int main() {

   Persona people[5] = {
       Persona(15, "Juan"),  Persona(19, "edoson"), Persona(21, "ososmar"),
       Persona(24, "peter"), Persona(20, "jero"),
   };

   Persona min = people[0];
   Persona max = people[0];

   for (Persona per : people) {
      if (per.GetAge() > max.GetAge()) max = per;
      if (per.GetAge() < min.GetAge()) min = per;
   }

   min.PrintPerson();
   max.PrintPerson();

   return 0;
}
