#pragma once
#include "Graphics.h"
namespace isgp{
	// does the painting of somthing ones and then 
	class BackgroundArtist
	{
	public:
		BackgroundArtist(void);
		~BackgroundArtist(void);
	private:
		Graphics*	_background;
	};


}