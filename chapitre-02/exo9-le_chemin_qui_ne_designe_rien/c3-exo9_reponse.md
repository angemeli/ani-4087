## **Fichier et dossier qui n'existent pas : Comment se comporte Jenga ?**

Pour cet exercice, nous avons ajouté dans le fichier `Salle.jenga` un fichier et un dossier qui n'existent pas dans le projet : le fichier `fantome.cpp` et le dossier `ghost`

```
with project("Salle") :
   windowedapp()
   language("C++")
   cppdialect("C++17")
   location(".")
   includedirs(["ghost"])     // Dossier fantôme
   files(["src/main.cpp", "src/fantome.cpp", "include/**.hpp"])      /// Fichier fantôme
```

### **Comment se comporte Jenga ?**

Le résultat de la commande `jenga info` est le suivant :

```
======================= Jenga Workspace: SalleWorkspace ========================

Location: C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo9-le_chemin_qui_ne_designe_rien\SalleWorkspace
Entry file: C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo9-le_chemin_qui_ne_designe_rien\SalleWorkspace\SalleWorkspace.jenga
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

La commande ne fournit aucune information sur les fichiers ou dossiers manquants (ce qui, en soi, est quand même prévisible) : ``jenga info` ne fait que lire l'état actuel du projet et lister les configurations et les informations générales du projet, et ne s'infiltre pas dans les dossiers et sous-dossiers du projet pour lire le code, faire un lien avec les fichiers existants et dire ce qui manque.

Le résultat de la commande `jenga build` est le suivant :

```
Loading workspace...

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (1 projects):
  1. Salle [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Salle                                                          Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\Salle\Salle.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.24s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           1.24s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

Le code compile normalement. Et un message en particulier nous interpelle :

```
Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
```

`Found 1 source file(s)`. En d'autres termes, le compilateur ne trouve qu'un seul fichier code source, bien que deux fichiers aient été explicitement déclarés dans `Salle.jenga`.

La commande jenga build est celle qui nous aurait fait gagner plus de temps. Le fait que le compilateur ne trouve qu'un fichier est significatif : Il ne fait pas aveuglément confiance au fichier de projet en tentant de compiler directement les fichiers sans vérifier qu'ils existent, il parcourt lui-même l'ensemble des programmes et trouve les fichiers qui sont réellement présents pour les compiler. 

Cela montre (à notre surprise) que le système de build ne provoque pas d'erreur s'il ne trouve pas des fichiers déclarés dans le fichier de projet, et que la compilation se compile normalement. Contrairement à ce à quoi nous nous attendions avant de résoudre l'exercice.
