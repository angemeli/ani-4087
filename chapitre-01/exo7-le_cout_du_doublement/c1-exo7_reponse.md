### **Valeurs obtenues pour le rendu seul**

Pour cet exercice, nous avons effectué deux mesures pour chaque exécution : La mesure de la durée totale, et la mesure de la durée du rendu seul. Cette double mesure a été effectuée dans le but de comparer à chaque fois la proportion de temps que prend le rendu seul, et de découvrir qui des deux (logique, rendu) doit être optimisé afin de rester dans les valeurs normales.

Les résultats obtenus pour 5 exécutions, , correspondant aux pires images, sont onsignés dans le tableau suivant :

| Exécution | Durée totale | Durée du rendu seul | Proportion du rendu sur la durée totale |
| -------- | -------- | ------- | ------- |
| 1 | 5.91 ms | 5.51 ms | 93.23 % | 
| 2 | 6.22 ms | 3.98 ms | 63.99 % |
| 3 | 6.87 ms | 6.21 ms | 90.39 % |
| 4 | 5.8446 ms | 5.8406 ms | 99.93 % |
| 5 | 7.69 ms | 5.29 ms | 68.79 % |

On constate que pour la majorité des exécutions (bien que 5 exécutions ne soient pas assez pour généraliser), le rendu seul consomme plus de 90 % de la durée totale d'exécution. 

Pour un rendu doublé, on aurait les résultats suivants :

| Exécution | Durée du rendu seul | Temps restant (par rapport à 11 ms) |
| -------- | ------- | ------- |
| 1 | 11.02 ms | -0.02 ms (Dépassement de temps) | 
| 2 | 7.96 ms | 3.04 ms |
| 3 | 12.42 ms | -1.42 ms (Dépassement de temps) |
| 4 | 11.6812 ms | -0.6812 ms (Dépassement de temps) |
| 5 | 10.58 ms | 0.42 ms |

Le doublement de rendu cause donc un dépassement de temps 3 fois sur 5. Pour un autre cas, le temps restant est très petit, et la logique de jeu pourrait le dépasser. Cela montre que ce qu'il faut réduire en priorité est le rendu, donc le code de rendu doit toujours être optimisé au maximum par le programmeur, afin d'éviter les consommations importantes de temps et les dépassements de budget.
