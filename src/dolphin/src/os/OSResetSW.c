#include <dolphin/os.h>

extern OSTime __OSGetSystemTime();

u8 GameChoice : (OS_BASE_CACHED | 0x30E3);

vu32 __PIRegs[12] : 0xCC003000;

extern OSTime __OSStartTime;

static OSResetCallback ResetCallback;
static BOOL Down;
static BOOL LastState;
static OSTime HoldUp;
static OSTime HoldDown;

void __OSResetSWInterruptHandler(__OSInterrupt interrupt, OSContext* context)
{
    OSResetCallback callback;

    HoldDown = __OSGetSystemTime();
    while (__OSGetSystemTime() - HoldDown < OSMicrosecondsToTicks(100) &&
           !(__PIRegs[0] & 0x00010000))
    {
        ;
    }
    if (!(__PIRegs[0] & 0x00010000))
    {
        LastState = Down = TRUE;
        __OSMaskInterrupts(OS_INTERRUPTMASK_PI_RSW);
        if (ResetCallback)
        {
            callback = ResetCallback;
            ResetCallback = NULL;
            callback();
        }
    }
    __PIRegs[0] = 2;
}

OSResetCallback OSSetResetCallback(OSResetCallback callback)
{
    BOOL enabled;
    OSResetCallback prevCallback;

    enabled = OSDisableInterrupts();
    prevCallback = ResetCallback;
    ResetCallback = callback;

    if (callback)
    {
        __PIRegs[0] = 2;
        __OSUnmaskInterrupts(0x200);
    }
    else
    {
        __OSMaskInterrupts(0x200);
    }
    OSRestoreInterrupts(enabled);
    return prevCallback;
}

BOOL OSGetResetButtonState(void)
{
    BOOL enabled;
    BOOL state;
    u32 reg;
    OSTime now;

    enabled = OSDisableInterrupts();

    now = __OSGetSystemTime();

    reg = __PIRegs[0];
    if (!(reg & 0x00010000))
    {
        if (!Down)
        {
            Down = TRUE;
            state = HoldUp ? TRUE : FALSE;
            HoldDown = now;
        }
        else
        {
            state = (HoldUp || (OSMicrosecondsToTicks(100) < now - HoldDown)) ? TRUE : FALSE;
        }
    }
    else if (Down)
    {
        Down = FALSE;
        state = LastState;
        if (state)
        {
            HoldUp = now;
        }
        else
        {
            HoldUp = 0;
        }
    }
    else if (HoldUp && (now - HoldUp < OSMillisecondsToTicks(40)))
    {
        state = TRUE;
    }
    else
    {
        state = FALSE;
        HoldUp = 0;
    }

    LastState = state;

    if (GameChoice & 0x1f)
    {
        OSTime fire = (GameChoice & 0x1f) * 60;
        fire = __OSStartTime + OSSecondsToTicks(fire);
        if (fire < now)
        {
            now -= fire;
            now = OSTicksToSeconds(now) / 2;
            if ((now & 1) == 0)
            {
                state = TRUE;
            }
            else
            {
                state = FALSE;
            }
        }
    }

    OSRestoreInterrupts(enabled);
    return state;
}
