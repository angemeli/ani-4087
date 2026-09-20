## **Mesures des durées de build et d'exécution par configuration**

Pour cet exercice, nous avons effectué 3 builds pour chaque configuration, et nous avons relevé à chaque fois les tailles des fichiers exécutables.

- **Construction en Debug**

Les durées de build sont : 1.23s, 1.21s et 1.21s.
La taille de l'exécutable est à chaque fois de 136 ko.

- **Construction en Release**

Les durées de build sont : 1.19s, 1.18s et 1.19s.
La taille de l'exécutable est à chaque fois de 136 ko.

## **Ce que l'on en déduit**

La construction en Debug et la construction en Release produisent un fichier exécutable qui ne change jamais de taille. Ce qui est normal vu que les deux créent un fichier qui est identique d'une configuration à une autre.

Cependant on constate que le Release est légèrement plus rapide que le Debug (on a à chaque fois un gain de temps d'environ 0.03s, soit environ 30ms). 

Cela peut s'expliquer par le fait que la Debug sacrifie volontairement la vitesse d'exécution pour fournir des informations utiles au débogage de code. Le build Debug envoie des informations que la Release ne fournit pas souvent : noms de variables, numéros de lignes, symboles... Pour permettre au programmeur de comprendre la façon dont la machine interprète le code source. En configuration Release par contre, le compilateur applique des optimisations afin de maximiser la performance de l'application.
