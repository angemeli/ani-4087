#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

using namespace nkentseu;

int nkmain(const NkEntryState& state) {
    NkWindowConfig config;
    config.title = "Ma salle";
    config.width = 1200;
    config.height = 720;

    // Champs modifiés
    config.centered = false;
    //config.closable = false;
    //config.hasShadow = false;
    //config.bgColor = 0x54A3FF;
    //config.opacity = 0.5f;

    NkWindow fenetre(config);
    if (!fenetre.IsValid()) {
        return 1;
    }

    while (fenetre.IsOpen()) {
        NkEvents().PollEvents();
    }

    return 0;
}
