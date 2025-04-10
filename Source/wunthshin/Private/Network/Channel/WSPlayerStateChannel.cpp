#include "wunthshin/Network/Channel/Public/WSPlayerStateChannel.h"
#include "wunthshin/Controller/PlayerController/wunthshinPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "wunthshin/Components/Stats/StatsComponent.h"
#include "wunthshin/Subsystem/GameInstanceSubsystem/Character/CharacterSubsystem.h"

UWSPlayerStateChannel::UWSPlayerStateChannel()
{
	CurrentPlayerController = Cast<AwunthshinPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}

void UWSPlayerStateChannel::ReceivedBunch(MessageBase& Bunch)
{
	Super::ReceivedBunch(Bunch);
	switch (Bunch.GetType())
	{
	case EMessageType::CharacterStatus:
		{
			CharacterStatusMessage& CharMessage = reinterpret_cast<CharacterStatusMessage&>(Bunch);
			//AA_WSCharacter* CurrentChar = GetWorld()->GetSubsystem<UCharacterSubsystem>()->GetCurrentCharacter();
			//UStatsComponent* StatComp = CurrentChar->GetStatsComponent();

			
			
		}
		
	}
	
}

void UWSPlayerStateChannel::SendBunchInternal(const EMessageType MessageType, MessageBase& Bunch)
{
	Super::SendBunchInternal(MessageType, Bunch);
	
	switch (MessageType)
	{
	case EMessageType::CharacterStatus:
		{
			CharacterStatusMessage& CharMessage = reinterpret_cast<CharacterStatusMessage&>(Bunch);
			FName StatName = CharMessage.StatName.data();
			auto Test = FindFieldChecked<float>(FCharacterStats::StaticStruct(),TEXT("HP"));
			CurrentPlayerController-
		}
		break;
		
		default:
			break;
	}
}
