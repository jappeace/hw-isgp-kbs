/* 
 * File:   Grid.h
 * Author: jappie
 *
 * Created on January 31, 2014, 11:20 AM
 */

#ifndef GRID_H
#define	GRID_H

#ifndef MAX_TILES
	// unit test started to fail when the number got to high on construction.
	#define MAX_TILES 5000
#endif

#include <vector>
#include "Tile.h"
#include "Size.h"
#include "Point.h"
#include "IGridTraveller.h"
#include <iostream>
#include "StrConverter.h"
#include <stdexcept>
#include "Exceptions.h"
using namespace std;
namespace isgp {
	/**
	 * A class for easaly handaling a grid as a one dimensional array, with O(1) accessing speed for positions,
	 * and O(N), for accesing any set of elements.
	 * it also handy for traversel of indivdual rows/columns or all tiles trough passing an object
	 * which inherits from the interface like IGridTraveller
	 */
	class Grid{
	public:

		/** default constructor will use the C_default_size for initiliztion */
		Grid();
		/** initialize the grid to the specified size*/
		Grid(unsigned width, unsigned height);
		/**
		 * destructor
		 */
		~Grid();

		/**
		 * retrieve tile at postiotion
		 */
		Tile* getTileAt(unsigned x, unsigned y) const;
		/**
		 * shorthand for getTileAt(int x, int y)
		 */
		Tile* getTileAt(Point& p) const;

		/**
		 * The given function pointer will receive all the tiles and coordinates in the specified row
		 */
		void traverseRow(unsigned y, IGridTraveller* travellar);
		/**
		 * The given function pointer will receive all the tiles and coordinates in the specified collumn
		 */
		void traverseCollumn(unsigned x, IGridTraveller* travellar);
		/**
		 * The given function pointer will receive all the tiles in the grid and the cordiantes of them.
		 */
		void traverseTiles(IGridTraveller* travellar);
        Size* getSize() const;
	private:
		vector<Tile*>* _tiles;
		unsigned _tilesLength;
		static const unsigned C_default_h = 20;
		static const unsigned C_default_w = 20;
		/**
		 * size of the grid
		 */
		Size* _size;
		/**
		 * final step in the traversal proces, here the cordinates are known and only the
		 * functionpointer has to be called
		 * */
		void traverse(unsigned x, unsigned y, IGridTraveller* travellar);
		
		/**
		 * A gaurd for the init function so It won't take etherinity to init the grid but
		 * just throw an GridToLarge exception
         * @param width
         * @param height
         */
		void gaurdInit(unsigned width, unsigned height);
		/**
		 * comman code for both contructors
		 */
		void init(unsigned width, unsigned height);
		/**
		 * this function prevents the same calculation showing up in several places
         * @param x
         * @param y
         * @return the index
         */
		unsigned getTileIndex(unsigned x, unsigned y) const;
	};
}


#endif	/* GRID_H */

