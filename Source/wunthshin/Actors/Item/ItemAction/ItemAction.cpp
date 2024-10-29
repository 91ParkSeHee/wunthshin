// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemAction.h"
#include "Kismet/GameplayStatics.h"

#include "wunthshin/Data/ItemActionTableRow/ItemActionTableRow.h"
#include "wunthshin/Actors/AA_WSCharacter.h"
#include "wunthshin/Components/CharacterStats/CharacterStatsComponent.h"
DEFINE_LOG_CATEGORY(LogItemAction);

UScriptStruct* UItemAction::GetTableType() const
{
    return FItemActionTableRow::StaticStruct();
}

void UItemAction::ApplyAsset(const FDataTableRowHandle& InRowHandle)
{
}
