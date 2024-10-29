// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SG_WSItemActionMetadata.generated.h"


/**
 * 
 */
UCLASS()
class WUNTHSHIN_API USG_WSItemActionMetadata : public USaveGame
{
	GENERATED_BODY()



	UPROPERTY(VisibleAnywhere)
	FName AssetName;

public:
	FName GetAssetName() const { return AssetName; }

	
};
