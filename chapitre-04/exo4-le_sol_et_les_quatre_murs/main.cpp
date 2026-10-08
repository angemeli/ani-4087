#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Emprise au sol d'un mur, vue de dessus
struct Mur {
   long long xmin, xmax, zmin, zmax;
};

int main() {
   long long L, e;
   int n;
   cin >> L >> e >> n;

   // Lecture des murs et calcul de leur emprise
   vector<Mur> murs;
   for (int i = 0; i < n; i++) {
      string nom;
      long long cx, cz, sx, sz;
      cin >> nom >> cx >> cz >> sx >> sz;

      Mur m;
      m.xmin = cx - sx / 2;
      m.xmax = cx + sx / 2;
      m.zmin = cz - sz / 2;
      m.zmax = cz + sz / 2;
      murs.push_back(m);

      cout << nom << " " << m.xmin << " " << m.xmax << " " << m.zmin << " " << m.zmax << "\n";
   }

   // Les quatre angles
   long long h = L / 2;
   string noms[4] = {"FOND_GAUCHE", "FOND_DROIT", "ENTREE_GAUCHE", "ENTREE_DROIT"};
   Mur angles[4] = {
      {-h - e, -h, -h - e, -h},
      {h, h + e, -h - e, -h},
      {-h - e, -h, h, h + e},
      {h, h + e, h, h + e}
   };

   int trous = 0;
   for (int a = 0; a < 4; a++) {
      // Un angle est bouché si un mur contient tout son carré
      bool bouche = false;
      for (const Mur& m : murs) {
         if (m.xmin <= angles[a].xmin && m.xmax >= angles[a].xmax && m.zmin <= angles[a].zmin && m.zmax >= angles[a].zmax) {
            bouche = true;
         }
      }

      if (bouche) {
         cout << noms[a] << " BOUCHE\n";
      } 
      else {
         cout << noms[a] << " TROU\n";
         trous++;
      }
   }

   // Bilan, toujours en dernier
   cout << "TROUS " << trous << "\n";

   return 0;
}
