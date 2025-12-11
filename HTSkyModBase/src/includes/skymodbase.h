#ifndef __SKYMODBASE_H__
#define __SKYMODBASE_H__

#include "includes/htmodloader.h"

#ifdef __cplusplus
extern "C" {
#endif

// API attributes.
#define SMB_API HTMLAPI
#define SMB_API_ATTR HTMLAPIATTR

// Namespace prefix.
#define smbNamespace "htskymodbase:"
#define smbMakeNamespace(literal) smbNamespace literal

// Event names.
// Call HTCommOnEvent() to listen to these events.
#define smbEventBuildScene        smbMakeNamespace("BuildScene")
#define smbEventInitialize        smbMakeNamespace("Initialize")
#define smbEventOnEvent           smbMakeNamespace("OnEvent")
#define smbEventOnLevelLoad       smbMakeNamespace("OnLevelLoad")
#define smbEventOnLevelLoadEarly  smbMakeNamespace("OnLevelLoadEarly")
#define smbEventOnLevelLoadLate   smbMakeNamespace("OnLevelLoadLate")
#define smbEventOnLevelUnload     smbMakeNamespace("OnLevelUnload")
#define smbEventOnLevelUnloadLate smbMakeNamespace("OnLevelUnloadLate")
#define smbEventOnPause           smbMakeNamespace("OnPause")
#define smbEventOnSuspend         smbMakeNamespace("OnSuspend")
#define smbEventOnUnpause         smbMakeNamespace("OnUnpause")
#define smbEventPostRender        smbMakeNamespace("PostRender")
#define smbEventRenderFlush       smbMakeNamespace("RenderFlush")
#define smbEventResize            smbMakeNamespace("Resize")
#define smbEventUpdate            smbMakeNamespace("Update")
#define smbEventUpdateBackground  smbMakeNamespace("UpdateBackground")
#define smbEventUpdateLate        smbMakeNamespace("UpdateLate")

// Function shortcuts.

typedef HTStatus (SMB_API *PFN_smbGetLocalAvatarPos)(
  float *);
SMB_API_ATTR HTStatus SMB_API smbGetLocalAvatarPos(
  float *pos);

// Function addresses.

// Get local avatar.
typedef UINT8 (SMB_API *PFN_Sky_AvatarBarn_tryGetLocalAvatar)(
  void *);
SMB_API_ATTR UINT8 SMB_API Sky_AvatarBarn_tryGetLocalAvatar(
  void *self);

// Get the cape level.
typedef UINT8 (SMB_API *PFN_Sky_AvatarAccount_getCapeLevel)(
  void *);
SMB_API_ATTR UINT8 SMB_API Sky_AvatarAccount_getCapeLevel(
  void *self);

#ifdef __cplusplus
}
#endif

#endif
