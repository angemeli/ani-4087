## **Le symbole non résolu : l'erreur de l'éditeur de liens**

- ### **Erreur provoquée**

Les deux modules concernés ici sont `somme.cpp` et `moyenne.cpp`. Il s'agit des mêmes modules utilisés à l'exercice 4 de ce chapitre (nous avons corrigé ici les types de données conformément à la remarque faite sur cet exercice là). Ces fichiers, ainsi que le Workspace complet, sont disponibles à côté du présent fichier .md

Pour provoquer une erreur, nous avons omis l'inclusion de **somme.cpp** dans le fichier de projet **Salle.jenga**. L'erreur d'édition de liens retournée au lancement de `jenga build` est la suivante :

```
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                Compilation Error: Link Failed                                ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\demo2-le_symbole_non_res ║
║ olu\SalleWorkspace\Build\Obj\Debug-Windows\Salle\src_main.obj: in function `main':           ║
║ C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\demo2-le_symbole_non_res ║
║ olu\SalleWorkspace\Salle\src/main.cpp:6:(.text+0x27): undefined reference to `somme(float,   ║
║ float)'                                                                                      ║
║ clang++: error: linker command failed with exit code 1 (use -v to see invocation)            ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✗ Link failed: Build\Bin\Debug-Windows\Salle\Salle.exe
```

Afin de se rassurer que c'est bien cette omission qui provoque cette erreur, nous avons remis le code original (`files(["src/**.cpp", "include/**.hpp"])`) dans le fichier de projet, et le build fonctionne normalement.

- ### **Quelle information désigne le module manquant ?**

La description de l'erreur interpelle : `undefined reference to 'somme(float, float)'`.

Lorsque le linker essaie de résoudre tous les symboles appelés vers leur adresse réelle (dans les fichiers .o fournis), il découvre qu'en réalité le symbole lié à `somme` n'existe nulle part. Il n'arrive à rien et provoque l'erreur qui nous intéresse. L'appel à la fonction somme ne peut être résolu, alors il retourne un message d'erreur en précisant quelle reférence n'a pas été définie.
