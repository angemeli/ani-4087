#include <iostream>
#include <string>

using namespace std;

// Valeur absolue d'un entier
long long absolu(long long v) {
   return (v < 0) ? -v : v;
}

int main() {
   int n;
   cin >> n;

   int deplaces = 0; // objets dont l'écart n'est pas nul
   long long pire = 0; // plus grand écart rencontré

   for (int i = 0; i < n; i++) {
      string nom;
      long long tx, ty, tz, sx, sy, sz;
      cin >> nom >> tx >> ty >> tz >> sx >> sy >> sz;

      // Mauvais ordre (échelle puis translation)
      long long x = sx * tx / 1000;
      long long y = sy * ty / 1000;
      long long z = sz * tz / 1000;

      // Écart avec la bonne position (tx, ty, tz)
      long long ecart = absolu(tx - x);
      if (absolu(ty - y) > ecart) {
         ecart = absolu(ty - y);
      }
      if (absolu(tz - z) > ecart) {
         ecart = absolu(tz - z);
      }

      // Mise à jour du bilan
      if (ecart != 0) {
         deplaces++;
      }
      if (ecart > pire) {
         pire = ecart;
      }

      cout << nom << " " << x << " " << y << " " << z << " " << ecart << "\n";
   }

   // Bilan
   cout << "DEPLACES " << deplaces << "\n";
   cout << "PIRE " << pire << "\n";

   return 0;
}
