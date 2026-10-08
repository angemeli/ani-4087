#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkEvent.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkKeyboardEvent.h"

using namespace nkentseu;
using namespace std;

int nkmain(const NkEntryState& state) {
    NkWindowConfig config;

    config.title = "Ma salle";
    config.width = 1200;
    config.height = 720;
    config.hasShadow = false;
    config.bgColor = 0x101717;

    NkWindow fenetre(config);
    if (!fenetre.IsValid()) {
        return 1;
    }

    auto& events = NkEvents();

    // ======= EVENEMENTS DE FERMETURE DE L'APPLICATION ========
    bool isRunning = true;

    // Fermeture avec le bouton
    events.AddEventCallback<NkWindowCloseEvent>([&](NkWindowCloseEvent* event) {
        isRunning = false;
    });

    // Fermeture au clavier avec la touche Echap
    events.AddEventCallback<NkKeyPressEvent>([&](NkKeyPressEvent* event) {
        if (event->GetKey() == NkKey::NK_ESCAPE) {
            isRunning = false;
        }
    });
    
    // Compteur d'état : s'incrémente à chaque fois où la touche Espace est tenue
    int etatCount = 0;

    // Compteur d'évènement : s'incrémente à chaque NkKeyPressEvent
    int eventCount = 0;

    events.AddEventCallback<NkKeyPressEvent>([&](NkKeyPressEvent* event) {
        if (event->GetKey() == NkKey::NK_SPACE) {
            eventCount += 1;
        }
    });

    while (isRunning) {
        while (NkEvent* ev = NkEvents().PollEvent()) {
            if (NkInput.IsKeyDown(NkKey::NK_SPACE)) {
                etatCount += 1;
            }
        }
    }

    cout << "Compteur d'etat : " << etatCount << endl;
    cout << "Compteur d'evenement : " << eventCount << endl;

    return 0;
}
