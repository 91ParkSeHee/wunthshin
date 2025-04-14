#include "Network/Channel/WSPlayerStateChannel.h"
#include "Controller/wunthshinPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Component/StatsComponent.h"
#include "Subsystem/CharacterSubsystem.h"

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
			statComp->SetCurrentStats(statName, statIncreasement);
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
			CharMessage.StatName = PreparedMessage.StatName;
			CharMessage.Increasement = PreparedMessage.Increasement;
		}
		break;
		
		default:
			break;
	}
}
