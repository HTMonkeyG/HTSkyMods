#include "includes/htmodloader.h"
#include "aliases.h"
#include "skymodbase_internal.h"

typedef void (__fastcall *PFN_ModuleBarn_callFunction)(
  void *, const char *, int, int, char);

static const HTAsmSig sigE8_ModuleBarn_callFunction = {
  .sig =
    "44 8B 86 ?  ?  ?  ?  C6 44 24 ?  ?  48 8D 15 ?  "
    "?  ?  ?  41 B9 ?  ?  ?  ?  E8 ?  ?  ?  ? ",
  .indirect = HT_SCAN_E8,
  .offset = 0x19
};

static HTAsmFunction sfn_ModuleBarn_callFunction = {
  .name = "ModuleBarn::CallFunction()",
  .detour = NULL,
  .fn = NULL,
  .origin = NULL
};

static void __fastcall hook_ModuleBarn_callFunction(
  void *self,
  const char *name,
  int a3,
  int a4,
  char direction
) {
  char eventId[48];

  ((PFN_ModuleBarn_callFunction)sfn_ModuleBarn_callFunction.origin)(
    self,
    name,
    a3,
    a4,
    direction);

  strcpy(eventId, smbNamespace);
  if (strlen(name) < 48 - sizeof(smbNamespace)) {
    strcat(eventId, name);
    HTCommEmitEvent(
      eventId,
      NULL,
      NULL);
  }
}

i08 smbInstallHooks() {
  HTSigScanFunc(
    &sigE8_ModuleBarn_callFunction,
    &sfn_ModuleBarn_callFunction);

  sfn_ModuleBarn_callFunction.detour = (void *)hook_ModuleBarn_callFunction;
  HTAsmHookCreate(
    hModuleDll,
    &sfn_ModuleBarn_callFunction);

  HTAsmHookEnable(
    hModuleDll,
    sfn_ModuleBarn_callFunction.fn);

  return 1;
}
