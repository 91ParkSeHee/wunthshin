// Fill out your copyright notice in the Description page of Project Settings.


#include "wunthshin/Data/Items/ItemMetadata/SG_WSItemMetadata.h"
#include "wunthshin/Data/Effects/EffectTableRow/EffectTableRow.h"
#include "wunthshin/Subsystem/GameInstanceSubsystem/Effect/EffectSubsystem.h"

const UO_WSBaseEffect* USG_WSItemMetadata::GetItemEffect(const UWorld* InWorld) const
{
    return InWorld->GetGameInstance()->GetSubsystem<UEffectSubsystem>()->GetEffector(ItemEffect);
}

const FEffectParameter& USG_WSItemMetadata::GetItemParameter() const
{
    return ItemParameter;
}
