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
			FString statName = CharMessage.StatName.data();
			int32 statIncreasement = CharMessage.Increasement;
			
			UStatsComponent* statComp = CurrentPlayerController->GetComponentByClass<UStatsComponent>();
			
			
			
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
			
		}
		break;
		
		default:
			break;
	}
}
