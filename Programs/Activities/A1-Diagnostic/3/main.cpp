// 3.- Números primos: Escribe un programa que diga si un número ingresado por
// el usuario es primo o no

#include <iostream>

using namespace std;

int main() {
   while (true) {
      int num;
      cout << "Ingresa un numero: ";

      cin >> num;

      bool prime = true;
      if (num == 1 || num == 0) {
         prime = false;
      } else {
         for (int i = 2; i < num; i++) {
            if (num % i == 0) prime = false;
         }
      };

      cout << (prime == 1 ? "Es primo" : "no es primo");
      cout << endl;
   }

   return 0;
}
