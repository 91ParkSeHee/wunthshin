// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "wunthshin/Interfaces/DataTableFetcher/DataTableFetcher.h"
#include "ItemAction.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogItemAction, Log, All);

/******************************
 * VFX 아님, 발동 시 효과
 * 
 */
USTRUCT()
struct FItemEffectRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	EEffectType EffectType;

	UPROPERTY(EditAnywhere)
	FName EffectName;

	UPROPERTY(EditAnywhere)
	uint64 Amount;
};

USTRUCT()
struct FItemActionRow : public FTableRowBase
{
	GENERATED_BODY()

	// 
	UPROPERTY(EditAnywhere)
	EActivationType ActivationType;

	UPROPERTY(EditAnywhere)
	EItemActionType ItemActionType;

	UPROPERTY(EditAnywhere)
	FName ActionName;

	UPROPERTY(EditAnywhere)
	double Distance;

	// 발동할 효과들, 키값만 저장하는게 나은가?
	UPROPERTY(EditAnywhere)
	TArray<FItemEffectRow> ItemEffects;

	virtual void OnDataTableChanged(const UDataTable* InDataTable, const FName InRowName) override
	{

	}
};

UCLASS()
class WUNTHSHIN_API UItemAction : public UObject, public IDataTableFetcher
{
	GENERATED_BODY()
	

	// IDataTableFetcher을(를) 통해 상속됨
	UScriptStruct* GetTableType() const override;

	void ApplyAsset(const FDataTableRowHandle& InRowHandle) override;

public:
	void ExecuteAction(AActor* InOwner, TArray<AActor*> InTargets);

protected:
	void Execute_Heal();
	void Execute_Equip();
	void Execute_Damage();

// Variable
protected:
	
	FName ItemActionName;
	AActor* Owner;			 // 시전자
	TArray<AActor*> Targets; // 피해자
	EItemActionType ItemActionType;		// 범위
	TArray<FItemEffectRow> ItemEffects;	// 효과
};
