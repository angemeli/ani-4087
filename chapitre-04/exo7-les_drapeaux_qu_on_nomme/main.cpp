#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Dependance {
   string drapeau;
   vector<string> besoins;
};

int main() {
   // Les treize drapeaux simples
   vector<string> simples = {
      "RENDER2D", "RENDER3D", "TEXT", "UI", "SHADOW", "POST_PROCESS", "VFX",
      "ANIMATION", "OVERLAY", "SIMULATION", "OFFSCREEN", "RAYTRACING", "GPU_CULLING"};

   // Table nom - valeur
   map<string, uint32_t> valeurs = {
      {"RENDER2D", 1}, {"RENDER3D", 2}, {"TEXT", 4}, {"UI", 8},
      {"SHADOW", 16}, {"POST_PROCESS", 32}, {"VFX", 64}, {"ANIMATION", 128},
      {"OVERLAY", 256}, {"SIMULATION", 512}, {"OFFSCREEN", 1024},
      {"RAYTRACING", 2048}, {"GPU_CULLING", 4096},
      {"NONE", 0}, {"2D_ESSENTIALS", 1 | 4}, {"3D_BASE", 2 | 16 | 32},
      {"DEBUG", 256 | 512}, {"ALL", 4294967295U}};

   // Dépendances
   vector<Dependance> dependances = {
      {"TEXT", {"RENDER2D"}},
      {"UI", {"RENDER2D", "TEXT"}},
      {"SHADOW", {"RENDER3D"}},
      {"OVERLAY", {"RENDER2D", "TEXT"}}};

   int n;
   cin >> n;

   // La valeur part de 0, si rien n'est nommé, la configuration par défaut est ALL
   uint32_t valeur = 0;
   if (n == 0) {
      valeur = valeurs["ALL"];
   }

   // Lecture des noms : un nom reconnu se combine par OU, un nom inconnu est signalé sans rien changer
   for (int i = 0; i < n; i++) {
      string nom;
      cin >> nom;

      if (valeurs.count(nom)) {
         valeur |= valeurs[nom];
      } 
      else {
         cout << "INCONNU " << nom << "\n";
      }
   }

   // Valeur en décimal, puis en hexadécimal sur huit chiffres majuscules
   cout << "VALEUR " << valeur << "\n";
   cout << "HEXA 0x" << hex << uppercase << setfill('0') << setw(8) << valeur << "\n";
   cout << dec << nouppercase << setfill(' ');

   // Dépendances absentes : seuls les drapeaux allumés réclament quelque chose
   for (const Dependance& d : dependances) {
      if ((valeur & valeurs[d.drapeau]) == 0) {
         continue;
      }
      for (const string& besoin : d.besoins) {
         if ((valeur & valeurs[besoin]) == 0) {
            cout << "MANQUE " << d.drapeau << " " << besoin << "\n";
         }
      }
   }

   // Bilan : drapeaux simples allumés dans la valeur finale
   int allumes = 0;
   for (const string& s : simples) {
      if ((valeur & valeurs[s]) != 0) {
         allumes++;
      }
   }

   cout << "ALLUMES " << allumes << "\n";
   cout << "ETEINTS " << simples.size() - allumes << "\n";

   return 0;
}
