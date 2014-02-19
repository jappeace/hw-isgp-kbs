/* 
 * File:   IGridTraveler.h
 * Author: jappie
 *
 * Created on January 31, 2014, 8:48 PM
 */

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
		virtual void receiveTile(Tile* tile) = 0;

	};
}
#endif	/* IGRIDTRAVELER_H */

