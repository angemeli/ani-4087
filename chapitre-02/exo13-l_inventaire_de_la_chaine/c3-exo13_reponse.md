## **`jenga info -v` : les toolchains**

Les toolchains affichées par la commande sont les suivantes :

```
Available Toolchains
------------------------------------------------------------
Name                Family        Target OS   Arch     Env    
==============================================================
host-clang          clang         Windows     x86_64   mingw
host-gcc            gcc           Windows     x86_64   mingw
clang-mingw         clang         Windows     x86_64   mingw
mingw               gcc           Windows     x86_64   mingw
clang-cross-linux   clang         Linux       x86_64   gnu
android-ndk         android-ndk   Android     arm64    android
```

### **Ce qui est présent et ce qui manque**

La machine possède 6 chaines d'outils de compilation, dont les descriptions sont les suivantes :

- Les toolchains `host-gcc` et `mingw`, de la famille gcc, produisent du code pour le système Windows en x86_64 via l'environnement MinGW
- `host-clang` et `clang-mingw` de la famille clang font pareil avec la même cible et la même architecture.

**Remarque** : La redondance des toolchains qui compilent pour windows s'explique par une double installation : Nous avions gcc installé depuis longtemps sur la machine, ce qui rendait les toolchains `host-gcc` et `mingw` disponibles. Puis nous avons récemment installé clang, qui a fourni `host-clang` et `clang-mingw` pour le même travail.

Jenga a une commande de détection automatique de toolchain (`jenga install toolchain detect`). Les deux entrées **"host-"** (`host-gcc` et `host-clang`) sont le résultat de cette autodétection : Jenga scanne la machine, trouve Clang et GCC déjà installés vis MSYS2, et les enregistre sous ces noms génériques.

Quant à `clang-mingw`, c'est la toolchain officiellement utilisée pour compiler Nkentseu sous Windows, et elle est liée à `msys64/ucrt64`. C'est pour cela qu'elle existe en plus de `host-clang` : c'est la version garantie du projet, indépendante de ce qui est déjà sur la machine via la variable d'environnement `path`.

- `clang-cross-linux`, toujours de la famille clang, tourne sur Windows (notre système à nous), mais produit du code pour Linux x86_64, avec l'environnement GNU de Linux. Spécifique pour la compilation croisée. 
- `android-ndk`, de la famille android-ndk, est le compilateur du Native Development Kit (NDK) d'Android (installé via `jenga install toolchain install android-ndk --path /path/to/ndk`). Il compile le code pour les systèmes Android en arm64. Son environnement est l'environnement Android Natif.

**Note** : 

Pour les différents systèmes d'exploitation cibles de nos projets (Windows, Linux, Android), aucune toolchain ne manque.
