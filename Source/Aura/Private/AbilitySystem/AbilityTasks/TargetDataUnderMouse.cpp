// Copyright Camperfire Studios


#include "AbilitySystem/AbilityTasks/TargetDataUnderMouse.h"

UTargetDataUnderMouse* UTargetDataUnderMouse::CreateTargetDataUnderMouse(UGameplayAbility* OwningAbility)
{
	UTargetDataUnderMouse* MyObj = NewAbilityTask<UTargetDataUnderMouse>(OwningAbility);
	return MyObj;
}

void UTargetDataUnderMouse::Activate() {
	
	FHitResult CursorHit;
	Ability->GetCurrentActorInfo()->PlayerController->GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	ValidData.Broadcast(CursorHit.Location);
}