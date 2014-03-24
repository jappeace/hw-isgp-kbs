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
		PlaySound(TEXT("sound/JUMP.wav"),GetModuleHandle(NULL),SND_FILENAME|SND_ASYNC);
		return ;
		}
	case KILL_ENEMY:
		{
		PlaySound(TEXT("sound/KILL_ENEMY.wav"),GetModuleHandle(NULL),SND_FILENAME|SND_ASYNC);
		return ;
		}

	case END_LOSE:
		{
		PlaySound(TEXT("sound/END_LOSE.wav"),GetModuleHandle(NULL),SND_FILENAME|SND_ASYNC);
		return ;
		}

	case END_WIN:
		{
		PlaySound(TEXT("sound/END_WIN.wav"),GetModuleHandle(NULL),SND_FILENAME|SND_ASYNC);
		return ;
		}
		
	case JUMP_PLATFORM:
		{
		PlaySound(TEXT("sound/JUMP_PLATFORM.wav"),GetModuleHandle(NULL),SND_FILENAME|SND_ASYNC);
		return ;
		}
	}




}

void Sound::Stop()
{
	
}
}