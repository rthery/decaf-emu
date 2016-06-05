#pragma once
#include "../cpu.h"
#include "../espresso/espresso_instructionid.h"

namespace cpu
{
namespace jit
{

void initialise();

void clearCache();
void resume(Core *core);

bool hasInstruction(espresso::InstructionID instrId);

}
}

void fallbacksPrint();
