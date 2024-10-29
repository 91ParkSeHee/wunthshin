// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EventHandler.generated.h"

DECLARE_MULTICAST_DELEGATE(FEventNoParam)
DECLARE_MULTICAST_DELEGATE_OneParam(FEventOneParam, UFunction)

UCLASS()
class WUNTHSHIN_API UEventHandler : public UGameInstanceSubsystem
{
	GENERATED_BODY()

};
