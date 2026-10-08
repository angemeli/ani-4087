#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
   map<string, string> lisible = {
      {"VULKAN", "Vulkan"}, {"DX12", "DirectX 12"}, {"DX11", "DirectX 11"},
      {"OPENGL", "OpenGL"}, {"METAL", "Metal"}, {"SOFTWARE", "Software"}};

   map<string, vector<string>> ordres = {
      {"WINDOWS", {"VULKAN", "DX12", "DX11", "OPENGL", "SOFTWARE"}},
      {"MACOS", {"METAL", "OPENGL", "SOFTWARE"}},
      {"IOS", {"METAL", "SOFTWARE"}},
      {"ANDROID", {"VULKAN", "OPENGL", "SOFTWARE"}}};

   vector<string> parDefaut = {"VULKAN", "OPENGL", "SOFTWARE"};

   int n;
   cin >> n;
   int ignorees = 0, logiciel = 0;
   set<string> noms;

   for (int i = 0; i < n; i++) {
      string nom, plateforme;
      int k;
      cin >> nom >> plateforme >> k;
      set<string> apis;

      for (int j = 0; j < k; j++) {
         string a;
         cin >> a;
         apis.insert(a);
      }

      const vector<string>& ordre =
         ordres.count(plateforme) ? ordres[plateforme] : parDefaut;

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

      noms.insert(lisible[choix]);
      cout << nom << " " << lisible[choix] << "\n";
   }

   cout << "IGNOREES " << ignorees << "\n";
   cout << "LOGICIEL " << logiciel << "\n";
   cout << "DIFFERENTES " << noms.size() << "\n";

   return 0;
}
