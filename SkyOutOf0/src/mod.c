#include "includes/htmod.h"
#include "outof0.h"

__declspec(dllexport) HTStatus HTMLAPI HTModOnInit(
  void *reserved
) {
  OzQueryPerfFreq();
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
