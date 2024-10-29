// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "A_WSItem.h"
#include "wunthshin/Actors/AA_WSCharacter.h"
#include "ConsumableItem.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogItem, Log, All);

UCLASS()
class WUNTHSHIN_API AConsumableItem : public AA_WSItem
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConsumableItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	virtual void UseItem(AActor* InInstigator, TArray<AActor*> InTargets);

public:
	AA_WSCharacter* User;
public:

};
