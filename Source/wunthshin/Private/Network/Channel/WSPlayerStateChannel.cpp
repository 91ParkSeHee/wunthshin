#include "wunthshin/Network/Channel/Public/WSPlayerStateChannel.h"

void UWSPlayerStateChannel::ReceivedBunch(MessageBase& Bunch)
{
	Super::ReceivedBunch(Bunch);

	
}

void UWSPlayerStateChannel::SendBunchInternal(const EMessageType MessageType, MessageBase& Bunch)
{
	Super::SendBunchInternal(MessageType, Bunch);
	
	switch (MessageType)
	{
	case EMessageType::CharacterStatus:
		{
			
		}
		break;
		
		default:
			break;
	}
}
