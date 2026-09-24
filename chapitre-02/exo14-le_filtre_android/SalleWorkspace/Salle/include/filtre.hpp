#ifndef FILTRE_HPP
#define FILTRE_HPP

#include <iostream>
using namespace std;

#ifdef MON_FILTRE_ANDROID
void fonction() {
   cout << "Cette fonction ne compile que si MON_FILTRE_ANDROID existe";
}
#endif
#endif // FILTRE_HPP