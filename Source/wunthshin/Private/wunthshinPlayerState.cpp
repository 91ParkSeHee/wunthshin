// Fill out your copyright notice in the Description page of Project Settings.


#include "wunthshinPlayerState.h"

#include "Actor/Pawn/AA_WSCharacter.h"
#include "Component/StatsComponent.h"
#include "Subsystem/CharacterSubsystem.h"
#include "Subsystem/WorldStatusSubsystem.h"
#include "Network/Subsystem/WSServerSubsystem.h"

void AwunthshinPlayerState::BeginPlay()
{
	Super::BeginPlay();
	
	if (UWorldStatusSubsystem* WorldStatusSubsystem = GetWorld()->GetSubsystem<UWorldStatusSubsystem>();
		WorldStatusSubsystem && Cast<AA_WSCharacter>(GetPawn()))
	{
		OnPlayerAlivenessChanged.AddUniqueDynamic(WorldStatusSubsystem, &UWorldStatusSubsystem::PlayDeathLevelSequence);

		UWSServerSubsystem* ServerSubsystem = GetGameInstance()->GetSubsystem<UWSServerSubsystem>();
		OnCharacterDied.AddUniqueDynamic(ServerSubsystem, &UWSServerSubsystem::TryChangeCharacterStatus);
	}
}

void AwunthshinPlayerState::SetAlive(const bool InbAlive)
{
	const bool TempBool = bAlive;
	bAlive = InbAlive;
	
	if (TempBool != InbAlive)
	{
		OnPlayerAlivenessChanged.Broadcast(bAlive);
	}

	if (APawn* ThisPawn = GetPawn())
	{
		ThisPawn->SetActorEnableCollision(bAlive);
	}
}

void AwunthshinPlayerState::CheckCharacterDeath(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
                                                AController* InstigatedBy, AActor* DamageCauser)
{
	if (const ICommonPawn* CommonPawn = Cast<ICommonPawn>(DamagedActor))
	{
		if (CommonPawn->GetStatsComponent()->GetHP() == 0)
		{
			if (Cast<AA_WSCharacter>(CommonPawn))
			{
				UCharacterSubsystem* CharacterSubsystem = GetGameInstance()->GetSubsystem<UCharacterSubsystem>();
				if (const int32 Index = CharacterSubsystem->GetAvailableCharacter();
					Index != -1)
				{
					CharacterSubsystem->SpawnAsCharacter(Index);
					SetAlive(true);
					return;
				}
			}

			// 캐릭터(몬스터)가 죽었을때 서버에 메시지를 보내고 UI를 갱신함
			OnCharacterDied.Broadcast(TEXT("Exp"),InstigatedBy->GetComponentByClass<UStatsComponent>()->GetStats().CurrentExp);
			SetAlive(false);
		}
	}
}
