#include "filtre.hpp"
#include <iostream>

using namespace std;

int main() {
    #ifdef _WIN32
        cout << "Le programme compile sous Windows\n";
        fonction();
    #elifdef __linux__
        cout << "Le programme compile sous Linux";
        fonction();
    #endif
    
    return 0;
}
