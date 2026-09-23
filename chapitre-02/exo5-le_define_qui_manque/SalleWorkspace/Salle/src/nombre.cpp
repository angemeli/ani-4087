#include <iostream>
#include "nombre.hpp"

using namespace std;

#ifdef VERSION_COMPLETE

Nombre::Nombre(int valeur) : m_valeur(valeur) {}

void Nombre::afficher() const {
   cout << "Le nombre vaut " << m_valeur << endl;
}

#endif // VERSION_COMPLETE