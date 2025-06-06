#ifndef IFMV_H
#define IFMV_H

#include <types.h>
#include <bink.h>
#include <PowerPC_EABI_Support\MSL_C\MSL_Common\size_t.h>

struct _GXRenderModeObj;

struct iFMV
{
    static void* mXFBs[2];
    static void* mCurrentFrameBuffer;
    static _GXRenderModeObj* mRenderMode;
    static U8 mFirstFrame;

    static void InitDisplay(_GXRenderModeObj*);
    static void InitGX();
    static void InitVI();
    static void Suspend();
    static void Resume();
};

void* iFMVmalloc(size_t size);
void iFMVfree(void* mem);
U32 iFMVPlay(char* filename, U32 buttons, F32 time, bool skippable, bool lockController);
static void Setup_surface_array();
void Decompress_frame(HBINK bnk, HRAD3DIMAGE rad_image, long flags);
#endif
