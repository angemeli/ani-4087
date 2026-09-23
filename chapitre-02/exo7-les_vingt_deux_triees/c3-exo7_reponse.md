## **Classement des 23 dépendances du moteur Nkentseu**

Il s'agit ici de trouver les dépendances du moteur Nkentseu pour la réalité virtuelle, puis de les classer selon leur niveau de compréhension au vu de leur nom.

**Note** : Ces dépendances sont visibles dans le code source du fichier `NKXRDemo.jenga` (Le chemin depuis le dossier original Nkentseu : `Applications/NKXRDemo/`), lignes 26 à 29.

````
NKXR, NKRenderer, NKRHI, NKSL, NKGLSlang, NKSPIRVCross,
NKSerialization, NKReflection, NKFileSystem, NKFont, NKImage, NKGlad,
NKEvent, NKWindow, NKMath, NKTime, NKLogger, NKStream,
NKContainers, NKMemory, NKCore, NKPlatform, NKThreading
```

### **Groupe 1 : Dépendances dont le nom suffit à deviner le rôle**

Celles ci sont facilement reconnaissables car elles utilisent des termes standard (Window, Math, Time...)

| Dépendance | Rôle |
| ---------- | ---- |
| NKRenderer | Moteur / sous-système de rendu graphique |
| NKFileSystem | Gestion du système de fichiers (lecture, écriture, accès) |
| NKFont | Chargement et rendu des polices de caractères |
| NKImage | Traitement d'images (décodage, encodage et manipulation) |
| NKEvent | Gestion des évènements (entrées utilisateur, évènements système...) |
| NKWindow | Création et gestion de la fenêtre d'affichage |
| NKMath | Bibliothèque mathématique (vecteurs, matrices, quaternions, transformations 3D...) |
| NKTime | Gestion du temps : horloge, fréquence de rafraichissement... |
| NKMemory | Gestionnaire de mémoire |
| NKPlatform | Gestion de la plateforme hôte (Windows, Linux, Android...) |
| NKThreading | Gestion du multi-threading : threads, mutex... |

### **Groupe 2 : Dépendances avec des idées sans certitude**

| Dépendance | Rôle probable |
| ---------- | ---- |
| NKSerialization | Probablement lié à la sérialisation des données (sauvegarde/chargement d'états et formats de fichiers) |
| NKReflection | Inspection générale du code à la compilation |
| NKLogger | Système de gestion des logs et traces de débogage et de sorties console |
| NKStream | Gestion des flux de données |
| NKContainers | Structures de données telles que les tableaux, les files... |
| NKXR | Module d'intégration pour la réalité virtuelle |
| NKCore | Module regroupant les utilitaires de base et l'initialisation du moteur |

### **Groupe 3 : Dépendances où nous n'avons aucune idée**

Ce groupe est composé de NKRHI, NKSL, NKGLSlang, NKSPIRVCross, NKGlad

- **NKRHI** (fichier ouvert : `Kernel\Runtime\NKRHI\src\NKRHI\NKRHI.h`) : Cette dépendance est un module d'intégration autour d'OpenXR ou un autre SDK de VR pour la réalité virtuelle.

- **NKSL** (`Kernel\Runtime\NKSL\src\NKSL\NKSL.h`) : Nkentseu Shader Language, c'est le langage d'ombrage propre au moteur Nkentseu

- **NKGLSlang** (`Externals/Libs/NKGLSlang/glslang/Public/ShaderLang.h`) : Intégration du compilateur Khronos `glslang` pour traduire le GLSL en SPIR-V

- **NKSPIRVCross** (`Externals/Libs/NKSPIRVCross/src/spirv_cross/spirv_cross.hpp`) : C'est un wrapper autour de l'outil tiers SPIRV-Cross pour convertir du bytecode SPIR-V vers d'autres langages d'ombrage

- **NKGlad** (`Externals/Libs/NKGlad/include/glad/gl.h`) : C'est une intégration ou un wrapper de la bibliothèque tiers Glad