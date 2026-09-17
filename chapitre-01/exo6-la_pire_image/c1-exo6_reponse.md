Pour cet exercie, le programme que nous avons utilisé a été fourni par Gemini. Accessible dans le dépôt github dans le même dossier que ce markdown : **ani-4087/chapitre-01/exo6-la_pire_image/programme.cpp**

Nous avons effectué la mesure sur 1000 images comme demandé, et nous avons repété l'exécution du programme 5 fois afin d'avoir une plage de valeurs pour la pire image. Nous avons obtenus les résultats suivants :

| Exéution | Durée de la plus longue image | Nombre d'images dépassant 11 ms |
| -------- | -------- | -------- |
| 1ere | 10.28 ms | 0 |
| 2e | 7.81 ms | 0 |
| 3e | 8.25 ms | 0 |
| 4e | 7.74 ms | 0 |
| 5e | 8.31 ms | 0 |

On peut constater qu'aucune image ne dépasse 11 ms lors des 5 exécutions. En d'autres termes, le programme tiendrait dans un casque tournant à une fréquence de 90 Hz, mais à 120 Hz il déborderait trop souvent la limite (8.3 Hz) et par conséquent causerait fréquemment des malaises au porteur du casque.
