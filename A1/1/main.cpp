// 1.- Contador de números pares: Escribe un programa que solicite un número al
// usuario y luego muestre todos los números pares desde 1 hasta ese número.
#include <iostream>

using namespace std;

int main() {
   int num;
   cout << "Ingresa un numero: ";

   cin >> num;

   for (int i = 1; i < num + 1; i++) {
      if (i % 2 == 0) cout << i << endl;
   }

   return 0;
}
