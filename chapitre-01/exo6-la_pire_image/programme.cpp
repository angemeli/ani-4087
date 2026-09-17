#include <windows.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (uMsg == WM_DESTROY) {
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int main() {
    // 1. Initialisation de la fenetre Win32
    HINSTANCE hInstance = GetModuleHandle(NULL);
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "EffacerEcran";
    RegisterClass(&wc);

    HWND hwnd = CreateWindow("EffacerEcran", "Exercice 6 - Mesure VR", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                             100, 100, 800, 600, NULL, NULL, hInstance, NULL);

    MSG msg = {0};
    bool running = true;

    // 2. Variables pour les mesures
    const int TOTAL_FRAMES = 1000;
    std::vector<double> frame_times;
    frame_times.reserve(TOTAL_FRAMES);

    std::cout << "Mesure en cours sur 1000 images..." << std::endl;

    // 3. Boucle d'affichage
    while (running && frame_times.size() < TOTAL_FRAMES) {
        // TOP DE DEPART
        auto start = std::chrono::high_resolution_clock::now();

        // Traitement des evenements Windows
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) running = false;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        // --- EFFACEMENT DE L'ÉCRAN ---
        HDC hdc = GetDC(hwnd);
        RECT rect;
        GetClientRect(hwnd, &rect);
        FillRect(hdc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
        ReleaseDC(hwnd, hdc);

        // TOP DE FIN & CALCUL DE LA DURÉE
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = end - start;
        frame_times.push_back(duration.count());
    }

    // 4. Analyse des resultats pour l'exercice 6
    if (!frame_times.empty()) {
        double max_time = *std::max_element(frame_times.begin(), frame_times.end());
        int exceeded_11ms = 0;

        for (double time_ms : frame_times) {
            if (time_ms > 11.0) {
                exceeded_11ms++;
            }
        }

        std::cout << "\n================ RESULTATS DES MESURES ================\n";
        std::cout << "Nombre d'images mesurees   : " << frame_times.size() << "\n";
        std::cout << "1. Pire image (duree max)  : " << max_time << " ms\n";
        std::cout << "2. Images depassant 11 ms  : " << exceeded_11ms << "\n";
        
        if (max_time <= 11.0) {
            std::cout << "Conclusion                 : Le programme tient la cadence a 90 Hz.\n";
        } else {
            std::cout << "Conclusion                 : La pire image depasse l'echeance de 11 ms.\n";
        }
        std::cout << "======================================================\n";
    }

    return 0;
}
