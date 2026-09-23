#include "filtre.hpp"
#include <iostream>

using namespace std;

int main() {
    #ifdef MON_FILTRE
        cout << "Le programme compile avec MON_FILTRE defini\n";
        fonction(); // L'appel n'est possible que si la macro est vraie
    #else
        cout << "Le programme compile sans MON_FILTRE defini";
        // fonction(); // Cette ligne reste commentée afin d'éviter une erreur de compilation
    #endif
    return 0;
}
