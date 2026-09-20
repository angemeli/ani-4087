## **Sortie fournie par la commande `jenga info` :**

```
======================= Jenga Workspace: SalleWorkspace ========================

Location: C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo1-le_projet_minimal\SalleWorkspace
Entry file: C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo1-le_projet_minimal\SalleWorkspace\SalleWorkspace.jenga
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

## **Ce que la sortie de `jenga info` apprend en plus :**

Le fichier de projet montre les configurations de base du projet (type d'application, langage de programmation, inclusion des fichiers de code source). Ce qu'il ne montre pas, c'est la totalité des propriétés du projet et des configurations qui lui sont applicables. Et c'est exactement ce que fait la commande `jenga info` : Elle fournit les détails techniques du projet (configurations choisies, plateformes cibles, architectures cibles, toolchains disponibles...).

- ### **Le point d'entrée de Jenga est un fichier différent du fichier de build du projet**

Jenga fait d'un autre fichier (`SalleWorkspace.jenga`) son point d'entrée. Pourtant il existe déjà un fichier .jenga (`Salle.jenga`) pour le projet. L'explication est simple : Le workspace (espace de travail) est l'environnement de développement qui contient les configurations, les dépendances et les outils liés au projet. C'est sur cet environnement que Jenga se base pour compiler le projet. Le projet est donc un niveau en dessous du workspace.

Ainsi deux ou plusieurs projets peuvent avoir le même workspace. C'est cette possibilité qui permet d'éviter de créer plusieurs environnements pour des projets qui peuvent en avoir un seul en commun.

Dans notre projet, le fichier de build est externe (External) car il est séparé du fichier de build du workspace. Il spécifie les configurations propres au projet, et donc il peut différer d'un projet à un autre. Il est lié au workspace grâce à la fonction `include()` utilisée dans `SalleWorkspace.jenga`.

- ### **Le fichier de projet ne mentionne pas toutes les configurations**

`jenga.info` liste toutes les configurations possibles pour le projet. Le fichier de projet ne mentionne que les configurations avec lesquelles il a été créé. Par exemple, le fichier de projet ne dit pas que le projet peut être compilé pour tourner sur d'autres plateformes que Windows, ou pour d'autres architectures que x86_64. Ces autres options existent pourtant dans le workspace, car ils sont définis à sa création. Le projet affiche ce qu'il utilise, le workspace affiche ce qu'il a.

- ### **Le démon et son impact lorsqu'il tourne**

Le démon est un programme qui sert à fournir un service en continu sans qu'on ait besoin de le déclencher manuellement. Lorsqu'il tourne, il écoute en permanence les commandes envoyées, écoute les évènements en continu et persiste entre les sessions d'utilisation. Par conséquent lorsqu'il ne tourne pas, certaines tâches et constructions attendent une intervention manuelle pour s'exécuter, ce qui ralentit les programmes.
