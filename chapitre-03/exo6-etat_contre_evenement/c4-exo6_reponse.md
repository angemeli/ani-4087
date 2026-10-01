# **Etat contre evenement**

Le but de cet exercice est d'illustrer par les compteurs la différence entre un état et un évènement. Pour cela, nous avons créé deux compteurs, `etatCount` et `eventCount`, initialisés chacun à 0.

## **Le compteur d'état**

Le bloc suivant (écrit à l'intérieur de la boucle) incrémente `etatCount` à chaque tour de boucle tant que la touche ESPACE reste enfoncée. 

```c++
while (NkEvent* ev = NkEvents().PollEvent()) {
   if (NkInput.IsKeyDown(NkKey::NK_SPACE)) {
         etatCount += 1;
   }
}
```

## **Le compteur d'évènement**

Le bloc suivant définit un évènement qui est provoqué par rappel à chaque appui sur la touche ESPACE (la touche est enfoncée une seule fois). `eventCount` n'est incrémenté de nouveau que lorsque la touche est relachée puis appuyée.

```c++
events.AddEventCallback<NkKeyPressEvent>([&](NkKeyPressEvent* event) {
   if (event->GetKey() == NkKey::NK_SPACE) {
      eventCount += 1;
   }
});
```

## **Résultats**

L'exécution se passe normalement, et lorsqu'on appuie pendant une seconde sur la touche ESPACE, nous obtenons les résultats :

```cmd
Compteur d'etat : 40
Compteur d'evenement : 1
```

Cet écart de valeurs s'explique : `NkInput.IsKeyDown()` est appellé à chaque tour de boucle tant que la touche ESPACE est enfoncée, et donc son compteur s'incrémente. Par contre, NkKeyPressEvent n'est appelé qu'une fois, lors du premier appui de la touche. Il ne détecte l'évènement que lorsque l'utilisateur appuie pour la première fois. L'incrémentation ne se fait de nouveau que lorsque la touche est relachée puis appuyée. Donc en une seconde, `etatCount` s'incrémente tant que la touche est maintenue enfoncée. `èventCount` quant à lui ne s'incrémente qu'au début de l'appui.