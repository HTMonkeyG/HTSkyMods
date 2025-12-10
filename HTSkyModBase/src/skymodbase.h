#ifndef __SKYMODBASE_H__
#define __SKYMODBASE_H__

#include "includes/htmodloader.h"

#define SMB_API HTMLAPI
#define SMB_API_ATTR HTMLAPIATTR

#define smbNamespace "htskymodbase:"
#define smbMakeNamespace(literal) smbNamespace literal

#ifdef __cplusplus
extern "C" {
#endif

typedef HTStatus (SMB_API *PFN_smbGetLocalAvatarPos)(
  float *);
SMB_API_ATTR HTStatus SMB_API smbGetLocalAvatarPos(
  float *pos);

#ifdef __cplusplus
}
#endif

#endif
