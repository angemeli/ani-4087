## **Mesure en Debug et en Release**

Pour cet exercice, nous avons écrit dans `main.cpp` une boucle qui s'exécute 1.000.000 fois, en calculant une expression composée de racines, de sinus et de cosinus. Nous avons placé une variable compteur au début et à la fin de la boucle. Le code complet est disponible, celui ci n'est qu'un extrait.

```
auto start = std::chrono::high_resolution_clock::now();    // Temps au départ

// Calcul
double result = 0;
for (size_t i = 1; i <= N; i++) {
   result += std::sqrt(i) * std::sin(i) + std::cos(i);
}

auto end = std::chrono::high_resolution_clock::now();     // Temps à la fin
std::chrono::duration<double, std::milli> duration = end - start;    // Durée totale d'exécution de la boucle       
```

Nous avons effectué 5 exécutions différentes pour chaque configuration. Les résultats sont les suivants :

### **Construction en Debug (`jenga build` ou `jenga build --config Debug`, puis `jenga run`)**

```
| Exécution | Durée d'exécution de la boucle |
| ------- | ------- |
| 1 | 59.321 ms |
| 2 | 50.412 ms |
| 3 | 57.401 ms |
| 4 | 53.328 ms |
| 5 | 50.364 ms |

```

La durée moyenne d'exécution ici est de **54.165 ms**

### **Construction en Release (`jenga build --config Release`, puis `jenga run --config Release`)**

```
| Exécution | Durée d'exécution de la boucle |
| ------- | ------- |
| 1 | 53.526 ms |
| 2 | 53.197 ms |
| 3 | 49.381 ms |
| 4 | 58.161 ms |
| 5 | 50.063 ms |

```

La durée moyenne d'exécution ici est donc de **52.865 ms**

### **Quelle mesure nous aurait fait prendre une mauvaise décision ?**

Les résultats de mesure obtenus ne nous permettent pas réellement de conclure avec clarté, la différence entre les deux durées n'étant que de **1.3 ms**. A moins que nous n'ayons commis une erreur dans notre approche, si ce résultat est le comportement attendu, nous pensons que cela est dû au fait que certains calculs ne peuvent pas être accélérés par le compilateur, surtout des opérations mathématiques de bas niveau (sin, cos, sqrt...). Nous sollicitons plus d'explications dans le rapport de correction.