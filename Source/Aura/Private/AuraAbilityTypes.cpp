#pragma once

#include "AuraAbilityTypes.h"

/** Custom serialization, subclasses must override this */
bool FAuraGameplayEffectContext::NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess)
{


	return true;
}