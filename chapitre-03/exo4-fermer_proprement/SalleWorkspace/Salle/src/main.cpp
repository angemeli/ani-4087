#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkEvent.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkKeyboardEvent.h"

using namespace nkentseu;

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
    bool isRunning = true;

    // Rappel sur NkWindowCloseEvent
    events.AddEventCallback<NkWindowCloseEvent>([&](NkWindowCloseEvent* event) {
        isRunning = false;
    });

    // Rappel sur NkKeyPressEvent
    events.AddEventCallback<NkKeyPressEvent>([&](NkKeyPressEvent* event) {
        if (event->GetKey() == NkKey::NK_ESCAPE) {
            isRunning = false;
        }
    });

    while (isRunning) {
        NkEvents().PollEvents();
    }

    return 0;
}
