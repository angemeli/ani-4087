#include "nombre.hpp"
#include <iostream>

using namespace std;

int main() {
    #ifdef VERSION_COMPLETE
        Nombre obj(32);
        obj.afficher();
    #else
        Nombre obj;  // instance de la coquille vide
        cout << "Coquille vide, sans details." << endl;
    #endif
    return 0;
}
