## **Info contre build**

Pour cette démo, nous avons provoqué volontairement une erreur dans le fichier `Salle.jenga`. Puis nous vons lancé respectivement les commandes `jenga build` et `jenga info`.

Nous le disons avec franchise : cette démo, tout comme les autres démos de ce chapitre, n'a pas été travaillée avec la classe.

- ### **L'erreur provoquée**

Le code initial du fichier de projet est le suivant :

```
from Jenga import *

with project("Salle") :
   windowedapp()
   language("C++")
   cppdialect("C++17")
   location(".")
   files(["src/**.cpp", "include/**.hpp"])
```

Afin de provoquer une erreur, nous avons modifié la dernière ligne en supprimant un `p` à `.cpp`, et donc mentionné un format de fichier non reconnu : `files(["src/**.cp", "include/**.hpp"])`. Cette version est disponible dans la version actuelle du fichier de projet.

- **Observation avec `jenga build` :**

```
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Salle                                                          Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

No source files found for project Salle

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           0.01s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

Le message `No source files found for project Salle` interpelle : Jenga ne trouve aucun fichier source pour le projet, ce qui est normal vu le format qui lui est passé (`.cp`)

- **Observation avec `jenga info` :**

```
======================= Jenga Workspace: SalleWorkspace ========================

Location: C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\demo1-info_contre_build\SalleWorkspace
Entry file: C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\demo1-info_contre_build\SalleWorkspace\SalleWorkspace.jenga
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

Cette commande ne renseigne aucune information montrant une erreur dans le fichier de projet. C'est la commande de build qui permet de comprendre la cause du message affiché.