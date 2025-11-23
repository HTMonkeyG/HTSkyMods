#ifndef __OUTOF0_H__
#define __OUTOF0_H__

#include <windows.h>
#include "aliases.h"

#ifdef __cplusplus
extern "C" {
#endif

// The handle of current DLL.
extern HMODULE hModuleDll;
// FPS limitation.
extern i32 gFpsLimit;
// Performance frequency.
extern u64 gPerfFreq;
extern f64 gPerfFreqDouble;

// Query performance frequency and convert to double.
void OzQueryPerfFreq();

// Install all hooks.
void OzInstallAllHooks();
// Render ImGui.
void OzRenderUi();

// Detect frame rate and return whether rendering is needed.
u08 OzShouldRender();

#ifdef __cplusplus
}
#endif

#endif
