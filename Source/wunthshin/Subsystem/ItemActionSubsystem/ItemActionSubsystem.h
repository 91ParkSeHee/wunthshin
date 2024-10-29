// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "wunthshin/Interfaces/ItemMetadataGetter/ItemMetadataGetter.h"
#include "wunthshin/Subsystem/TableQuerySubsystem.h"
#include "ItemActionSubsystem.generated.h"

class USG_WSItemMetadata;
struct FItemActionTableRow;

/**
 * 
 */
UCLASS()
class WUNTHSHIN_API UItemActionSubsystem : public UTableQueryGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UItemActionSubsystem();
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void DispatchAction(AActor* Sender, AActor* Receiver, FItemActionTableRow ItemAction);
};

UCLASS()
class WUNTHSHIN_API UItemActionEditorSubsystem : public UTableQueryEditorSubsystem
{
	GENERATED_BODY()

public:
	UItemActionEditorSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
};
