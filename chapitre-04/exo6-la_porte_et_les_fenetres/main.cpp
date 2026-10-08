#include <iostream>
#include <string>

using namespace std;

int main() {
   long long W, H, seuil;
   int n;
   cin >> W >> H >> seuil >> n;

   int ok = 0;
   int aReprendre = 0;

   for (int i = 0; i < n; i++) {
      string nom;
      long long u, y, l, h, e, d;
      cin >> nom >> u >> y >> l >> h >> e >> d;

      // Saillie : profondeur de la face avant, face arrière : l'autre côté
      long long saillie = d + e / 2;
      long long arriere = d - e / 2;

      // Les verdicts sont testés dans l'ordre imposé, le premier gagne
      string verdict;
      if (u - l / 2 < -W / 2 || u + l / 2 > W / 2 ||
          y - h / 2 < 0 || y + h / 2 > H) {
         // Le panneau sort du mur (des bords qui coïncident ne comptent pas)
         verdict = "DEBORDE";
      } 
      else if (saillie <= 0) {
         // Face avant dans le mur ou sur lui : le panneau est noyé
         verdict = "INVISIBLE";
      } 
      else if (saillie < seuil) {
         // Les deux faces sont trop proches : le panneau se bat avec le mur
         verdict = "CLIGNOTE";
      } 
      else if (arriere > seuil) {
         // Un vide entre le panneau et le mur
         verdict = "DECOLLE";
      } 
      else {
         verdict = "OK";
      }

      // Mise à jour du bilan
      if (verdict == "OK") {
         ok++;
      } 
      else {
         aReprendre++;
      }

      // La saillie s'affiche pour tous les panneaux, même ceux qui débordent
      cout << nom << " " << saillie << " " << verdict << "\n";
   }

   // Bilan
   cout << "OK " << ok << "\n";
   cout << "A REPRENDRE " << aReprendre << "\n";

   return 0;
}
