#ifndef __STEAMPIPE_H__
#define __STEAMPIPE_H__

#include "aliases.h"

#ifdef __cplusplus
extern "C" {
#endif

// Initialize steam api.
i08 spInitSteamApi();

// This function is called single-threaded in the game's main loop.
void spRunSteamCallbacks();

i08 spScreenShotRedirect(
  const char *path,
  i32 width,
  i32 height);

i08 spScreenShotTake();

#ifdef __cplusplus
}
#endif

#endif
