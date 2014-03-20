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
		PlaySound(TEXT("JUMP.wav"),GetModuleHandle(NULL),SND_FILENAME|SND_ASYNC);
		return ;
		}
	case KILL_ENEMY:
		{
		PlaySound(TEXT("KILL_ENEMY.wav"),GetModuleHandle(NULL),SND_FILENAME|SND_ASYNC);
		return ;
		}

	case END_LOSE:
		{
		PlaySound(TEXT("END_LOSE.wav"),GetModuleHandle(NULL),SND_FILENAME|SND_ASYNC);
		return ;
		}

	case END_WIN:
		{
		PlaySound(TEXT("END_WIN.wav"),GetModuleHandle(NULL),SND_FILENAME|SND_ASYNC);
		return ;
		}
		
	case CHANGE_DIREC:
		{
		PlaySound(TEXT("CHANGE_DIREC.wav"),GetModuleHandle(NULL),SND_FILENAME|SND_ASYNC);
		return ;
		}
	}




}

void Sound::Stop()
{
	
}
}