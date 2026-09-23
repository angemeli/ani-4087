#ifndef FILTRE_HPP
#define FILTRE_HPP

#include <iostream>

#ifdef _WIN32
   #include <windows.h> // Bibliothèque spécifique pour Windows
   void fonction() {
      std::cout << "Cette fonction ne compile que sous Windows";
   }

#elifdef __linux__
   #include <unistd.h> // Bibliothèque spécifique pour Linux
   void fonction() {
      std::cout << "Cette fonction ne compile que sous Linux";
   }

#else
   #error "Systeme non supporte"

#endif
#endif // FILTRE_HPP