# **La fenêtre nue**

Nous avons remplacé le corps de la boucle principale par un commentaire :

```
while (fenetre.IsOpen()) {
   // NkEvents().PollEvents();
}
```

La compilation se termine normalement, et l'exécution se déroule comme suit :
- Au lancement de `jenga run`, la fenêtre s'ouvre
- Lorsqu'on attend, rien ne se passe, le curseur tourne. La fenêtre reste indéfiniment bloquée sans réponse du système.
- Lorsqu'on lance le programme et qu'on provoque un évènement (par exemple un clic sur la croix de fermeture), le système signale que la fenêtre ne répond pas (le délai entre la provocation de l'évènement et le retour du système est de 1.10 seconde)

## **Ce qui se passe en réalité**

Lorsqu'on clique ou survole la fenêtre, le système d'exploitation capture l'événement provoqué et le transforme en message système. Il dépose ensuite ce message dans la file d'attente réservée à l'application. En principe, une boucle principale récupère un message dans la file d'attente, le traite et récupère ensuite le prochain message. Mais lorsque la boucle est vide, l'application est bloquée sur son instruction de saut en boucle. Elle ne lit jamais la file d'attente. Les événements s'accumulent sans jamais être traités.

Par conséquent, l'interface devient totalement insensible : cliquer sur un bouton ou fermer la fenêtre avec la croix n'a aucun effet. Puisque le thread associé à l'application ne vérifie jamais sa file d'attente, le système le considère comme bloqué. La fenêtre est grisée, le curseur tourne et le message "Ne répond pas" aparaît.
