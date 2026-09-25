## **Demo : La coquille vide**

Ici, il était question de compiler le projet avec et sans le define qui entoure une classe créée. Nous avons compilé directement sur le projet de l'exercice 5 de ce chapitre, les fichiers y sont disponibles. Voici l'en-tête qui nous concerne :

```
#ifndef NOMBRE_HPP
#define NOMBRE_HPP

#ifdef VERSION_COMPLETE

// Version complète de la classe
class Nombre {
   public :
      Nombre(int valeur);
      void afficher() const;

   private :
      int m_valeur;
};

#else

// Coquille vide
class Nombre {

};

#endif // VERSION COMPLETE
#endif // NOMBRE_HPP
```

Le fichier `main.cpp` qui l'utilise :

```
#include "nombre.hpp"
#include <iostream>

using namespace std;

int main() {
   Nombre obj(32);
   obj.afficher();
   return 0;
}
```

- La compilation avec le define (dans le fichier de projet, on décommente la ligne `#defines(["VERSION_COMPLETE"])`) se termine normalement, et l'exécution affiche `Le nombre vaut 32`.

- La compilation sans le define (on laisse cette ligne commentée) produit ceci :

```
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                 Compilation Error: main.cpp║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo5-le_define_qui_manqu║
║ e\SalleWorkspace\Salle\src\main.cpp:7:12: error: no matching constructor for initialization║
║ of 'Nombre'║
║     7 |     Nombre obj(32);║
║       |            ^   ~~║
║ C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo5-le_define_qui_manqu║
║ e\SalleWorkspace\Salle\include/nombre.hpp:19:7: note: candidate constructor (the implicit║
║ copy constructor) not viable: no known conversion from 'int' to 'const Nombre' for 1st║
║ argument║
║    19 | class Nombre {║
║       |       ^~~~~~║
║ C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo5-le_define_qui_manqu║
║ e\SalleWorkspace\Salle\include/nombre.hpp:19:7: note: candidate constructor (the implicit║
║ default constructor) not viable: requires 0 arguments, but 1 was provided║
║ C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo5-le_define_qui_manqu║
║ e\SalleWorkspace\Salle\src\main.cpp:8:9: error: no member named 'afficher' in 'Nombre'║
║     8 |     obj.afficher();║
║       |     ~~~ ^║
║ 2 errors generated.║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo5-le_define_qui_manque\SalleWorkspace\Salle\src\main.cpp
✓   [2/2] Compiled: nombre.cpp

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 0.95s│
│ Errors: 2  | Failed files: 1│
└──────────────────────────────────────────────────────────────────────────────────────────────┘
```

