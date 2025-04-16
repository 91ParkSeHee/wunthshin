#include "Network/Channel/WSPlayerStateChannel.h"
#include "Controller/wunthshinPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Component/StatsComponent.h"
#include "Network/Channel/WSLoginChannel.h"
#include "Network/Subsystem/WSServerSubsystem.h"
#include "Subsystem/CharacterSubsystem.h"
#include "Subsystem/WorldStatusSubsystem.h"

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
			UWSServerSubsystem* Subsystem = GetSubsystem();
			auto sessionID = GetSubsystem()->GetLoginChannel()->GetSessionID();
			auto statComp = CurrentPlayerController->Owner->GetComponentByClass<UStatsComponent>();
			CharMessage.sessionID = sessionID.uuid;
			CharMessage.character_id = 0;
			CharMessage.changed_Hp = statComp->GetHP();
			CharMessage.changed_Exp = statComp->GetStats().CurrentExp;
		}
		break;
		
		default:
			break;
	}
}
