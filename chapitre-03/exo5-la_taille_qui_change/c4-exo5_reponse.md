# **La taille qui change**

Ici, il est question d'effectuer deux séries de mesures : les tailles après des redimentionnements lents, puis les tailles après des redimentionnements brusques. Pour cela, nous avons écrit le bloc suivant dans le fichier `main.cpp` :

```
events.AddEventCallback<NkWindowResizeEvent>([&](NkWindowResizeEvent* event) {
   cout << "Nouvelle taille de la fenetre : (" 
      << event->GetWidth() << "," 
      << event->GetHeight() << ")" << endl;
});
```

Les méthodes `GetWidth()` et `GetHeight()` renvoient les dimensions en temps réel de la fenêtre. Nous avons procédé aux redimensionnements sur la hauteur, en diminuant lentement puis brusquement sa valeur, et voici les valeurs obtenues (lire d'une colonne à une autre) :

- Redimensionnements lents :
```
(1216,758)	(1198,711)	(1216,756)	(1198,709)
(1216,755)	(1198,708)	(1216,754)	(1198,707)
(1216,752)	(1198,705)	(1216,751)	(1198,704)
(1216,750)	(1198,703)	(1216,749)	(1198,702)
(1216,747)	(1198,700)	(1216,746)	(1198,699)
(1216,745)	(1198,698)	(1216,744)	(1198,697)
(1216,742)	(1198,695)	(1216,741)	(1198,694)
(1216,740)	(1198,693)	(1216,739)	(1198,692)
(1216,738)	(1198,691)	(1216,737)	(1198,690)
(1216,736)	(1198,689)	(1216,735)	(1198,688)
(1216,734)	(1198,687)	(1216,733)	(1198,686)
(1216,732)	(1198,685)	(1216,730)	(1198,683)
(1216,730)	(1216,729)	(1198,682)	(1216,728)
(1198,681)	(1216,727)	(1198,680)	(1216,726)
(1198,679)	(1216,724)	(1198,677)	(1216,723)
(1198,676)

```

- Redimensionnements brusques :

```
(1216,744)	(1198,697)	(1216,721)	(1198,674)
(1216,676)	(1198,629)	(1216,545)	(1198,498)
(1216,474)	(1198,427)	(1216,419)	(1198,372)
(1216,381)	(1198,334)	(1216,366)	(1198,319)
(1216,357)	(1198,310)	(1216,356)	(1198,309)
(1216,355)	(1198,308)	(1216,356)	(1198,309)
(1216,358)	(1198,311)
```

61 évènements ont été reçus pour passer lentement de 758 à 676 pixels de hauteur. Seulement 26 évènements ont été reçus pour passer brusquement de 744 à 311 pixels de hauteur. 

Cet écart considérable entre les deux rapports de redimensionnement s'explique par la façon dont le système gère les évènements.

Le système ne les gère pas en continu absolu, mais à une fréquence fixée, généralement calée sur le taux de rafraichissement de l'écran. Dans notre cas, ce taux s'élève à 60 Hz, soit un signal toutes les 16.67 ms. A chaque tick du système (chaque dépassement des 16.67 ms), la souris ne bouge que d'un, de deux, maximum de cinq pixels, sauf variation brusque. Par conséquent, le système a eu le temps d'émettre 61 signaux pour couvrir les 82 pixels de différence. 

En déplacement brusque, entre deux ticks du système, la souris a franchi une grande distance d'un seul coup. Le système n'émet de signal qu'à l'instant où il lit la position du curseur, ce qui saute toutes les positions intermédiaires. Résultat, on n'obtient que 26 signaux pour couvrir 433 pixels de différence.