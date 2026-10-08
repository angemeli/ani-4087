#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
   // Table de correspondance : nom technique - nom lisible à afficher
   map<string, string> lisible = {
      {"VULKAN", "Vulkan"}, {"DX12", "DirectX 12"}, {"DX11", "DirectX 11"},
      {"OPENGL", "OpenGL"}, {"METAL", "Metal"}, {"SOFTWARE", "Software"}};

   // Ordre d'essai des interfaces pour chaque plateforme connue
   map<string, vector<string>> ordres = {
      {"WINDOWS", {"VULKAN", "DX12", "DX11", "OPENGL", "SOFTWARE"}},
      {"MACOS", {"METAL", "OPENGL", "SOFTWARE"}},
      {"IOS", {"METAL", "SOFTWARE"}},
      {"ANDROID", {"VULKAN", "OPENGL", "SOFTWARE"}}};

   // Ordre utilisé pour toute plateforme absente de la table
   vector<string> parDefaut = {"VULKAN", "OPENGL", "SOFTWARE"};

   int n;
   cin >> n;
   int ignorees = 0, logiciel = 0;
   set<string> noms;

   // Traitement d'une machine par tour de boucle
   for (int i = 0; i < n; i++) {
      // Lecture de la ligne : nom, plateforme, nombre d'interfaces
      string nom, plateforme;
      int k;
      cin >> nom >> plateforme >> k;
      set<string> apis;

      // Lecture des interfaces qui fonctionnent sur cette machine
      for (int j = 0; j < k; j++) {
         string a;
         cin >> a;
         apis.insert(a);
      }

      // Choix de l'ordre : celui de la plateforme si elle est connue, sinon on choisit l'ordre par défaut
      const vector<string>& ordre =
         ordres.count(plateforme) ? ordres[plateforme] : parDefaut;

      // Comptage des interfaces ignorées
      for (const string& a : apis) {
         bool dansOrdre = false;
         for (const string& o : ordre) {
            if (o == a) {
               dansOrdre = true;
            }
         }
         if (!dansOrdre) {
            ignorees++;
         }
      }

      // Choix de l'interface
      string choix = "SOFTWARE";
      for (const string& o : ordre) {
         if (apis.count(o)) { 
            choix = o;
            break; 
         }
      }

      if (choix == "SOFTWARE") {
         logiciel++;
      }

      // Mémorisation du nom lisible pour DIFFERENTES
      noms.insert(lisible[choix]);
      cout << nom << " " << lisible[choix] << "\n";
   }

   cout << "IGNOREES " << ignorees << "\n";
   cout << "LOGICIEL " << logiciel << "\n";
   cout << "DIFFERENTES " << noms.size() << "\n";

   return 0;
}
