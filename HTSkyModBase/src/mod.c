#include "includes/htmod.h"
#include "skymodbase_internal.h"

__declspec(dllexport) HTStatus HTMLAPI HTModOnInit(
  void *reserved
) {
  smbInstallHooks();

  return HT_SUCCESS;
}

__declspec(dllexport) HTStatus HTMLAPI HTModOnEnable(
  void *reserved
) {
  return HT_SUCCESS;
}
