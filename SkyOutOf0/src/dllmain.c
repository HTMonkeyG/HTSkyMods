#include <windows.h>
#include "includes/htmod.h"

#include "outof0.h"

HMODULE hModuleDll;
u64 gPerfFreq = 0;
f64 gPerfFreqDouble = 0.0;

void OzQueryPerfFreq() {
  if (!gPerfFreq) {
    LARGE_INTEGER qpf;
    QueryPerformanceFrequency(&qpf);
    gPerfFreq = qpf.QuadPart;
    gPerfFreqDouble = (f64)qpf.QuadPart;
  }
}

BOOL APIENTRY DllMain(
  HMODULE hModule,
  DWORD dwReason,
  LPVOID lpReserved
) {
  if (dwReason == DLL_PROCESS_ATTACH) {
    hModuleDll = hModule;
    DisableThreadLibraryCalls(hModule);
  }
  return TRUE;
}
