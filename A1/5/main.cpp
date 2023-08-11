// 5.- Clases y objetos: Escribe un programa que tenga una clase Persona con los
// atributos nombre y edad y los métodos imprimirPersona y cumplirAnios, escribe
// tu clase Main en la cual se solicite al usuario ingresar el nombre y la edad
// inicial y le permita a través de un menú imprimir el nombre o cumplir años
// hasta que el usuario decida salir del programa.

#include <iostream>
#include "persona.h"

using namespace std;

int main() {
   int age;
   cout << "Ingresa edad: ";
   cin >> age;

   string name;
   cout << "Ingresa nombre: ";
   cin >> name;

   Persona person(age, name);

   while (true) {
      string input;
      cout << "[0]salir\n[1]imprimir persona\n[2]cumplir años\n";
      cin >> input;

      if (input == "0")
         break;
      else if (input == "1")
         person.PrintPerson();
      else if (input == "2")
         person.agePerson();
      else
         cout << "Opcion no valida, ingrese un numero del 0 al 2\n";
   }

   return 0;
}
