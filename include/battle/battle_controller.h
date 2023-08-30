#ifndef POKEPLATINUM_BATTLE_CONTROLLER_H
#define POKEPLATINUM_BATTLE_CONTROLLER_H

#include "struct_decls/battle_system.h"
#include "battle/battle_context.h"

enum BattleControlSequence {
    BATTLE_CONTROL_GET_BATTLE_MON = 0,
    BATTLE_CONTROL_START_ENCOUNTER,
    BATTLE_CONTROL_TRAINER_MESSAGE,
    BATTLE_CONTROL_SHOW_BATTLE_MON,
    BATTLE_CONTROL_INIT_COMMAND_SELECTION,
    BATTLE_CONTROL_COMMAND_SELECTION_INPUT,
    BATTLE_CONTROL_CALC_TURN_ORDER,

    BATTLE_CONTROL_FIGHT = 13,
    BATTLE_CONTROL_ITEM,
    BATTLE_CONTROL_PARTY,
    BATTLE_CONTROL_RUN,

    BATTLE_CONTROL_SAFARI_BALL,
    BATTLE_CONTROL_SAFARI_BAIT,
    BATTLE_CONTROL_SAFARI_ROCK,
    BATTLE_CONTROL_SAFARI_WAIT,

    BATTLE_CONTROL_EXEC_SCRIPT = 21,

    BATTLE_CONTROL_AFTER_MOVE = 39,

    BATTLE_CONTROL_RESULT = 41,

    BATTLE_CONTROL_END_WAIT = 44,
};

void *BattleContext_New(BattleSystem *battleSys);
int BattleController_Main(BattleSystem *battleSys, BattleContext *battleCtx);
void BattleContext_Free(BattleContext *battleCtx);
void BattleController_CheckMoveHitEffect(BattleSystem *battleSys, BattleContext *battleCtx, int attacker, int defender, int move);

#endif // POKEPLATINUM_BATTLE_CONTROLLER_H
