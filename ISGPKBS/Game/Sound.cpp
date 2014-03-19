#include "Sound.h"
namespace isgp{
Sound::Sound(void)
{
}

Sound::~Sound(void)
{
}

void Sound::Play(int ID)
{

	switch(ID)
	{
	case JUMP:
		{
		PlaySound(TEXT("1.wav"),GetModuleHandle(NULL),SND_FILENAME|SND_ASYNC);
		return ;
		}
	case COLLISION:
		{
		PlaySound(TEXT("5.wav"),GetModuleHandle(NULL),SND_FILENAME|SND_ASYNC);
		return ;
		}

	case END_LOSE:
		{
		PlaySound(TEXT("2.wav"),GetModuleHandle(NULL),SND_FILENAME|SND_ASYNC);
		return ;
		}

	case END_WIN:
		{
		PlaySound(TEXT("4.wav"),GetModuleHandle(NULL),SND_FILENAME|SND_ASYNC);
		return ;
		}
	}




}

void Sound::Stop()
{
	
}
}