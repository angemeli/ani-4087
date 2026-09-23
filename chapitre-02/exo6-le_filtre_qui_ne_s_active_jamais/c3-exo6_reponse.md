## **Le filtre qui ne s'active jamais : preuves**

Le but de cet exercice est de prouver qu'un filtre dont la condition est fausse sur une machine ne s'active jamais. Pour cela nous avons défini une fonction dans un fichier en-tête (`filtre.hpp`), qui n'est conservée par le préprocesseur que si la macro `__linux__` est définie. Ce qui n'est pas le cas, puisque nous utilisons le système Windows.

L'ensemble des fichiers et le workspace sont disponibles, joints au présent .md

### **Preuve que la condition est fausse : Compilation sur Windows**

La compilation fonctionne (nous avons commenté la ligne d'appel à la fonction afin d'éviter une erreur et de voir le message affiché), l'exécution affiche `Le programme compile sans __linux__ defini`.

La preuve que la fonction n'est pas appliquée est claire : Lorsque nous décommentons l'appel à la fonction, l'éditeur de code nous signale directement, et la compilation le confirme :

![Ligne d'appel décommentée](Capture.png)

```
══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                 Compilation Error: main.cpp                                  ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo6-le_filtre_qui_ne_s_ ║
║ active_jamais\SalleWorkspace\Salle\src\main.cpp:12:9: error: use of undeclared identifier    ║
║ 'fonction'                                                                                   ║
║ 12 |         fonction(); // Cette ligne reste commentée afin d'éviter une erreur de          ║
║ compilation                                                                                  ║
║       |         ^~~~~~~~                                                                     ║
║ 1 error generated.
```

Cette erreur prouve que le préprocesseur a bien retiré le bloc de définition de la fonction, elle n'existe absolument pas dans le code compilé.

### **Preuve que la condition rendue vraie l'est**

Ici, nous allons artificiellement forcer la macro : nous allons inclure __linux__ dans les defines du projet, dans Salle.jenga. L'exécution affiche, conformément à ce qui est prévu si la condition est vraie :
```
Le programme compile avec __linux__ defini
```
Puis :
```
Cette fonction ne compile que sous Linux
```

Cette fois, la fonction est bien présente et appelable. Le fait que la condition réussisse ici s'explique par le comportement du préprocesseur : il ne fait aucune différence entre une macro définie naturellement par le compilateur sous un système, et une macro forcée dans un programme (comme c'est le cas dans le notre). Les deux sont traitées de façon identique.