// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "wunthshin/Interfaces/DataTableFetcher/DataTableFetcher.h"
#include "ItemAction.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogItemAction, Log, All);

struct FItemEffectRow;

UCLASS()
class UItemEffect : public UObject
{
	GENERATED_BODY()

};

UCLASS()
class WUNTHSHIN_API UItemAction : public UObject, public IDataTableFetcher
{
	GENERATED_BODY()

public:
	UItemAction() {};

public:
	virtual void ExecuteAction(AActor* InInstigator, TArray<AActor*> InTargets)
	{
		if (InTargets.IsEmpty()) Targets[0] = InInstigator;

		for (auto& Target : InTargets)
		{
			for (auto& Effect : ItemEffects)
			{
				
			}
		}
	};

// Variable
protected:
	FName ItemActionName;
	AActor* Instigator;					// 시전자
	TArray<AActor*> Targets;			// 피해자
	EItemActionType ItemActionType;		// 범위
	TArray<FItemEffectRow> ItemEffects;
	// IDataTableFetcher을(를) 통해 상속됨
	UScriptStruct* GetTableType() const override;
	void ApplyAsset(const FDataTableRowHandle& InRowHandle) override;
	// 효과
};
