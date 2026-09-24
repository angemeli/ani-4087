## **Lecture et description du fichier de projet de la démonstration XR du moteur Nkentseu**

Ce fichier se trouve dans le répertoire `Nkentseu\Applications\NKXRDemo` (le fichier `NKXRDemo.jenga`)

### **Qu'est-ce qu'il construit ?**

```
NKXRDemo — une demo VR "Étage 0" de la mission NKXR
```

C'est une démo de réalité virtuelle, sans vrai casque VR. C'est simulé sur PC : on bouge la souris pour tourner la tête, et le clavier (système de touches WASD/ZQSD) est utilisé pour se déplacer. L'écran affiche deux images côte à côte (une par oeil), comme dans un vrai casque VR, mais générées sur le PC.

### **De quoi dépend-t-il ?**

Il repose sur plusieurs modules du moteur Nkentseu déjà existants (des détails sur ces modules sont déjà donnés à l'exercice 7) :

```
nkentseudependson(
   ["NKXR", "NKRenderer", "NKRHI", "NKSL", "NKGLSlang", "NKSPIRVCross",
   "NKSerialization", "NKReflection", "NKFileSystem", "NKFont", "NKImage", "NKGlad",
   "NKEvent", "NKWindow", "NKMath", "NKTime", "NKLogger", "NKStream",
   "NKContainers", "NKMemory", "NKCore", "NKPlatform", "NKThreading"],
   extra_includes=["src",
                  # NkVulkanDevice.h (liaison OpenXR) tire vulkan.h.
                  "%{wks.location}/Externals/Libs/Vulkan-Headers-1.4.350/include"],
)
```

### **Ce qui change selon le système d'exploitation**

Le code s'adapte à Windows, Linux et macOS. Chacun a besoin de bibliothèques système différentes pour marcher (Windows utilise ses propres outils graphiques, Linux utilise X11, macOS utilise Cocoa). Ce que le code fait, c'est brancher les bons outils selon le système d'exploitation sur lequel il tourne.

### **Les 3 pièges qui arrivent**

- **Deux bibliothèques spéciales à ajouter à la main** : En principe, lorsqu'on ajoute un module, tout ce dont il a besoin suit automatiquement, mais pas les modules `NKGLSlang` et `NKSPIRVCross`. Si elles ne sont pas manuellement ajoutées, le programme compile mais le linker bloque à la fin.

- **L'interrupteur `NK_RHI_VK_ENABLED` active le vrai code Vulkan** au lieu d'une version vide. Sans ça, le code ne compile pas, car la partie VR a besoin de la version originale.

- **La bibliothèque Windows `advapi32`** sert à lire le registre Windows, elle est utilisée pour détecter quel logiciel de réalité virtuelle tourne sur la machine. Si elle est oubliée, le programme compile mais le linker plante sous Windows.
