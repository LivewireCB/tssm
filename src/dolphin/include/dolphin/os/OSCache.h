#ifndef _DOLPHIN_OSCACHE
#define _DOLPHIN_OSCACHE

#include "dolphin/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void DCInvalidateRange(void* addr, u32 nBytes);
void DCFlushRange(void* addr, u32 nBytes);
void DCStoreRange(void* addr, u32 nBytes);
void DCFlushRangeNoSync(void* addr, u32 nBytes);
void DCStoreRangeNoSync(void* addr, u32 nBytes);
void DCZeroRange(void* addr, u32 nBytes);
void DCTouchRange(void* addr, u32 nBytes);
void ICInvalidateRange(void* addr, u32 nBytes);

// Instruction cache functions.
void ICInvalidateRange(void* addr, u32 numBytes);
void ICFlashInvalidate();
void ICEnable();

#define LC_BASE_PREFIX 0xE000
#define LC_BASE (LC_BASE_PREFIX << 16)
#define LCGetBase() ((void*)LC_BASE)

void LCEnable();
void LCDisable(void);
void LCLoadBlocks(void* destTag, void* srcAddr, u32 numBlocks);
void LCStoreBlocks(void* destAddr, void* srcTag, u32 numBlocks);
u32 LCLoadData(void* destAddr, void* srcAddr, u32 nBytes);
u32 LCStoreData(void* destAddr, void* srcAddr, u32 nBytes);
u32 LCQueueLength(void);
void LCQueueWait(u32 len);
void LCFlushQueue(void);

#ifdef __cplusplus
}
#endif

#endif // _DOLPHIN_OSCACHE
