#ifndef Skeleton_H
#define Skeleton_H

#include "Win.h"
#include "Graphics.h"

using namespace isgp;

class CSkeleton : public CWin
{
private:
	Graphics *_graphics;

public:
	CSkeleton();
	~CSkeleton();

	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
};

#endif
