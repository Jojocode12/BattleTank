// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "../Public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("Couldn't find player tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Found player tank: %s"), *PlayerTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {
		// TODO Move towards the player
		// Aim towards player
		FVector PlayerLocation = GetPlayerTank()->GetActorLocation();
		GetAIControlledTank()->AimAt(PlayerLocation);
		// Fire towards player
	}
}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}