// Copyright Camperfire Studios


#include "AbilitySystem/Abilities/AuraProjectileSpell.h"
#include <Kismet\KismetSystemLibrary.h>

void UAuraProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
					 const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) 
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	UKismetSystemLibrary::PrintString(this, FString("Activate ability in c++"), true, true, FColor::Yellow, 3);

}

