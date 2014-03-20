#pragma once
#include "Window.h"
#include "resource.h"
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
namespace isgp{
	enum{JUMP,END_LOSE,KILL_ENEMY,END_WIN,CHANGE_DIREC};
class Sound
{
public :

	
	Sound(void);
	~Sound(void);
	void Play(int ID);
	void Stop();
};}