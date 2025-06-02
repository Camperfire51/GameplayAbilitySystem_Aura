// Copyright Camperfire Studios


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include <Interaction/EnemyInterface.h>


AAuraPlayerController::AAuraPlayerController() 
{
	bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;
	
	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();

	/*
	* Line trace from cursor. There are several scenerios:
	* A. LastActor is nullptr, ThisActor is nullptr: Do nothing. Easy.
	* B. LastActor is nullptr, ThisActor is valid: We are hovering over this actor for the first time. Highlight ThisActor.
	* C. LastActor is valid, ThisActor is nullptr: We are no longer hovering over LastActor. Unhighlight LastActor.
	* D. LastActor is valid, ThisActor is valid but LastActor != ThisActor: We are hovering over a different actor. Unhighlight LastActor, highlight ThisActor.
	* E. LastActor is valid, ThisActor is valid and LastActor == ThisActor: We are still hovering over the same actor. Do nothing.
	*/

	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			//Case B: Highlight ThisActor
			ThisActor->HighlightActor();
		}
		else
		{
			//Case A: Do nothing, unnecessary but for clarity
		}
	}
	else // LastActor is valid
	{
		if (ThisActor == nullptr)
		{
			//Case C: Unhighlight LastActor
			LastActor->UnhighlightActor();
		}
		else // Both Actors are valid.
		{
			if (LastActor != ThisActor)
			{
				// Case D
				LastActor->UnhighlightActor();
				ThisActor->HighlightActor();
			}
		}
	}
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);

	Subsystem->AddMappingContext(AuraContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}


