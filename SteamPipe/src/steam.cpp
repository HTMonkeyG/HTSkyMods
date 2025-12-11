#include <windows.h>
#include "steam_api.h"
#include "steam_api_flat.h"

#include "steampipe.h"

i08 spInitSteamApi() {
  return SteamAPI_Init();
}

void spRunSteamCallbacks() {
  SteamAPI_RunCallbacks();
}
