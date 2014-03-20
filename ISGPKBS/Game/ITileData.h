#include "IPaintable.h"
#include "IGridTraveller.h"
#pragma once

namespace isgp{
	// tile data needs to be able to paint and receive on which tile it is located
	// The painting is used by a Tile to paint its data.
	// The receive tile is used to tell the data who is rendering it
	class ITileData : public IPaintable, public IGridTraveller {
	public:
		virtual ~ITileData() {}
		bool IsSolid;
	};
}