#include "includes/htmod.h"

#include "steampipe.h"

__declspec(dllexport) HTStatus HTMLAPI HTModOnInit(
  void *
) {
  if (!spInitSteamApi())
    HTTellText("§c[SteamPipe] Init steam failed.");
  else
    HTTellText("[SteamPipe] Inited steam.");

  return HT_SUCCESS;
}

__declspec(dllexport) HTStatus HTMLAPI HTModOnEnable(
  void *
) {
  return HT_SUCCESS;
}
