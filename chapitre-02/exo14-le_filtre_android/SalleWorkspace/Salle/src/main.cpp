#include "filtre.hpp"
#include <iostream>

using namespace std;

int main() {
    #ifdef MON_FILTRE_ANDROID
        cout << "Le programme compile avec MON_FILTRE_ANDROID defini\n";
        fonction(); // L'appel n'est possible que si le filtre est valable
    #else
        cout << "Le programme compile sans MON_FILTRE_ANDROID defini\n";
        fonction();
    #endif
    return 0;
}

extern "C" void android_main(struct android_app* state) {
    // Point d'entrée de l'application sur Android
    cout << "Bonjour depuis Android\n";
}
