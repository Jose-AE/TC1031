// 2.- Factorial: Escribe un programa que calcule el factorial de un número
// ingresado por el usuario.

#include <iostream>

using namespace std;

int main() {
   int num;
   cout << "Ingresa un numero: ";

   cin >> num;

   int temp = 1;
   for (int i = 1; i < num + 1; i++) {
      temp *= i;
   }

   cout << temp;

   return 0;
}
