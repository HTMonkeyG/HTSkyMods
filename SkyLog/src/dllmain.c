#include <windows.h>
#include <string.h>
#include "includes/htmod.h"

static const HTAsmSig sigE8_Logger_printf = {
  .sig =
    "48 8D 05 ?  ?  ?  ?  48 89 44 24 ?  E8 ?  ?  ?  "
    "?  48 8D 05 ?  ?  ?  ?  48 89 86",
  .indirect = HT_SCAN_E8,
  .offset = 0x0C
};

HMODULE hModuleDll;

typedef void (__fastcall *PFN_Logger_printf)(
  int, const char *, const char *, int, const char *, const char *);

PFN_Logger_printf fn_Logger_printf = NULL;

void __fastcall hook_Logger_printf(
  int a1,
  const char *a2,
  const char *a3,
  int a4,
  const char *a5,
  const char *a6
) {
  if (strcmp(a5, "%s"))
    return;
  HTTellText(
    "[Sky] %s %s%s",
    a2,
    a4 ? "warning: " : "",
    a6);
  return fn_Logger_printf(
    a1, a2, a3, a4, a5, a6);
}

HTAsmFunction pfn_Logger_printf = {
  .name = "Logger::printf",
  .fn = NULL,
  .detour = hook_Logger_printf,
  .origin = NULL
};

__declspec(dllexport) HTStatus HTMLAPI HTModOnInit(
  void *
) {
  LPVOID fn = HTSigScan(&sigE8_Logger_printf);

  pfn_Logger_printf.fn = fn;
  HTAsmHookCreate(
    hModuleDll,
    &pfn_Logger_printf);
  fn_Logger_printf = pfn_Logger_printf.origin;
  HTAsmHookEnable(hModuleDll, fn);

  return HT_SUCCESS;
}

BOOL APIENTRY DllMain(
  HMODULE hModule,
  DWORD dwReason,
  LPVOID lpReserved
) {
  if (dwReason == DLL_PROCESS_ATTACH)
    hModuleDll = hModule;
  return TRUE;
}
