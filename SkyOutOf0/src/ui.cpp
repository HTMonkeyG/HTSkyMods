#include <windows.h>
#include "imgui.h"

#include "outof0.h"

void OzRenderUi() {
  if (!ImGui::Begin("Out of Zero"))
    return ImGui::End();
  ImGui::PushID("Out of Zero");

  // FPS limitaion input.
  ImGui::SliderInt(
    "FPS Limitation",
    &gFpsLimit,
    30,
    1000,
    gFpsLimit > 999 ? "No Limit" : "%d");
  if (gFpsLimit < 15)
    gFpsLimit = 15;
  if (gFpsLimit > 1000)
    gFpsLimit = 1000;

  ImGui::PopID();
  ImGui::End();
}
