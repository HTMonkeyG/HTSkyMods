#include <windows.h>
#include "steam_api.h"
#include "steam_api_flat.h"

#include "steamsky.h"

i08 stInitSteamApi() {
  return SteamAPI_Init();
}
