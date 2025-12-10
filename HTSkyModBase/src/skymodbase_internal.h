#ifndef __SKYMODBASE_INTERNAL_H__
#define __SKYMODBASE_INTERNAL_H__

#include <windows.h>
#include "includes/htmodloader.h"

#include "aliases.h"
#include "skymodbase.h"

#ifdef __cplusplus
extern "C" {
#endif

extern HMODULE hModuleDll;

i08 smbInstallHooks();

#ifdef __cplusplus
}
#endif

#endif
