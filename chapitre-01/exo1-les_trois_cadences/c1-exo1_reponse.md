## **Durée d'une image**

- À 72 Hz, une image dure 13.9 ms
- À 90 Hz, une image dure 11.1 ms
- À 120 Hz, une image dure 8.3 ms

## **Temps qui reste au code**

- À 72 Hz : 13.9 - 8 = **5.9 ms**
- À 90 Hz : 11.1 - 8 = **3.1 ms**
- À 120 Hz : 8.3 - 8 = **0.3 ms**

Chacune de ces valeurs représentent les durées maximales que possède le code lui-même pour être exécuté. Donc toute la logique du jeu, la physique, les ressources... Tout cela doit être exécuté au bout de 5.9 ms maximum (à 72 Hz).

On peut alors se rendre compte qu'à fréquence élevée, le code doit s'exécuter ultra rapidement. Il m'a presque pas de temps pour lui, car comme expliqué dans le chapitre 1 s'il n'est pas prêt à temps, le système continue de tourner avec les anciennes sorties (images, valeurs...) déformées. Par conséquent le corps se sent comme "empoisonné" et provoque des malaises. 
