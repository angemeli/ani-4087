#include <iostream>
#include <string>

using namespace std;

int main() {
   int n;
   cin >> n;

   int aCorriger = 0; // cubes dont le verdict n'est pas POSE
   long long pire = 0; // plus grande distance entre un bas et le sol

   for (int i = 0; i < n; i++) {
      string nom;
      long long e, y;
      cin >> nom >> e >> y;

      // L'échelle e donne une hauteur de e millimètres.
      // Le cube est centré sur y : on prend la demi-hauteur de chaque côté.
      long long demi = e / 2;
      long long bas = y - demi;
      long long haut = y + demi;

      // Verdict : l'ordre des tests compte (SOUS LE SOL avant ENTERRE)
      string verdict;
      if (haut <= 0) {
         verdict = "SOUS LE SOL";
      } 
      else if (bas < 0) {
         verdict = "ENTERRE";
      } 
      else if (bas == 0) {
         verdict = "POSE";
      } 
      else {
         verdict = "FLOTTE";
      }

      // Tout verdict autre que POSE est à corriger
      if (verdict != "POSE") {
         aCorriger++;
      }

      // Distance entre le bas et le sol, en valeur absolue
      long long ecart = (bas < 0) ? -bas : bas;
      if (ecart > pire) {
         pire = ecart;
      }

      // La hauteur de pose vaut toujours la demi-hauteur, quel que soit y
      cout << nom << " " << bas << " " << haut << " " << verdict << " " << demi << "\n";
   }

   // Bilan, dans l'ordre demandé
   cout << "A CORRIGER " << aCorriger << "\n";
   cout << "PIRE " << pire << "\n";

   return 0;
}
