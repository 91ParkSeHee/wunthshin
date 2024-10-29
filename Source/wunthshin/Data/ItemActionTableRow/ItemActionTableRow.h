// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "wunthshin/Enums.h"
#include "UObject/NoExportTypes.h"
#include "kismet/GameplayStatics.h"
#include "wunthshin/Subsystem/ItemActionSubsystem/ItemActionSubsystem.h"
#include "ItemActionTableRow.generated.h"


/******************************
 * VFX 아님, 발동 시 효과
 * 
 */

USTRUCT()
struct FItemEffectRow : public FTableRowBase
{
	GENERATED_BODY()

	// Key
	UPROPERTY(EditAnywhere)
	FName ActionName;

	UPROPERTY(EditAnywhere)
	EEffectType EffectType;

	UPROPERTY(EditAnywhere)
	double Amount;
};

USTRUCT()
struct FItemActionTableRow : public FTableRowBase
{
	GENERATED_BODY()

	// Key
	UPROPERTY(EditAnywhere)
	FName ActionName;

	// 
	UPROPERTY(EditAnywhere)
	EActivationType ActivationType;

	UPROPERTY(EditAnywhere)
	float ActivationTime;

	// 범위
	UPROPERTY(EditAnywhere)
	EItemActionType ActionType;

	// 효과
	UPROPERTY(EditAnywhere)
	TArray<FDataTableRowHandle> Effects;
};
