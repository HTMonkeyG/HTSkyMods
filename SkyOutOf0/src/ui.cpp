#include <windows.h>
#include "includes/htmodloader.h"
#include "imgui.h"

#include "outof0.h"

static bool gShowMenu = false;

void OzToggleMenuState() {
  gShowMenu = !gShowMenu;
}

void OzRenderUi() {
  bool changed;

  if (!gShowMenu)
    return;

  if (!ImGui::Begin("Out of Zero", &gShowMenu))
    return ImGui::End();
  ImGui::PushID("Out of Zero");

  // FPS limitaion input.
  changed = ImGui::SliderInt(
    "FPS Limitation",
    &gFpsLimit,
    30,
    1000,
    gFpsLimit > 999 ? "No Limit" : "%d");
  if (gFpsLimit < 15)
    gFpsLimit = 15;
  if (gFpsLimit > 1000)
    gFpsLimit = 1000;

  if (changed) {
    f64 fpsLimit = (f64)gFpsLimit;
    HTOptionSetCustom(
      hModuleDll,
      OzText_KeyOptionFpsLimit,
      HTOptionType_Double,
      (void *)&fpsLimit);
  }

  ImGui::PopID();
  ImGui::End();
}
