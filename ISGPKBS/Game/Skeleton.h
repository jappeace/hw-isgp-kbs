#ifndef Skeleton_H
#define Skeleton_H

#include "Win.h"

class Skeleton : public Win
{
public:
	Skeleton();
	~Skeleton();
	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
};

#endif
