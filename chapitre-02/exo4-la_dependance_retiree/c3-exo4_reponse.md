## **Détection et explication de l'erreur obtenue après retrait d'un fichier de la liste**

- ### **Structure des fichiers et erreur provoquée**

Les deux modules concernés ici sont `somme.cpp` et `moyenne.cpp`. On part du principe (un principe vrai) que pour calculer la moyenne de deux nombres entiers, on a besoin de connaître leur somme. Le but est donc de retirer le module somme.cpp, qui est le module dont dépend moyenne.cpp, et voir comment réagit Jenga lors du build.

Ces fichiers, ainsi que le Workspace complet, sont disponibles à côté du présent fichier .md

Pour provoquer une erreur, conformément à la consigne de l'exercice, nous avons omis l'inclusion de **somme.cpp** dans le fichier de projet **Salle.jenga** (nous avons remplacé la ligne `files(["src/**.cpp", "include/**.hpp"])` par cette instruction : `files(["src/main.cpp", "src/moyenne.cpp", "include/**.hpp"])`). L'erreur retournée au lancement de `jenga build` est la suivante :

```Compilation Error: Link Failed                                ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo4-la_dependance_retir ║
║ ee\SalleWorkspace\Build\Obj\Debug-Windows\Salle\src_main.obj: in function `main':            ║
║ C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo4-la_dependance_retir ║
║ ee\SalleWorkspace\Salle\src/main.cpp:6:(.text+0x21): undefined reference to `somme(int,      ║
║ int)'                                                                                        ║
║ clang++: error: linker command failed with exit code 1 (use -v to see invocation)            ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✗ Link failed: Build\Bin\Debug-Windows\Salle\Salle.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 1.28s  │
│ Errors: 2  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  0/1
Failed:         1
Errors:         2
Time:           1.28s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ Salle```

Afin de se rassurer que c'est bien cette omission qui provoque cette erreur, nous avons remis le code original (`files(["src/**.cpp", "include/**.hpp"])`) dans le fichier de projet, et le build fonctionne normalement (Le build a été refait après avoir lancé `jenga clean` pour supprimer les anciens fichiers liés au build précédent et éviter qu'ils n'aient un impact).

- ### **Analyse de l'erreur**

Le titre et la description de l'erreur interpellent :

```
Compilation Error: Link Failed
(...) **undefined reference** to `somme(int, int)`
clang++: error: **linker command failed with exit code 1 (use -v to see invocation)**
```

Les deux modules compilent normalement, chacun de façon séparée. La chaîne de construction ne bloque donc pas au niveau de la compilation. C'est lorsqu'il faut lier les fichiers .o générés que le problème se pose (donc à l'étape **d'édition des liens**) :

- Le préprocesseur (#include) ne se soucie pas des dépendances entre modules, juste des fichiers texte inclus
- Le compilateur transforme les fichiers .cpp en fichiers objets. Tant qu'il y a un prototype de la fonction du module retiré, il génère l'appel sans vérifier que le code existe réellement
- L'assemblage non plus utilise la même logique, donc il ne change rien
- C'est à l'édition de liens, lorsque le linker essaie de résoudre tous les symboles appelés vers leur adresse réelle (dans les fichiers .o fournis), qu'il découvre qu'en réalité le symbole n'existe nulle part. Conséqence, il n'arrive à rien et provoque l'erreur qui nous intéresse.
