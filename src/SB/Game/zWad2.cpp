#include "zWad2.h"
#include "iTime.h"

//                                  Data

// all long32's were replaced with S64

char buffer[16];
// Why is there a duplicate in dwarf?
//char buffer[16];
F32 scale;
U32 gFXSurfaceFlags;
basic_rect<F32> screen_bounds; // are these both correct?
basic_rect<F32> default_adjust;
xFXRing sPatrickStunRing[3];
xFXRing sThunderRing[1];
xFXRing sHammerRing[1];
xFXRing sPorterRing[2];
xFXRing sMuscleArmRing[1];
F32 defaultGooTimes[4];
F32 defaultGooWarbc[4];
zFXGooInstance zFXGooInstances[24];
ztextbox* sGooTimerTextBox;
iSndHandle sGooSndHandle;
iSndGroupHandle sGooSndGrpHandle;
xEnt* g_entForGoo[24];
xVec3 zfx_bubblehit_pos_rnd;
xVec3 zfx_bubblehit_vel_rnd;
F32 zfx_bubblehit_vel_scale;
xVec3 bubbletrail_pos_rnd;
xVec3 bubbletrail_vel_rnd;
F32 bubbletrail_vel_scale;
xVec3 bubblewall_scale;
xVec3 bubblewall_velscale;
U16 popper_weight_sizes[8];
popper_data poppers[8];
popper_data instantPopper;
entrail_type entrail_types[7];
entrail_data* entrails;
U32 entrails_size;
U32 ribbonCount;
xFXRibbon* ribbonPool;
U8* ribbonInUse;
F32 thresh;
// another duplicate?
//F32 thresh;
S32 sMemDepthJustHIPStartPlayer;
U32 sPlayerMarkerStartID;
F32 sGameOverTimer;
F32 sTimeElapsed;
F32 gRealTimeElapsed;
S64 sTimeLast;
S64 sTimeCurrent;
U32 gLevelChanged;
S32 g_hiphopReloadHIP;
S32 g_hiphopForcePortal;
S32 g_hiphopResetOnly;
S32 g_hiphopEnabled;
xColor_tag sFadeColor;
U32 gzAsyncSceneID;
U32 startPressed;
xColor_tag black;
xColor_tag clear;
U32 gSoak;
char** soaklevels;
char* allsoaklevels[33];
char* otherNonSoakLevels[44];
F32 SOAK_DELAY;
F32 SOAK_DELAYRAND;
F32 soaktime;
S32 doCallLogging;
S32 enableMemDebugLogging;
S32 enableHackNProbeLogging;
S32 enableSuperSoaker;
S32 enableMuttonMasher;
S32 superSoak_simulatePlayerAction;
U32 superSoakExtraPadOnInput;
U32 superSoakExtraPadPressInput;
xPortalAsset dummyPortalAsset;
_zPortal dummyPortal;
U32 loadMeter;
U32 loadCDMeter;
S64 t0;
S64 t1;
S64 w0;
S64 w1;
S64 gloop_time;
S64 gwait_time;
S32 gloop_ct;
F32 gloop_time_secs;
F32 gwait_time_secs;
F32 gloop_net_time_secs;
F32 snd_radius;
U32 gLastProfileDump;
void (*zSB04_BossPreRender)();
RwCamera* sGameScreenTransCam;
RpWorld* gWorld;
RpLight* DirectionalLight;
U32 bgID;
F32 bgu1;
F32 bgv1;
F32 bgu2;
F32 bgv2;
U8 bgr;
U8 bgg;
U8 bgb;
U8 bga;
S32 g_enableGameExtras;
S32 g_currDay;
S32 g_currMonth;
S32 g_gameExtraFlags;
EGGItemFuncs EGGModuleTest;
EGGItemFuncs EGGBirthDay;
EGGItemFuncs EGGSnow;
EGGItemFuncs EGGRain;
EGGItemFuncs EGGEmpty;
EGGItem g_eggBasket[2];
S32 g_flg_chEnabled;
F32 sCheatTimer;
S32 sCheatInputCount;
U32 sCheatAddShiny[16];
U32 sCheatAddSpatulas[16];
U32 sCheatBubbleBowl[16];
U32 sCheatCruiseBubble[16];
U32 sCheatMonsterGallery[16];
U32 sCheatArtTheatre[16];
U32 sCheatTestCheats[16];
U32 sCheatTargetCostumeSBCaveman[16];
U32 sCheatTargetCostumeSBRippedShorts[16];
U32 sCheatTargetCostumePatGoofyGoober[16];
U32 sCheatTargetCostumePatCaveman[16];
U32 sMaxHealth[16];
U32 sManliness[16];
U32 sGoofyGoober[16];
U32 sBubbleBash[16];
U32 sMachoBowl[16];
U32 sSonicGuitar[16];
U32 sBellyFlop[16];
U32 sPickupThrow[16];
U32 sAllMoves[16];
U32 sAllUpgradedMoves[16];
U32 sChaChing[16];
U32 sTenSkillPoints[16];
U32 sTenTreasureChests[16];
U32 sAllTasks[16];
GECheat cheatList[10];
U32 sCheatPressed[16];
xEnt* sGalleryTitle;
S32 gGameState;
eGameMode gGameMode;
_GameOstrich gGameOstrich;
U32 sGameMode_DispatchTable[13];
U32 sGameState_DispatchTable[8];
U32 sPauseState_DispatchTable[2];
U32 sSaveState_DispatchTable[3];
U32 sOptionsState_DispatchTable[1];
U32 sLoadState_DispatchTable[3];
U32 sTitleState_DispatchTable[2];
U32 sIntroState_DispatchTable[4];
U32 sGameState_DoDispatchTable[8];
U32 sPauseState_DoDispatchTable[2];
U32 sSaveState_DoDispatchTable[3];
U32 sOptionsState_DoDispatchTable[1];
U32 sLoadState_DoDispatchTable[3];
U32 sTitleState_DoDispatchTable[2];
U32 sIntroState_DoDispatchTable[4];
zGooParams* zgoo_gps;
S32 zgoo_ngps;
S32 zgoo_nused;
zGrapplePoint* sGrapplePoints;
S32 sNumGrapplePoints;
xGrid colls_grid;
xGrid colls_oso_grid;
xGrid npcs_grid;
xGrid grabbable_grid;
S32 zGridInitted;
zHangableObject* sPlayerHangObj;
xVec3 playerDPos;
zHangableObject* sHangableObjects;
S32 sNumHangableObjects;
zHitSourceMapEntry zHitSourceMap[22];
U32 zHitSourceCCs[21];
U32 zHitTargetCCs[7];
S32 sPatTongueLastCount;
RwRaster* sLassoRaster;
zLassoGuideList sGuideList[64];
U32 sNumGuideLists;
zLassoGuide* sCurrentGuide;
RxObjSpace3DVertex* lnverts;
S32 negativeHondaX;
PatTongueVert sPatMouthVert[12];
PatTongueVert sPatTipVert[12];
PatTongueVert sPatTeethVert[2];
xVec3 sPatHitchPos;
RwMatrixTag sPatTongueTipMatrix;
xVec3 sPatTongueLastVec[16];
xVec3 sPatTongueLastRight;
_zLight* sLight[32];
S32 sLightTotal;
_tagPartition sLightPart;
zVolume* sPartitionVolume;
S32 gNumTemporaryLights;
_zLight* gTemporaryLights[32];
// "illegal use of void"
//void (*sEffectFuncs)(_zLight*, F32)[18];
//void (*sEffectInitFuncs)(_zLight*)[18];
xVec3 sDefaultShadowVec;
zLightning* sLightning;
zParEmitter* sSparkEmitter;
RwRaster* sLightningRaster;
RwRaster* sLightningRasterBranch;
RwTexture* sLightningParticleRaster;
F32 LIGHTNING_FADE_DIST_SQR;
F32 LIGHTNING_CULL_DIST_SQR;
xFuncPiece sLFuncX[10];
xFuncPiece sLFuncY[10];
xFuncPiece sLFuncZ[10];
xVec3 sLFuncVal[10];
xVec3 sLFuncSlope[2][10];
F32 sLFuncEnd[10];
F32 sLFuncJerkFreq;
F32 sLFuncJerkTime;
F32 sLFuncShift;
F32 sLFuncMaxPStep;
F32 sLFuncMinPStep;
F32 sLFuncMinScale;
F32 sLFuncMaxScale;
F32 sLFuncScalePerLength;
F32 sLFuncMinSpan;
F32 sLFuncSpanPerLength;
F32 sLFuncSlopeRange;
F32 sLFuncUVSpeed;
F32 sLFuncUVOffset;
zLightningFuncPiece sLFuncNew[11];
_tagLightningAdd gLightningTweakAddInfo;
xVec3 sTweakStart;
xVec3 sTweakEnd;
tweak_callback sLightningStartCB;
tweak_callback sLightningChangeCB;
CollisionInfo collisionInfo;
xVec3* posArray;
xVec3 sPoint[5];
F32 sSize[5];
S32 system_count;
lightweight_system_base* system[10];
U32 sLODTableCount;
zLODTable* sLODTableList;
U32 sManagerIndex;
U32 sManagerCount;
F32 sLODFadeDistance;
zLODManager sManagerList[2048];
S32 sFirstBoot;
S32 logoTmr;
F32 time_elapsed;
F32 time_last;
F32 time_current;
F32 sAttractMode_timer;
F32 sOneLiner_timer;
S32 promptSel;
S32 card;
S32 var;
S32 fullCard;
S32 sInMenu;
F32 ONELINER_WAITTIME;
F32 holdTmr;
U8 sAllowAttract;
PowerUpMenuTableEntry sPowerUpMenuTable[11];
U32 sPowerUpMenuTableSize;
char* cPowerUpMenuRefreshGroupName;
PowerUpMovieTableEntry sPowerUpMovieTable[10];
U32 sPowerUpMovieTableSize;
taskEntry sDefaultWorldTasks[20];
U32 sNumWorlds;
extraEntry sExtrasList[50];
U32 sNumExtras;
U8 sNumChestsNeeded;
eFMVFile sExtrasMovieList[14];
S32 sExtrasMovieListSize;
extraCostumeEntry sExtraCostumeList[8];
U32 sExtraCostumeListSize;
U8 bNoChatter;
xModelInstance* tempModel;
U32 sNextSceneID;
xVec3 sparkleStart;
xVec3 sparkleEnd;
xVec3 sparkleScale;
xVec3 sparkleVel;
F32 sparkleTime;
F32 totalTimeForEffect;
F32 multiplier;
F32 randomYOffset;
F32 probability;
zUITextAsset* powerupText[10];
S32 powerupIndex;
U8 effectStarted;
F32 fmvDelay;
iSndHandle upgradeSound;
iSndGroupHandle upgradeSoundGroupHandle;
xSoundFX* sCurrentChatter;
zMovePoint* g_mvpt_list;
S32 g_mvpt_cnt;
zMusicTrackInfo sMusicTrack[2];
xSndGroup* spMusicGroup;
zMusicState sMusic;
F32 gDialogueMusicLevel;
S32 g_modinit;
zNPCMgr* g_npcmgr;
NPCBrainTableEntry g_brainTable[67];
char* EVENT_TYPE_STRINGS[49];
//_anon5 __vt__Q24zNPC4base;
//S32 (*zNPCMgr_OrdComp_npcid)(void*, void*);
S32 (*zNPCMgr_OrdTest_npcid)(void*, void*);
zGlobals globals;
xQCControl xqc_def_ctrl;
extern const xVec3 g_O3;
xGlobals* xglobals;
S32 (*MVPT_dflt_chklos)(void*, xVec3*, zMovePoint*);
//void (*zMovePointEventCB)(xBase*, xBase*, U32, F32*, xBase*, U32);
U32 gActiveHeap;
_tagGameVidMode gVidMode;
//_anon6 __vt__22zUICustomPalRedirector;
//_anon40 __vt__9zUICustom;
//_anon36 __vt__21zUICustomDialogPlayer;
//_anon14 __vt__33zUICustomUpgradeTutorialContoller;
U32 ourGlobals[4096];
//_anon22 __vt__20zUICustomLoadingText;
//_anon39 __vt__18zUICustomExtrasArt;
//_anon37 __vt__20zUICustomExtrasSound;
//_anon30 __vt__19zUICustomExtrasIcon;
//_anon44 __vt__22zUICustomExtrasManager;
F32 SECS_PER_VBLANK;
U32 SCENE_ID_MNU_START;
extern _tagTRCPadInfo gTrcPad[4];
xVec3 m_Null;
_tagxPad mPad[4];
U32 gFrameCount;
xColor_tag g_CLEAR;
xColor_tag g_BLACK;
_zEnv* gCurEnv;
xMat4x3 g_I3;
//xEnt* (*AddToLODList)(xEnt*, xScene*, void*);
U8 HDR_brightening;
tagiRenderArrays gRenderArr;
// xColor_tag g_WHITE;
_tagxPad* gDebugPad;
//void (*lightningTweakStart)(tweak_info&);
void (*EventCB)(xBase*, xBase*, U32, F32*, xBase*, U32);
RpWorld* gLightWorld;
//void (*zLightEventCB)(xBase*, xBase*, U32, F32*, xBase*, U32);
void (*zHangable_EventCB)(xBase*, xBase*, U32, F32*, xBase*, U32);
S32 gCartwheelButton;
S32 gBowlButton;
S32 gBashButton;
xVec3 m_UnitAxisY;
eSNDCurrentPlayer gCurrentPlayer;
U32 FB_XRES;
U32 FB_YRES;
F32 VBLANKS_PER_SEC;
U32 gBusStopIsRunning;
xSndGlobals gSnd;
U32 gSceneFrameCount;
F32 speedOfSound;
//void (*on_spawn_bubble_wall)(tweak_info&);
void (*RenderThread)(void*);
//_anon45 __vt__14zLoadingScreen;
//_anon46 __vt__Q26zAsync6Screen;
xVec3 g_Y3;
RpAtomic* (*gAtomicRenderCallBack)(RpAtomic*);
//RpAtomic* (*AtomicDefaultRenderCallBack)(RpAtomic*);
RxPipeline* xFXgooPipeline;
RpAtomic* (*zFXGooRenderAtomic)(RpAtomic*);
U8 _enabled;
void (*cb_dispatch)(xBase*, xBase*, U32, F32*, xBase*, U32);
//_anon38 __vt__9zNMEMindy;
//_anon19 __vt__12zNMEFriendly;
//_anon9 __vt__10zNMECommon;
//_anon3 __vt__14zNMENPCWrapper;
//_anon2 __vt__14zNMETongueSpin;
//_anon35 __vt__9zNMESBBat;
//_anon13 __vt__15zBossCam_Binary;
//_anon11 __vt__4xCam;
//_anon0 __vt__11zNMENeptune;
////_anon12 __vt__8zNMEBoss;
//_anon4 __vt__10zNMEDenToo;
//_anon34 __vt__15DennisLetMeKnow;
//_anon29 __vt__8xPSYNote;
//_anon26 __vt__10zNMEDennis;
//_anon20 __vt__12zNMEFrogfish;
//_anon27 __vt__13zNMEBuckotron;
//_anon8 __vt__13MervLetMeKnow;
//_anon28 __vt__10zNMEMervyn;
//_anon21 __vt__12zNMEStandard;
//_anon25 __vt__12ZapLetMeKnow;
//////_anon23 __vt__10zNMEZapper;
//_anon18 __vt__10zNMEPopper;
//_anon42 __vt__11zNMESpinner;
//_anon15 __vt__14FlingLetMeKnow;
//_anon1 __vt__11zNMEFlinger;
//_anon32 __vt__11zNMESlammer;
//_anon24 __vt__10zNMEFogger;
//_anon47 __vt__13zNMETurSpiral;
//_anon31 __vt__10zNMETurret;
//_anon17 __vt__13zNMETurTurner;
//_anon41 __vt__12zNMETurPopup;
//_anon7 __vt__13zNMETurBarrel;
///_anon16 __vt__13zNMECritJelly;
//_anon33 __vt__11zNMECritter;
///_anon10 __vt__13zNMECritBasic;
//_anon43 __vt__8zNMETiki;

//

//                                   zNPCMgr

struct NPCMTypeTable //     ported from bfbb
{
    en_npctyp useNPCType;
    char* modelName;
    unsigned int hashOfName;
} g_tbltype[250];

S32 zNPCMgr_OrdComp_npcid(void* vkey, void* vitem)
{
    S32 rc;
    U32 item;
    U32 key;

    key = *(U32*)vkey;
    item = *(U32*)vitem;
    if (key < item)
    {
        rc = -1;
    }
    else if (key > item)
    {
        rc = 1;
    }
    else
    {
        rc = 0;
    }

    return rc;
}

// S32 zNPCMgr_OrdTest_npcid(void* vkey, void* vitem)
// {
//     S32 rc;
//     void* key = *(void**)(vitem);

//     if (vkey < key)
//     {
//         rc = -1;
//     }
//     else if (vkey > key)
//     {
//         rc = 1;
//     }
//     else
//     {
//         rc = 0;
//     }

//     return rc;
// }

void zNPCMgr::Shutdown()
{
    if (this->npcFactory != NULL)
    {
        delete this->npcFactory;
    }
    this->npcFactory = NULL;
}

void zNPCMgr_scenePostInit()
{
}

void zNPCMgr_sceneReset()
{
}

void zNPCMgr_sceneFinish()
{
}

void zNPCMgr_scenePrepare(S32 npccnt) // npccnt may not be right. code was ported
{
}

void zNPCMgr_Shutdown()
{
    g_modinit--;
    if (g_modinit == 0)
    {
        zNPCMgr* mgr = zNPCMgrSelf();
        if (mgr != NULL)
        {
            mgr->Shutdown();
            delete mgr;
            g_npcmgr = NULL;
        }
        zNPCMgr_Shutdown();
        xBehaveMgr_Shutdown();
    }
}

void zNPCMgr_Startup()
{
    if (g_modinit++ == 0)
    {
        xBehaveMgr_Startup();
        zNPCMgr* npc = new ('NPCM', NULL) zNPCMgr();
        g_npcmgr = npc;
        npc->Startup();
    }
}

zNPCMgr* zNPCMgr_GetNPCList()
{
    return g_npcmgr;
}

zNPCMgr* zNPCMgrSelf()
{
    return g_npcmgr;
}

//                                                      zMenu

void zMenuAllowAtract(bool allowAttract)
{
    sAllowAttract = allowAttract;
}

void zMenuPause(bool bPause)
{
    S64 time;
    U32 Utime;

    if (bPause == FALSE)
    {
        Utime = iTimeGet();
        time = iTimeDiffSec((U64)Utime >> 0x20);
        time_last = time - SECS_PER_VBLANK;
        Utime = iTimeGet();
    }

    sTimeLast = Utime >> 0x20;
}

S32 zMenuIsFirstBoot()
{
    return sFirstBoot;
}

U32 zMenuGetBadCard()
{
    return card + 1;
}

void zMenuExit()
{
}

S32 zMenuRunning()
{
    return sInMenu;
}

//                                              zLOD

zLODTable* zLOD_Get(xEnt* ent)
{
    if (!ent->model)
    {
        return 0;
    }

    for (int i = 0; i < sLODTableCount; i++)
    {
        if (sLODTableList[i].baseBucket != NULL)
        {
            if ((*sLODTableList[i].baseBucket)->OriginalData == ent->model->Data)
            {
                return &sLODTableList[i];
            }
        }
    }
    return 0;
}

//                                              z::lightweight_manager

// These are in the dwarf, but you have to find them with just "lightweight_manager"

// void z::lightweight_manager::setup()
// {
// }

//                                              zLightning

void _zLightningKill(zLightning* l)
{
}

void zLightningKill(zLightning* l)
{
}

//                                              zLightEffect

void zLightEffectInitCauldron(_zLight* zlight)
{
    *zlight->reg = 0.0f;
    zlight->flags = zlight->flags | 1;
}

void zLightEffectRandomColFast(_zLight* zlight, F32)
{
}

void zLightEffectRandomCol(_zLight* zlight, F32)
{
}

void zLightEffectRandomColSlow(_zLight* zlight, F32)
{
}

void zLightEffectHalfDimFast(_zLight* zlight, F32)
{
}

void zLightEffectHalfDim(_zLight* zlight, F32)
{
}

void zLightEffectHalfDimSlow(_zLight* zlight, F32)
{
}

void zLightEffectDimFast(_zLight* zlight, F32)
{
}

void zLightEffectDim(_zLight* zlight, F32)
{
}

void zLightEffectDimSlow(_zLight* zlight, F32)
{
}

void zLightEffectStrobeFast(_zLight* zlight, F32)
{
}

void zLightEffectStrobe(_zLight* zlight, F32)
{
}

void zLightEffectStrobeSlow(_zLight* zlight, F32)
{
}

void zLightEffectInitFlicker(_zLight* zlight)
{
    *zlight->reg = 0.0f;
    zlight->flags = zlight->flags | 1;
}

void zLightEffectInitRandomCol(_zLight*)
{
}

void zLightEffectInitHalfDim(_zLight*)
{
}

void zLightEffectInitDim(_zLight*)
{
}

void zLightEffectInitStrobe(_zLight*)
{
}

//                                              zLight

void zLightSetVolume(zVolume* vol)
{
    if (!vol)
    {
        sPartitionVolume = 0;
    }
    else
    {
        U32 lp_id = xStrHash("LIGHT_PARTITION" + 9);
        if (vol->id == lp_id)
        {
            sPartitionVolume = vol;
        }
    }
}

void zLightRemoveLocalEnv()
{
    int i;
    const RwLLLink* link;

    for (i = 0; i < gNumTemporaryLights; i++)
    {
        link = gLightWorld->directionalLightList.link.prev;
        link->prev->next = link->next;
        link->next->prev = link->prev;
    }
    gNumTemporaryLights = 0;
}

void zLightAddLocal(xEnt* ent)
{
}

void zLightLoad(_zLight* ent, xSerial* s)
{
    xBaseLoad(ent, s);
}

void zLightSave(_zLight* ent, xSerial* s)
{
    xBaseSave(ent, s);
}

void zLightDestroyAll()
{
    S32 total = sLightTotal;

    for (int i = 0; i < total; i++, sLightTotal--)
    {
        zLightDestroy(sLight[i]);
    }
    sLightTotal = 0;
}

void zLightResolveLinks()
{
    S32 i;
    _zLight* zl;

    for (i = 0; i < sLightTotal; i++)
    {
        zl = sLight[i];
        if (zl->tasset->attachID)
        {
            zl->attached_to = zSceneFindObject(zl->tasset->attachID);
        }
        else
        {
            zl->attached_to = 0;
        }
    }
}

void zLightInit(void* b, void* tasset)
{
    zLightInit((xBase*)b, (zLightAsset*)tasset);
}

//                                              zPat / zLasso

//                                              zGrid

void zGridExit(zScene* s)
{
    xGridKill(&colls_grid);
    xGridKill(&colls_oso_grid);
    xGridKill(&npcs_grid);
    xGridKill(&grabbable_grid);
    zGridInitted = 0;
}

//                                              zGoo

void zGooExit()
{
    zgoo_gps = 0;
    zgoo_ngps = 0;
    zgoo_nused = 0;
}

void zGooInit(S32 nobj)
{
    zgoo_gps = (zGooParams*)xMemAlloc(gActiveHeap, nobj * 0xc, 0);
    zgoo_ngps = nobj;
}

//                                              zGameState

//xSndMgrPauseSounds

void zGameStatePauseUnpauseSnd(bool pause)
{
    xSndMgrPauseSounds(0, pause, TRUE);
    xSndMgrPauseSounds(1, pause, TRUE);
    xSndMgrPauseSounds(2, pause, FALSE);
}

void SB04FMVPauseSoundCB(bool doPause)
{
    bool tempBool;

    if (gGameMode == 8)
    {
        tempBool = TRUE;
    }
    else if (gGameMode == 7)
    {
        tempBool = TRUE;
    }
    else if (gGameMode == 6)
    {
        tempBool = TRUE;
    }
    else if (gGameMode == 2)
    {
        tempBool = TRUE;
    }
    else if (gGameMode == 4)
    {
        tempBool = TRUE;
    }
    else if (gGameMode == 6)
    {
        tempBool = TRUE;
    }
    else if (gGameMode == 1)
    {
        tempBool = TRUE;
    }
    else if (gGameMode == 0)
    {
        tempBool = TRUE;
    }
    else
    {
        tempBool = FALSE;
    }

    if (tempBool)
    {
        xSndMgrPauseSounds(3, doPause, TRUE);
    }
    else if (doPause != 0)
    {
        xSndMgrPauseSounds(-3, TRUE, TRUE);
    }
    else
    {
        xSndMgrPauseSounds(-3, FALSE, TRUE);
    }
}

void zGameSetOstrich(_GameOstrich o)
{
    gGameOstrich = o;
}

_GameOstrich zGameGetOstrich()
{
    return gGameOstrich;
}

eGameMode zGameModeGet()
{
    return gGameMode;
}

S32 zGameStateGet()
{
    return gGameState;
}

//                                                  zGameExtras / EGG

void zGameExtras_Load(xSerial* xser)
{
    S32 keepers[2];
    keepers[0] = 0;
    xser->Read(keepers);
    g_flg_chEnabled |= keepers[0];
}

void zGameExtras_Save(xSerial* xser)
{
    xser->Write(g_flg_chEnabled & 0xFFFF);
}

S32 zGameExtras_CheatFlags()
{
    return g_flg_chEnabled;
}

S32 EGG_check_ExtrasFlags(EGGItem*)
{
    switch (g_currMonth)
    {
    case JANUARY:
        if (g_currDay == 1) // New Year's Day
            g_gameExtraFlags |= 0b000000001;
        break;

    case FEBRUARY:
        if (g_currDay == 2)
            g_gameExtraFlags |= 0b100000000;
        break;

    case MARCH:
        if (g_currDay == 15)
            g_gameExtraFlags |= 0b000001000;
        if (g_currDay == 17) // St. Patrick's Day
            g_gameExtraFlags |= 0b000000100;
        if (g_currDay == 18)
            g_gameExtraFlags |= 0b100000000;
        if (g_currDay == 21)
            g_gameExtraFlags |= 0b100000000;
        if (g_currDay == 22)
            g_gameExtraFlags |= 0b100000000;
        break;

    case APRIL:
        if (g_currDay == 1) // April Fools' Day
            g_gameExtraFlags |= 0b010000000;
        break;

    case MAY:
        break;

    case JUNE:
        if (g_currDay == 6)
            g_gameExtraFlags |= 0b001000000;
        break;

    case JULY:
        if (g_currDay == 4) // Independence Day
            g_gameExtraFlags |= 0b000000010;
        break;

    case AUGUST:
        if (g_currDay == 8)
            g_gameExtraFlags |= 0b100000000;
        break;

    case SEPTEMBER:
        if (g_currDay == 8)
            g_gameExtraFlags |= 0b000000010;
        break;

    case OCTOBER:
        if (g_currDay == 5)
            g_gameExtraFlags |= 0b100000000;
        if (g_currDay == 14)
            g_gameExtraFlags |= 0b100000000;
        if (g_currDay == 22)
            g_gameExtraFlags |= 0b100000000;
        if (g_currDay == 31) // Halloween
            g_gameExtraFlags |= 0b000100000;
        break;

    case NOVEMBER:
        if (g_currDay == 5)
            g_gameExtraFlags |= 0b100000000;
        break;

    case DECEMBER:
        break;
    }

    return 0;
}

void zGameExtras_SceneReset()
{
    if (!g_enableGameExtras)
    {
        return;
    }

    EGGItem* egg_next = g_eggBasket;

    while (egg_next->fun_check)
    {
        EGGItem* egg = egg_next++;

        if (egg->enabled)
        {
            if (egg->funcs->fun_reset)
            {
                egg->funcs->fun_reset(egg);
            }
        }
    }
}

void zGameExtras_MoDay(S32* month, S32* day)
{
    *month = g_currMonth;
    *day = g_currDay;
}

S32 zGameExtras_ExtrasFlags()
{
    return g_gameExtraFlags;
}

//                                          zGame

void DoTheResetinator()
{
}

void zGameStall()
{
    bool tempGameBool;
    if (gGameMode == 8)
    {
        tempGameBool = TRUE;
    }
    else if (gGameMode == 7)
    {
        tempGameBool = TRUE;
    }
    else if (gGameMode == 6)
    {
        tempGameBool = TRUE;
    }
    else if (gGameMode == 2)
    {
        tempGameBool = TRUE;
    }
    else if (gGameMode == 4)
    {
        tempGameBool = TRUE;
    }
    else if (gGameMode == 6)
    {
        tempGameBool = TRUE;
    }
    else if (gGameMode == 1)
    {
        tempGameBool = TRUE;
    }
    else if (gGameMode == 0)
    {
        tempGameBool = TRUE;
    }
    else
    {
        tempGameBool = FALSE;
    }

    if (!tempGameBool) // chain of if elses
    {
        zGameModeSwitch(eGameMode_Stall);
        xSndMgrPauseSounds(0, TRUE, TRUE);
        xSndMgrPauseSounds(1, TRUE, TRUE);
        xSndMgrPauseSounds(2, TRUE, FALSE);
        iPadStopRumble(globals.pad[1]);
        zEntEvent("techbutton6_click", 24);
    }
}
