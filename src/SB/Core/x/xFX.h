#ifndef XFX_H
#define XFX_H

#include "xMath3.h"
#include "containers.h"
#include "iColor.h"

#include <rwcore.h>
#include <rpworld.h>

class xModelInstance;

struct xFXRing
{
    U32 texture;
    F32 lifetime;
    xVec3 pos;
    F32 time; // 0x14
    F32 ring_radius;
    F32 ring_radius_delta; // 0x1c
    F32 ring_tilt;
    F32 ring_tilt_delta; // 0x24?
    F32 ring_height; // 0x28
    F32 ring_height_delta;
    iColor_tag ring_color;
    U16 ring_segs;
    U8 u_repeat;
    U8 v_repeat;
    xFXRing** parent;
};

struct xFXRibbon
{
    struct config
    {
        F32 life_time;
        U32 blend_src;
        U32 blend_dst;
        F32 pivot;
    };

    struct joint_data
    {
        U32 flags;
        U32 born;
        xVec3 loc;
        xVec3 norm;
        F32 orient;
        F32 scale;
        F32 alpha;
    };

    struct curve_node
    {
        F32 time;
        iColor_tag color;
        F32 scale;
    };

    config cfg;
    bool activated;
    RwRaster* raster;
    tier_queue<joint_data> joints;
    curve_node* curve;
    U32 curve_size;
    U32 curve_index;
    F32 ilife;
    U32 mtime;
    U32 mlife;

    void init(const char*, const char*);
    void set_texture(const char* name);
    void set_curve(const curve_node* curve, size_t size);
    void refresh_config();
    void set_default_config();
    void update_curve_tweaks();
    void debug_init(const char*, const char*);
    void debug_update_curve();
    void debug_update(F32);
};

struct xFRect
{
    F32 x;
    F32 y;
    F32 w;
    F32 h;
};

struct xFXCameraTexture
{
    RwCamera* cam;
    RwRaster* raster;
    RwRaster* bgraster;
    RpWorld* world;
    RwTexture* texture;
    U32 vert_buffer_used;
    xColor_tag bgcolor;
    RwCamera* oldcam;
    RpWorld* oldworld;
    F32 rcz;
    F32 w;
    F32 h;
    RwRaster* zraster;
    S32 max_tw;
    S32 max_th;
    F32 old_near_plane;
    F32 old_far_plane;
    F32 old_znear;

    void zbuffer_map_and_clear(RwRaster* fraster, RwRaster* zraster, U32 fbmsk, S32 clear_flags);
    // void get_subview(xMat4x3& ltm, xVec2& view_window, xVec2& view_offset, RwCamera* src_cam,
    //                  xFRect& src_rect, xFRect& dst_rect);
    void setup_subview(RwCamera* src_cam, xFRect& src_rect, xFRect& dst_rect);
    void end_render();
    void begin_render(S32 clear_flags, U32 fbmsk_write, U32 fbmsk_finish, F32 near_plane,
                      F32 far_plane);
    void destroy();
    U8 create(S32 w, S32 h, U8 need_zwrite, S32 bpp, S32 zbpp);
};

#define RING_COUNT 8

extern xFXRing ringlist[RING_COUNT];

void xFXInit();
xFXRing* xFXRingCreate(const xVec3* pos, const xFXRing* params);
void xFXRingRender();
void xFX_SceneEnter(RpWorld* world);
void xFX_SceneExit(RpWorld* world);
void xFXUpdate(F32 dt);
RpAtomic* AtomicDisableMatFX(RpAtomic* atomic);
void xFXPreAllocMatFX(RpClump* clump);

RpAtomic* xFXBubbleRender(RpAtomic* atomic);

void xFXanimUV2PSetTexture(RwTexture* texture);
void xFXanimUVSetTranslation(const xVec3* trans);
void xFXanimUV2PSetTranslation(const xVec3* trans);
void xFXanimUVSetScale(const xVec3* scale);
void xFXanimUV2PSetScale(const xVec3* scale);
void xFXanimUVSetAngle(F32 angle);
void xFXanimUV2PSetAngle(F32 angle);
RpAtomic* xFXanimUVAtomicSetup(RpAtomic* atomic);
U32 xFXanimUVCreate();
void xFXFireworksInit(const char* fireworksTrailEmitter, const char* fireworksEmitter1,
                      const char* fireworksEmitter2, const char* fireworksSound,
                      const char* fireworksLaunchSound);
void xFXFireworksLaunch(F32 countdownTime, const xVec3* pos, F32 fuelTime);
void xFXFireworksUpdate(F32 dt);
void xFXStreakInit();
void xFXStreakUpdate(F32 dt);
void xFXStreakUpdate(U32 streakID, const xVec3*, const xVec3*);
void xFXStreakRender();
void xFXStreakStop(U32);
void xFXShineInit();
void xFXShineUpdate(F32 dt);
void xFXShineRender();
RpAtomic* xFXAtomicEnvMapSetup(RpAtomic* atomic, U32 envmapID, F32 shininess);
void xFXRibbonSceneEnter();
void xFXRibbonUpdate(F32 dt);
void xFXRibbonRender();
void xFXAuraInit();
void xFXAuraUpdate(F32 dt);
void xFXAuraRender();
void xFXRenderProximityFade(const xModelInstance& model, F32 near_dist, F32 far_dist);
void xFXSceneInit();
void xFXSceneSetup();
void xFXSceneReset();
void xFXScenePrepare();
void xFXSceneFinish();

#endif
