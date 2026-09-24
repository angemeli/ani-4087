## **La clé de signature**

### **Ce que nous avons compris à propos des clés de signature**

Avant de rendre les éléments attendus, nous présentons ce qu'est une clé de signature et comment elle est utilisée.

Une clé de signature est un certificat cryptographique qui sert à prouver l'identité de l'auteur de la compilation et de la publication d'une application. Elle permet par exemple de se rassurer que ce n'est pas un individu tiers qui injecte du code malveillant dans une application.

- **A quoi sert-elle ?**

Android n'installe pas une application si elle n'est pas signée. Dans le cas des mises à jour, le fait que la clé de la nouvelle version soit identique à celle de l'ancienne prouve à Android que ce n'est pas une fausse mise à jour effectuée par une autre personne. Avant toute publication, chaque build d'une application doit obligatoirement être signé.

- **Comment est-elle générée ?**

Il s'agit d'une paire de clé stockée dans un fichier `keystore`, protégé par deux mots de passe : un pour le keystore lui-même, et un pour l'alias de la clé à l'intérieur. Ces deux mots de passe peuvent être identiques.

- **Pourquoi il ne faut jamais la publier ?**

La consigne de l'exercice précise : `(...) Notez son emplacement et son mot de passe ailleurs que dans le dépôt. Rendez la commande employée, sans le mot de passe (...)`. 

Il y a une raison claire à ces précisions : si la clé de signature est perdue, ou qu'elle est compromise, il devient impossible de publier une mise à jour de l'application sous le même identifiant. L'application doit être publiée sur un nouveau package name, et tous les utilisaters perdent alors les mises à jour automatiques. 

De plus, n'importe qui avec la clé et le mot de passe peut signer un APK malveillant, qui se ferait passer pour une mise à jour légitime de l'application.

### **Elements à rendre : commande employée, endroit où elle a été rangée**

La commande de création de la clé de signature est la suivante : `jenga keygen --interactive` (nous l'avons trouvée dans le wiki officiel de Jenga, dans la section **Packaging, Déploiement, Publication**). Son exécution donne l'affichage suivant :

```
============================================================
Generate Android Keystore
============================================================

Key alias [mykey]: (alias de la clé)
Validity (days) [10000]:
Distinguished Name (CN=Name, OU=Org, O=Company, L=City, ST=State, C=Country) [CN=Jenga User]:
Keystore password:
Key password (default: same as keystore):
Generating keystore...
Keystore generated: (emplacement de la clé)
Alias: (alias de la clé)
```

L'alias de la clé, l'emplacement et le mot de passe ont été retirés dans le bloc ci-haut afin de les protéger (le mot de passe ne s'affiche d'ailleurs pas lors de la saisie dans le terminal).

Nous avons rangé la clé dans un dossier réservé à cet effet, hors de l'oeil de git. Il n'a aucun accès à ce dossier, et aucun programme n'utilise ce dossier de façon à l'exposer. En plus de cela nous avons noté l'alias, l'emplacement et le mot de passe sur papier, hors de la machine. Ceci afin de prévenir des éventuels oublis.

![Clé sur papier](Image.jpg)