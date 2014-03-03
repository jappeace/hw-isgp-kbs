#pragma once
#include "ILevelFactory.h"
namespace isgp{
	class SimpleLevelFactory :
		public ILevelFactory, public IGridTraveller
	{
	public:
		SimpleLevelFactory(void);
		~SimpleLevelFactory(void);

		Level* CreateLevel() override;
		void SimpleLevelFactory::ReceiveTile(Tile* tile) override;
	};
}
