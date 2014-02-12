#pragma once
#include "IGridTraveller.h"
namespace isgp{

	class Block : IGridTraveller
	{
	public:
		Block(void);
		~Block(void);
		void paint(Graphics*);
	};

}
