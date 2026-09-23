#ifndef FILTRE_HPP
#define FILTRE_HPP

#include <iostream>
using namespace std;

#ifdef MON_FILTRE
void fonction() {
   cout << "Cette fonction ne compile que si MON_FILTRE existe";
}
#endif
#endif // FILTRE_HPP