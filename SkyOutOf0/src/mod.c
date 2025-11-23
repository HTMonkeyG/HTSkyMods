#include "includes/htmod.h"
#include "outof0.h"

static HTHandle hToggleMenu = NULL;

static void loadOptions() {
  f64 fpsLimit;

  HTOptionGetCustom(
    hModuleDll,
    OzText_KeyOptionFpsLimit,
    HTOptionType_Double,
    (void *)&fpsLimit,
    NULL);
  gFpsLimit = (i32)fpsLimit;
  if (gFpsLimit > 1000)
    gFpsLimit = 1000;
  if (gFpsLimit < 15)
    gFpsLimit = 15;
}

static void HTMLAPI toggleMenuCallback(
  HTKeyEvent *event
) {
  if ((event->flags & HTKeyEventFlags_Mask) == HTKeyEventFlags_Down)
    OzToggleMenuState();
}

__declspec(dllexport) HTStatus HTMLAPI HTModOnInit(
  void *reserved
) {
  OzQueryPerfFreq();

  loadOptions();

  hToggleMenu = HTHotkeyRegister(
    hModuleDll,
    "Toggle menu",
    HTKey_F3);
  HTHotkeyListen(
    hToggleMenu,
    toggleMenuCallback);

  OzInstallAllHooks();
  
  return HT_SUCCESS;
}

__declspec(dllexport) HTStatus HTMLAPI HTModOnEnable(
  void *reserved
) {
  return HT_SUCCESS;
}

__declspec(dllexport) void HTMLAPI HTModRenderGui(
  float timeElapesed,
  void *reserved
) {
  OzRenderUi();
}
