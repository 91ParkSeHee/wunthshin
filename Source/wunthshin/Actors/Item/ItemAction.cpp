// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemAction.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY(LogItemAction);

//UScriptStruct* UItemAction::GetTableType() const
//{
//	return FItemActionRow::StaticStruct();
//}
//
//void UItemAction::ApplyAsset(const FDataTableRowHandle& InRowHandle)
//{
//	if (InRowHandle.IsNull()) return;
//
//	auto Data = InRowHandle.GetRow<FItemActionRow>(TEXT("Action"));
//
//	
//
//}

void UItemAction::ExecuteAction(AActor* InOwner, TArray<AActor*> InTargets)
{
	// 시전 -> 타겟들에게 Effect전달 -> 전달 받은 Effect를 타겟이 알맞게 계산?
	// unreal 기본제공 takedamage 이용하여 데미지, 힐가능(값을 음수로주면 됨)

	UE_LOG(LogItemAction, Log, TEXT("ExecuteAction"));

	for (auto& Effect : ItemEffects)
	{
		switch (Effect.EffectType)
		{
		case EEffectType::Heal: Execute_Heal();
			break;
		case EEffectType::Damage: Execute_Damage();
			break;
		default:
			break;
		}
	}
}

void UItemAction::Execute_Heal()
{

}

void UItemAction::Execute_Equip()
{
}

void UItemAction::Execute_Damage()
{
	

	float TestAmount = 1;
	UDamageType TestType;

	for (auto& Target : Targets)
	{
		UGameplayStatics::ApplyDamage(Target, TestAmount, Owner->GetInstigatorController<APlayerController>(), Owner, NULL);
	}
}
