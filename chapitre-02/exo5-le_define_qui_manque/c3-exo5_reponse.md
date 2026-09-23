## **Header conditionnel (classe complète et coquille vide)**

Le but de cet exercice était d'écrire un en-tête qui déclare une classe ou une coquille vide selon un define posé, et de compiler un programme qui l'emploie avec et sans ce define dans le fichier de projet.

L'en-tête et le fichier main.cpp, ainsi que le fichier de projet (Salle.jenga) contenant l'inclusion du define, sont disponibles dans le dossier SalleWorkspace associé au présent fichier .md

Nous avons compilé et exécuté le projet en ajoutant, dans le fichier de projet, la ligne `defines(["VERSION_COMPLETE"])` (VERSION_COMPLETE est le define qui nous intéresse). Puis nous l'avons refait cette fois en retirant cette ligne. Dans les deux cas, les compilations réussissent sans faute, et les deux messages à l'exécution sont différents.

- ### **Première compilation (avec le define)**
Le message en sortie est `Le nombre vaut 32`

- ### **Deuxième compilation (sans le define)**
Le message en sortie est `Coquille vide, sans details.`

### **Lequel des deux messages aurait-on pu diagnostiquer ?**

La version complète, avec le define, est celle que nous aurions pu diagnostiquer. Sans avoir manipulé de compilation conditionnelle, on s'attendrait naturellement à ce qu'un programme qu'on a écrit et appelé explicitement dans main fasse ce pourquoi il est écrit.

La version de la coquille vide est beaucoup moins intuitive lorsqu'on a pas compris le mécanisme `#ifdef/#else`. On aurait pu s'attendre même à une erreur de compilation plutôt qu'à une compilation réussie. Le résultat obtenu dans ce cas montre que deux compilations du même fichier source peuvent produire des programmes structurellement différents, une notion qu'on ne comprend vraiment qu'après avoir pratiqué la compilation conditionnelle.
