// Fill out your copyright notice in the Description page of Project Settings.


#include "ConsumableItem.h"
#include "wunthshin/Components/CharacterStats/CharacterStatsComponent.h"


DEFINE_LOG_CATEGORY(LogItem);


// Sets default values
AConsumableItem::AConsumableItem()
{
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AConsumableItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConsumableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AConsumableItem::UseItem(AActor* InInstigator, TArray<AActor*> InTargets)
{
	Super::UseItem(InInstigator, InTargets);

	UCharacterStatsComponent* Comp = User->GetComponentByClass<UCharacterStatsComponent>();
	Comp->CurrentStats.CurrentHP += 10.f;

	
}

