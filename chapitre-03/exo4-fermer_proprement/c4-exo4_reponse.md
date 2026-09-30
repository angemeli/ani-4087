# **Fermer proprement**

Cet exercice consistait à appliquer le modèle de gestion d'évènements par callbacks, avec des `AddEventCallback`. Il fallait ajouter deux rappels : l'un à `NkWindowCloseEvent`, et l'autre à `NkKeyPressEvent`. Le fichier `main.cpp` est disponible dans le workspace associé au présent fichier.

## **Procédure de réalisation**

Premièrement, nous avons créé une variable `events` qui est le conteneur d'évènements de notre application :

```
auto& events = NkEvents();
```

Nous avons ensuite ajouté le rappel sur `NkWindowCloseEvent`, qui place la variable booléenne `isRunning` à `false` lorsque l'utilisateur clique sur le bouton d'arrêt (croix) de l'application :

```
events.AddEventCallback<NkWindowCloseEvent>([&](NkWindowCloseEvent* event) {
   isRunning = false;
});
```

Par la suite nous avons ajouté le rappel sur `NkKeyPressEvent`, et qui place la même variable booléenne à `false`, mais cette fois lorsque l'utilisateur appuie sur la touche Echap du clavier :

```
events.AddEventCallback<NkKeyPressEvent>([&](NkKeyPressEvent* event) {
   if (event->GetKey() == NkKey::NK_ESCAPE) {
      isRunning = false;
   }
});
```

## **Résultats et analyse**

Lors de l'exécution, la fenêtre se ferme lorsqu'on clique sur la croix. Elle se ferme également si on appuie sur la touche Echap du clavier.

- **Pourquoi les deux chemins de sortie aboutissent au même résultat ?**

La méthode `AddEventCallback` sert à écouter des évènements particuliers et à exécuter des instructions lorsqu'ils se produisent. Voici ce qui se passe : Lorsque l'utilisateur fait un clic sur le bouton d'arrêt, le `PollEvents()` dans la boucle principale récupère l'action effectuée et fait un appel à l'évènement associé, donc à `NkWindowCloseEvent`. Cet évènement est contenu dans le pointeur `event`, de type `NkWindowCloseEvent*`

Or la capture de cet évènement se fait par reférence (`[&]`), ce qui permet à la fonction lambda de rappel d'avoir accès aux variables qui l'entourent dans le code, et par conséquent à la variable `isRunning`. Et elle peut donc la modifier directement.

C'est exactement le même processus qui se déroule lorsque l'utilisateur appuie sur Echap, avec une précision : la variable n'est modifiée que si l'on est sûr que c'est la touche Echap qui est appuyée (`if (event->GetKey() == NkKey::NK_ESCAPE)`). Les deux chemins de sortie ont accès à la même variable drapeau et peuvent donc la modifier, et c'est ce qu'ils font. C'est cette variable qui conditionne la boucle qui maintient en vie la fenêtre : dès que l'un des chemins y accède et la modifie, l'application s'arrête.
