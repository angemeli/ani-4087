## **Header conditionnel (classe complète et coquille vide)**

Le but de cet exercice était d'écrire un en-tête qui déclare une classe ou une coquille vide selon un define posé, et de compiler un programme qui l'emploie avec et sans ce define dans le fichier de projet.

L'en-tête et le fichier main.cpp, ainsi que le fichier de projet (Salle.jenga) contenant l'inclusion du define, sont disponibles dans le dossier SalleWorkspace associé au présent fichier .md

Afin d'éviter une influence des anciens fichiers de build, nous avons fait un coup de  `jenga clean` avant de reconstruire, pour cette deuxième tentative.

Nous avons retiré le bloc `#ifdef` (présent à la première remise de l'exercice), compilé et exécuté le projet en gardant dans le fichier de projet, la ligne `defines(["VERSION_COMPLETE"])`.
Puis nous l'avons refait cette fois en retirant cette ligne.

- ### **Première compilation (avec le define)**
L'exécution affiche `Le nombre vaut 32`

- ### **Deuxième compilation (sans le define)**
Un extrait de la compilation (après un coup de jenga clean) :

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

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  0/1
Failed:         1
Errors:         2
Time:           0.95s
Status:         ✗ FAILURE
```

Effectivement, comme mentionné dans le rapport de correction de notre première tentative, le retrait du define provoque une chaine d'erreurs et d'informations à la compilation :

```
error: no matching constructor for initialization    // Provoquée à la ligne Nombre obj(32);

note: candidate constructor (the implicit copy constructor) not viable: no known conversion from 'int' to 'const Nombre' for 1st argument    // Provoquée dans la déclaration de la coquille vide

note: candidate constructor (the implicit default constructor) not viable: requires 0 arguments, but 1 was provided    // Provoquée dans la déclaration de la coquille vide

error: no member named 'afficher' in 'Nombre'    // Provoquée à l'appel de la fonction afficher()
```

Puisque le define a été retiré, le bloc de code qu'il définit l'est aussi. Conséquence, le compilateur tombe sur la déclaration de la coquille vide plutôt que sur la déclaration propre de la classe :
- `Nombre obj(32)` lui demande de créer une instance de la classe Nombre, mais il ne trouve aucun constructeur pour le faire
- Il se retrouve en train de devoir convertir un entier en instance de classe
- La coquille vide ne demande aucun argument mais on lui demande d'en utiliser un
- Il ne retrouve pas la méthode "afficher" qui est appelée puisqu'elle n'existe pas

### **Lequel des deux messages aurait-on pu diagnostiquer ?**

Après cette revérification, il est évident que le cas sans le define est celui qui est le plus facile à diagnostiquer : Le compilateur se plaint et nous dit en détails ce qui arrive lorsqu'on omet le define. Contrairement au cas avec le define, qui compile et s'exécute sans problème. Avec ce cas, bien que l'éditeur de code mentionne une incohérence, le compilateur l'ignore et se contente d'éviter le piège.

Dans la version avec le define, on aurait pu s'attendre à une erreur de compilation plutôt qu'à une compilation réussie, vu le comportemet de l'éditeur de code. Le résultat obtenu dans ce cas montre que deux compilations du même fichier source peuvent produire des programmes structurellement différents, une notion qu'on ne comprend vraiment qu'après avoir pratiqué la compilation conditionnelle.
