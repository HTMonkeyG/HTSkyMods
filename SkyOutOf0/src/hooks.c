#include "includes/htmodloader.h"
#include "aliases.h"
#include "outof0.h"

typedef u08 (__fastcall *PFN_Client_shouldRender)(
  void *);

static const HTAsmSig sigE8_Client_shouldRender = {
  .sig =
    "FF 50 ?  48 89 F1 E8 ?  ?  ?  ?  84 C0 0F 84 ?  "
    "?  ?  ?  48 8B",
  .indirect = HT_SCAN_E8,
  .offset = 0x06
};

static HTAsmFunction sfn_Client_shouldRender = {
  .name = "Client::shouldRender",
  .detour = NULL,
  .fn = NULL,
  .origin = NULL
};

static u08 __fastcall hook_Client_shouldRender(
  void *a1
) {
  // We ignore the game's original detection function.
  (void)((PFN_Client_shouldRender)sfn_Client_shouldRender.origin)(
    a1);

  return OzShouldRender();
}

void OzInstallAllHooks() {
  HTSigScanFunc(
    &sigE8_Client_shouldRender,
    &sfn_Client_shouldRender);

  sfn_Client_shouldRender.detour = (void *)hook_Client_shouldRender;
  HTAsmHookCreate(
    hModuleDll,
    &sfn_Client_shouldRender);

  HTAsmHookEnable(
    hModuleDll,
    sfn_Client_shouldRender.fn);
}