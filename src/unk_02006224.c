#include <nitro.h>
#include <string.h>

#include "struct_decls/struct_0202CC84_decl.h"

#include "struct_defs/struct_02004CB4.h"

#include "unk_02003B60.h"
#include "unk_020041CC.h"
#include "unk_02005474.h"
#include "unk_0201D15C.h"
#include "unk_0202CC64.h"

BOOL sub_02006224(void);
BOOL sub_02006260(const UnkStruct_0202CC84 * param0);
BOOL sub_0200629C(const UnkStruct_0202CC84 * param0, u32 param1, int param2, int param3);
void sub_02006350(void);
MICResult sub_0200637C(void);
MICResult sub_020063B8(void);
void sub_020063C0(UnkStruct_0202CC84 * param0);
void sub_020063D4(u8 param0);
BOOL sub_020063E4(UnkStruct_0202CC84 * param0, u32 param1, int param2, int param3);
BOOL sub_02006438(UnkStruct_0202CC84 * param0, u32 param1, int param2, int param3, u8 param4);
int Sound_Chatter(UnkStruct_0202CC84 * param0);
BOOL sub_020064C8(int param0);

BOOL sub_02006224 (void)
{
    u8 * v0 = sub_02003D5C(16);
    u8 * v1 = sub_02003D5C(30);

    if (*v1 == 1) {
        if (*v0 == 1) {
            if (sub_02004D04(14) == 0) {
                sub_02006350();
                return 1;
            }
        } else {
            sub_02006350();
            return 1;
        }
    }

    return 0;
}

BOOL sub_02006260 (const UnkStruct_0202CC84 * param0)
{
    u8 * v0 = sub_02003D5C(31);
    u8 * v1 = sub_02003D5C(54);

    if (sub_0202CCA4(param0) == 0) {
        return 0;
    }

    if (*v1 == 1) {
        return 0;
    }

    if (*v0 == 1) {
        return 0;
    }

    return 1;
}

BOOL sub_0200629C (const UnkStruct_0202CC84 * param0, u32 param1, int param2, int param3)
{
    u16 v0;
    int v1, v2;
    s8 * v3 = sub_02005014();
    u8 * v4 = sub_02003D5C(30);

    if (sub_02006260(param0) == 0) {
        return 0;
    }

    if (param3 < 0) {
        v2 = 64 + (param3 / 2);
    } else {
        v2 = 64 + (param3 / 2);
    }

    sub_0200592C(0);
    sub_02006350();
    sub_02004BCC(14);

    v0 = (LCRNG_Next() % 8192);
    sub_0202CCB4(v3, sub_0202CCB0(param0));

    {
        UnkStruct_02004CB4 v5;

        v5.unk_00 = sub_02004B78(14);
        v5.unk_04 = NNS_SND_WAVE_FORMAT_PCM8;
        v5.unk_08 = sub_02005014();
        v5.unk_0C = 0;
        v5.unk_10 = 0;
        v5.unk_14 = (2000 * 1);
        v5.unk_18 = 2000;
        v5.unk_1C = param2;
        v5.unk_20 = (32768 + v0);
        v5.unk_24 = v2;

        v1 = sub_02004CB4(&v5, 14);
        sub_02004D40(14, param2);
    }

    *v4 = 1;
    sub_020063D4(0);

    return v1;
}

void sub_02006350 (void)
{
    u8 * v0 = sub_02003D5C(16);
    u8 * v1 = sub_02003D5C(30);

    if (*v0 == 1) {
        sub_02004E84(14);
        sub_02004C4C(14);
    }

    *v1 = 0;
    return;
}

MICResult sub_0200637C (void)
{
    MICAutoParam v0;

    v0.type = MIC_SAMPLING_TYPE_SIGNED_8BIT;
    v0.buffer = sub_02005014();
    v0.size = (2000 * 1);

    if ((v0.size & 0x1f) != 0) {
        v0.size &= 0xffffffe0;
    }

    v0.rate = HW_CPU_CLOCK_ARM7 / 2000;
    v0.loop_enable = 0;
    v0.full_callback = NULL;
    v0.full_arg = NULL;

    return sub_02004B5C(&v0);
}

MICResult sub_020063B8 (void)
{
    return sub_02004B64();
}

void sub_020063C0 (UnkStruct_0202CC84 * param0)
{
    sub_0202CCEC(param0, (const s8 *)sub_02005014());
    return;
}

void sub_020063D4 (u8 param0)
{
    u8 * v0 = sub_02003D5C(31);

    *v0 = param0;
    return;
}

BOOL sub_020063E4 (UnkStruct_0202CC84 * param0, u32 param1, int param2, int param3)
{
    int v0;
    UnkStruct_0202CC84 ** v1 = sub_02003D5C(36);

    if (param0 == NULL) {
        v0 = sub_0200629C(*v1, param1, param2, param3);
    } else {
        v0 = sub_0200629C(param0, param1, param2, param3);
    }

    if (v0 == 0) {
        sub_020063D4(1);
        v0 = sub_020059D0(0, 441, param3, param2, 11, 0);
    }

    return v0;
}

BOOL sub_02006438 (UnkStruct_0202CC84 * param0, u32 param1, int param2, int param3, u8 param4)
{
    int v0;
    UnkStruct_0202CC84 ** v1 = sub_02003D5C(36);

    if (param0 == NULL) {
        v0 = sub_0200629C(*v1, param1, param2, param3);
    } else {
        v0 = sub_0200629C(param0, param1, param2, param3);
    }

    if (v0 == 0) {
        sub_020063D4(1);
        sub_02005F4C(0, 441, param3, param2, 11, param4, 0);
        v0 = 1;
    }

    return v0;
}

int Sound_Chatter (UnkStruct_0202CC84 * param0)
{
    const s8 * v0;
    s8 v1;

    if (sub_0202CCA4(param0) == 0) {
        return 0;
    }

    v0 = sub_0202CCB0(param0);
    v1 = v0[15];

    if ((-128 <= v1) && (v1 < -30)) {
        return 1;
    }

    if ((30 <= v1) && (v1 < 128)) {
        return 2;
    }

    return 0;
}

BOOL sub_020064C8 (int param0)
{
    switch (param0) {
    case 0:
    case 1:
    case 5:
    case 11:
    case 12:
        return 1;
    }

    return 0;
}
