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

- **Condition du filtre vraie : utilisation du système Windows (sur lequel nous travaillons)**

Le bloc du filtre en entier :

```
with filter("system:Windows") :
   usetoolchain("android-ndk")
   defines(["MON_FILTRE_ANDROID"])
   links(["android", "vulkan"])
```

La sortie de la commande `jenga info` est la suivante :

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

- **Condition du filtre fausse : Changement de système**

Le bloc du filtre est conservé, nous remplaçons juste Windows par Android (c'est cette version du bloc qui est visible sur le dépôt de cet exercice). `jenga info` affiche exactement la même chose qu'au cas précédent : il ne sait pas détecter si un filtre s'applique, même lorsqu'il s'applique.

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
║  Project: Salle                                                          Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                 Compilation Error: main.cpp                                  ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo14-le_filtre_android\ ║
║ SalleWorkspace\Salle\src\main.cpp:12:9: error: use of undeclared identifier 'fonction'       ║
║    12 |         fonction();                                                                  ║
║       |         ^~~~~~~~                                                                     ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo14-le_filtre_android\SalleWorkspace\Salle\src\main.cpp

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 3.01s  │
│ Errors: 2  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  0/1
Failed:         1
Errors:         2
Time:           3.02s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════
```

Par la suite, nous avons relancé le build, cette fois en précisant la plateforme cible : `jenga build --platform Android`

```
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Salle                                                          Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                Compilation Error: Link Failed                                ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ ld.lld: error: unable to find library -lvulkan                                               ║
║ clang++: error: linker command failed with exit code 1 (use -v to see invocation)            ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✗ Link failed: Build\Bin\Debug-Android\Salle\libSalle.so

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                Time: 10.51s  │
│ Errors: 2  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  0/1
Failed:         1
Errors:         2
Time:           10.51s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════
```

L'erreur change. Dans le premier cas, le compilateur ne trouve aucune définition de la fonction, car il ne voit pas ce qui est encadré par le filtre pour Android. Dans le deuxième cas, il trouve bien la définition : la précision `--platform Android` lui permet d'entrer dans le bloc qui définit le filtre, et de constater qu'il existe. L'erreur passe de `use of undeclared identifier 'fonction'` à `error: unable to find library -lvulkan (...) linker command failed with exit code 1.

Cette fois nous avons soumis les sorties de compilation en entier car certains détails ont attiré notre attention :

- Dans le premier cas (build pour Windows), le titre général de l'erreur est `Compilation Error: main`, et le processus total de build met 3.02 secondes.
- Dans le deuxième cas (build pour Android), le titre général de l'erreur change : `Compilation Error: Link Failed`, et le processus total de build met 10.51 secondes. 

Cet écart de temps énorme est révélateur, il montre que la deuxième construction a franchi une étape que la première n'a pas pu faire : la compilation complète des fichiers sources en objets. Le deuxième build échoue à l'étape finale de l'édition de lien. Les fichiers sources ont compilé avec succès, ce qui allonge le temps total de build par rapport au premier cas.

### **Résolution de l'erreur liée à la bibliothèque vulkan**

Pour résoudre cette erreur, nous sommes partis de l'interprétation de l'instruction `links(["android", "vulkan"])` écrite dans le fichier de projet. Cette instruction dit au linker qu'il faut le loader vulkan fourni par Android (`libvulkan.so`), peu importe si le projet en a réellement besoin. Afin de comprendre si c'est le cas, nous avons analysé le fichier du module `NKRHI.jenga`, qui est le module d'intégration pour la VR.

L'analyse de ce code nous a permis de comprendre qu'en réalité, Vulkan n'est jamais lié en dur, comme nous l'avons fait : il est toujours entouré par un `if WANT_VULKAN:`. Voici un extrait du code qui le montre :

Lignes 179 à 187

```
with filter("system:Android"):
   usetoolchain("android-ndk")
   # NK_OPENGL_ES est INDEPENDANT de Vulkan : le backend GL de NKRHI doit
   # TOUJOURS prendre ses chemins GLES sur Android (sinon il reference les
   # symboles glad desktop gl.c — glad_debug_* — jamais linkes ici).
   defines(["NK_OPENGL_ES"])
   _ANDROID_LINKS = ["android", "log", "EGL", "GLESv3"]
   if WANT_VULKAN:
      _ANDROID_LINKS.append("vulkan")
```

Le commentaire sur NK_OPENGL_ES confirme l'indépendance : **`NK_OPENGL_ES est INDEPENDANT de Vulkan : le backend GL de NKRHI doit TOUJOURS prendre ses chemins GLES sur Android (sinon il reference les symboles glad desktop gl.c — glad_debug_* — jamais linkes ici).`**

Donc le build de notre projet pour Android ne dépendait absolument pas de Vulkan. L'erreur soulevée, que nous avons mal interprétée, n'est pas la preuve que le build Android a besoin du module de Vulkan, c'est plutôt la preuve que notre filtre exige un module dont le build peut très bien se passer.

Après avoir compris cela, nous avons recherché le moyen de résoudre ce problème. Et cela s'est fait en 3 étapes :

- **Etape 1 : Nous avons supprimé vulkan du linker.** L'instruction devient désormais `links(["android"])` uniquement. L'exécution après cette étape nous a produit cette erreur :

```
║                                Compilation Error: Link Failed                                ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ ld.lld: error: undefined symbol: android_main                                                ║
║ >>> referenced by android_native_app_glue.c:226                                              ║
║ (C:\Users\Kindson\Desktop\Travaux\github\Teguis\Jenga\.jenga\compilers\android-ndk\sources\a ║
║ ndroid\native_app_glue/android_native_app_glue.c:226)                                        ║
║ >>>                                                                                          ║
║ C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo14-le_filtre_android\ ║
║ SalleWorkspace\Build\Obj\Debug-Android\Salle\android_native_app_glue.o:(android_app_entry)   ║
║ clang++: error: linker command failed with exit code 1 (use -v to see invocation)
```

Le linker est allé plus loin dans le processus et a coincé sur un problème différent : `android_native_app_glue.c` (le code standatd qui fait le pont entre Android et une application native C/C++), fourni par le NDK, attendait que notre propre code définisse le point d'entrée obligatoire de l'application pour Android, l'équivalent d'un `int main()` classique sur desktop. A ce stade, le fichier `main.c` ne l'avait pas encore. Ce qui nous a amené à la deuxième étape.

- **Etape 2 : Nous avons ajouté la fonction définissant le point d'entrée pour Android**

```
extern "C" void android_main(struct android_app* state) {
   // Point d'entrée de l'application sur Android
   cout << "Bonjour depuis Android\n";
}
```

`android_native_app_glue.c` est du C pur, pas du C++, et il appelle android_main avec le nom exact tel qu'il apparaît en C. `extern "C"` permet de dire au compilateur de ne pas mélanger le nom `android_main(android_app*)` en un nom encodé différement, et de générer le symbole `android_main` tel quel.

La compilation a fonctionné après cela, et le build de l'APK s'est fait avec succès.

```
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Salle                                                          Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Android\Salle\libSalle.so

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.93s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           1.93s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

ℹ Building APK for Salle (x86_64)
⚠ Debug keystore not found at C:\Users\Kindson\.android\debug.keystore - APK ne sera PAS signe ; Android refusera l'install. Generer via: keytool -genkeypair -keystore ~/.android/debug.keystore -alias androiddebugkey -storepass android -keypass android -keyalg RSA -validity 10000
✓ APK generated: C:\Users\Kindson\Desktop\Travaux\github\Teguis\ani-4087\chapitre-02\exo14-le_filtre_android\SalleWorkspace\Build\Bin\Debug-Android\Salle\android-build-x86_64\Salle-Debug.apk
```

**Note :** Jenga nous a retourné cet avertissement lié à la signature de l'application. Nous avons expliqué les concepts liés à la signature dans l'exercice 15 de ce chapitre.

```
CRITICAL WARNINGS (action requise) (1)                                       │
├──────────────────────────────────────────────────────────────────────────────┤
│   1. Debug keystore not found at C:\Users\Kindson\.android\debug.keystore - APK│
│      ne sera PAS signe ; Android refusera l'install. Generer via: keytool    │
│      -genkeypair -keystore ~/.android/debug.keystore -alias androiddebugkey  │
│      -storepass android -keypass android -keyalg RSA -validity 10000
```