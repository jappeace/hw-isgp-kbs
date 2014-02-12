#ifndef Skeleton_H
#define Skeleton_H

#include "Win.h"
#include "Graphics.h"

using namespace isgp;

class Skeleton : public Win
{
private:
	Graphics *_graphics;

public:
	Skeleton();
	~Skeleton();
	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
};

#endif
