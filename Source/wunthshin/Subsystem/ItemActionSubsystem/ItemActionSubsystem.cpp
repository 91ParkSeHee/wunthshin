// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemActionSubsystem.h"

//#include "wunthshin/Actors/Item/ItemAction/ItemAction.h"
#include "wunthshin/Data/ItemMetadata/SG_WSItemMetadata.h"
#include "wunthshin/Data/ItemTableRow/ItemTableRow.h"
#include "wunthshin/Subsystem/Utility.h"

UItemActionSubsystem::UItemActionSubsystem()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> Table(TEXT("/Script/Engine.DataTable'/Game/DataTable/DT_ItemActionTable.DT_ItemActionTable'"));
	check(Table.Object);
	DataTable = Table.Object;
}

void UItemActionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	//FItemSubsystemUtility::UpdateTable<FItemTableRow, USG_WSItemMetadata>(DataTable, Metadata);
}

void UItemActionSubsystem::DispatchAction(AActor* Sender, AActor* Receiver, FItemActionTableRow ItemAction)
{
			
}

UItemActionEditorSubsystem::UItemActionEditorSubsystem()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> Table(TEXT("/Script/Engine.DataTable'/Game/DataTable/DT_ItemTable.DT_ItemTable'"));
	check(Table.Object);
	DataTable = Table.Object;
}

void UItemActionEditorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	//FItemSubsystemUtility::UpdateTable<FItemTableRow, USG_WSItemMetadata>(DataTable, Metadata);
}
