#pragma once
#include "IGridTraveller.h"
namespace isgp{

	class WorldBlock : IGridTraveller
	{
	public:
		Block(void);
		~Block(void);
		void paint(Graphics*);
	private:
	};

}
