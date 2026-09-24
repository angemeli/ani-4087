## **Le filtre pour Android et son activation**

Le but de cet exercice est d'ajouter dans le fichier de projet un filtre pour Android, et de prouver qu'il s'active bien. Pour cela, nous avons procédé ainsi :

- Nous avons écrit dans le fichier en-tête `filtre.hpp`, la définition d'une fonction qui n'est lue par le compilateur que si le filtre `MON_FILTRE_ANDROID` est défini. Puis nous avons écrit dans le fichier `main.cpp` le code qui affiche un message spécifique selon l'existence du filtre.

- Nous avons ajouté un bloc suivant dans le fichier de projet :

```
with filter("system:Android") :
   usetoolchain("android-ndk")
   defines(["MON_FILTRE_ANDROID"])
   links(["android", "vulkan"])
```

Ici nous précisons à Jenga quelle toolchain utiliser pour la compilation, et `links(["android", "vulkan"])` dit au linker de lier l'exécutable avec les bibliothèques android et vulkan (`libandroid.so`, la bibliothèque native de base d'Android, et `libvulkan.so`, le loader Vulkan fourni par Android).

### **La sortie de `jenga info`**

Elle ne change pas, que la condition du filtre soit vraie ou fausse. Les preuves suivent :

- **Condition du filtre vraie : ligne `defines(["MON_FILTRE_ANDROID"])` conservée**

```
======================= Jenga Workspace: SalleWorkspace ========================

Location: C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo14-le_filtre_android\SalleWorkspace
Entry file: C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo14-le_filtre_android\SalleWorkspace\SalleWorkspace.jenga
Configurations: Debug, Release
Platforms: Windows
Target OSes: Windows, Android
Target Architectures: x86_64, arm64


Projects
------------------------------------------------------------
Name    Kind          Language   Test   External
================================================
Salle   WindowedApp   C++        No     Yes


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


Daemon
------------------------------------------------------------
Status: Not running

PS C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo14-le_filtre_android\SalleWorkspace> jenga clean

╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

PS C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo14-le_filtre_android\SalleWorkspace> jenga info 

╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

======================= Jenga Workspace: SalleWorkspace ========================

Location: C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo14-le_filtre_android\SalleWorkspace
Entry file: C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo14-le_filtre_android\SalleWorkspace\SalleWorkspace.jenga
Configurations: Debug, Release
Platforms: Windows
Target OSes: Windows, Android
Target Architectures: x86_64, arm64


Projects
------------------------------------------------------------
Name    Kind          Language   Test   External
================================================
Salle   WindowedApp   C++        No     Yes


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


Daemon
------------------------------------------------------------
Status: Not running
```

- **Condition du filtre fausse : ligne `defines(["MON_FILTRE_ANDROID"])` commentée**

```
======================= Jenga Workspace: SalleWorkspace ========================

Location: C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo14-le_filtre_android\SalleWorkspace
Entry file: C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo14-le_filtre_android\SalleWorkspace\SalleWorkspace.jenga
Configurations: Debug, Release
Platforms: Windows
Target OSes: Windows, Android
Target Architectures: x86_64, arm64


Projects
------------------------------------------------------------
Name    Kind          Language   Test   External
================================================
Salle   WindowedApp   C++        No     Yes


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


Daemon
------------------------------------------------------------
Status: Not running
```

### **Comment vérifier que le filtre s'active bien pour Android ?**

Nous avons dans un premier temps, lancé la construction du projet par défaut (`jenga build`, construction pour windows). Le compilateur renvoie le message :

```
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                 Compilation Error: main.cpp ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo14-le_filtre_android\ ║
║ SalleWorkspace\Salle\src\main.cpp:12:9: error: use of undeclared identifier 'fonction' ║
║    12 |         fonction(); ║
║       |         ^~~~~~~~ ║
║ 1 error generated.
```

Par la suite, nous avons relancé le build, cette fois en précisant la plateforme cible : `jenga build --platform Android`

```
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                Compilation Error: Link Failed ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ ld.lld: error: unable to find library -lvulkan ║
║ clang++: error: linker command failed with exit code 1 (use -v to see invocation)
```

L'erreur change. Dans le premier cas, le compilateur ne trouve aucune définition de la fonction, car il ne voit pas ce qui est encadré par le filtre pour Android. Dans le deuxième cas, il trouve bien la définition : la précision `--platform Android` lui permet d'entrer dans le bloc qui définit le filtre, et de constater qu'il existe. L'erreur passe de `use of undeclared identifier 'fonction'` à `error: unable to find library -lvulkan (...) linker command failed with exit code 1.

A propos de cette erreur, nous sollicitons, dans le rapport de correction, une explication de sa cause et de comment la résoudre. Nous n'avons pas pu comprendre pourquoi elle apparaît malgré la précision faite au linker dans l'instruction `links(["android", "vulkan"])`.