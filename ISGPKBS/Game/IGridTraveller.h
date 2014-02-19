#ifndef IGRIDTRAVELER_H
#define	IGRIDTRAVELER_H

#include "Tile.h"
#include "Point.h"
namespace isgp{
// 'pure virtual' or an interface, classes that extend this class will be able to traverse the
// grid.
// a class implementing this interface can be given to the traverse// methods of grid and receive
// the tiles in the row column or grid.
	class IGridTraveller{

	public:
		virtual void ReceiveTile(Tile* tile) = 0;

	};
}
#endif	/* IGRIDTRAVELER_H */

