// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor() : TotalDamage(10), DamageTimeInSeconds(1.2f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DamagePerSecond = TotalDamage / DamageTimeInSeconds;
	CharacterName = TEXT("Nickname");
	bAttackable = true;

	UE_LOG(LogTemp, Log, TEXT("Constructor"));
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Log, TEXT("BeginPlay"));
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Log, TEXT("Tick"));
}

void AMyActor::PostInitProperties()
{
	Super::PostInitProperties();

	CalculateDPS();
}

void AMyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	CalculateDPS();
}

void AMyActor::CalculateDPS()
{
	DamagePerSecond = TotalDamage / DamageTimeInSeconds;
}

void AMyActor::InputSpaceKey(bool Pressed)
{
	bPressedKey = Pressed;
}

void AMyActor::MoveUp(float DeltaTime)
{
	if (bPressedKey)
	{
		FVector Location = GetActorLocation();
		Location += FVector::UpVector * 980.0f * DeltaTime;
		SetActorLocation(Location);
	}
}

