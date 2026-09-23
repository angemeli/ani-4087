#include "filtre.hpp"
#include <iostream>

using namespace std;

int main() {
    #ifdef __linux__
        cout << "Le programme compile avec __linux__ defini\n";
        fonction(); // L'appel n'est possible que si la macro est vraie
    #else
        cout << "Le programme compile sans __linux__ defini";
        // fonction(); // Cette ligne reste commentée afin d'éviter une erreur de compilation
    #endif
    return 0;
}
