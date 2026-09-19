## **Sortie fournie par la commande ``jenga info`` :**

```
======================= Jenga Workspace: SalleWorkspace ========================

Location: C:\Users\Kindson\Desktop\Travaux\github\Teguis\Projets Jenga\SalleWorkspace
Entry file: C:\Users\Kindson\Desktop\Travaux\github\Teguis\Projets Jenga\SalleWorkspace\SalleWorkspace.jenga
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

## **Ce que la sortie de ``jenga info`` apprend en plus :**

Le fichier de projet montre les configurations de base du projet (type d'application, langage de programmation, inclusion des fichiers de code source). Ce qu'il ne montre pas, c'est la totalité des propriétés du projet et des configurations qui lui sont applicables. Et c'est exactement ce que fait la commande ``jenga info`` : Elle fournit les détails techniques du projet (configurations choisies, plateformes cibles, architectures cibles, toolchains disponibles...).

C'est justement pour cette raison que le cours précise que c'est la première commande à lancer avant de déployer le projet : Elle permet de comprendre clairement ce que Jenga peut faire de l'application qu'on construit.
