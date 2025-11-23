#include "outof0.h"
#include "aliases.h"

i32 gFpsLimit = 120;

static LARGE_INTEGER gLastFrameTime = {0};

u08 OzShouldRender() {
  LARGE_INTEGER currentFrameTime;

  if (!gLastFrameTime.QuadPart) {
    QueryPerformanceCounter(&gLastFrameTime);
    return 1;
  }

  QueryPerformanceCounter(&currentFrameTime);

  // (currentFrameTime - gLastFrameTime) / gPerfFreqDouble >= 1 / gFpsLimit
  u64 tickElapsed = currentFrameTime.QuadPart - gLastFrameTime.QuadPart;

  // Avoid divide by 0.
  if (tickElapsed && gPerfFreqDouble / (f64)tickElapsed <= (f64)gFpsLimit) {
    gLastFrameTime = currentFrameTime;
    return 1;
  }

  return 0;
}
