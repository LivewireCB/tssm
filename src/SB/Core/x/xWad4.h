#ifndef XWAD4_H
#define XWAD4_H

#include "xCollide.h"
#include "iCollide.h"
#include "xEnt.h"
#include "xBase.h"
#include "xScene.h"
#include "zBase.h"
#include "xutil.h"
#include "xRMemData.h"
#include "xMemMgr.h"
#include "xhipio.h"
#include "xordarray.h"
#include "xpkrsvc.h"
#include "xPar.h"
#include "xParMgr.h"
#include "xParGroup.h"
#include "xParCmd.h"
#include "xPad.h"
#include "xVec3Inlines.h"
#include "xMath.h"
#include "xMathInlines.h"

void iParMgrRender();
void iParMgrUpdate(F32);
void iParMgrInit();

#endif
