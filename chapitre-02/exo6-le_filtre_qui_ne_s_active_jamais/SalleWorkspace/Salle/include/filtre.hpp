#ifndef FILTRE_HPP
#define FILTRE_HPP

#include <iostream>
using namespace std;

#ifdef __linux__
void fonction() {
   cout << "Cette fonction ne compile que sous Linux";
}
#endif
#endif // FILTRE_HPP