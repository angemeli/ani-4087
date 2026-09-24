#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>

int main() {
    const size_t N = 1000000;
    std::cout << "Calcul lourd en cours : (" << N << " iterations)\n";

    auto start = std::chrono::high_resolution_clock::now();    // Temps au départ

    // Calcul
    double result = 0;
    for (size_t i = 1; i <= N; i++) {
        result += std::sqrt(i) * std::sin(i) + std::cos(i);
    }

    auto end = std::chrono::high_resolution_clock::now();     // Temps à la fin
    std::chrono::duration<double, std::milli> duration = end - start;    // Durée totale d'exécution de la boucle

    std::cout << "Resultat du calcul : " << result << "\n";
    std::cout << "Temps d'execution  : " << duration.count() << " ms\n";

    return 0;
}