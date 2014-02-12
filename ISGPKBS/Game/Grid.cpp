#include "Grid.h"
using namespace std;
namespace isgp {

	void Grid::traverse(unsigned x, unsigned y, IGridTraveller* traveller) {
		traveller->receiveTile(getTileAt(x, y));
	}

	unsigned Grid::getTileIndex(unsigned x, unsigned y) const {
		return x + y * _size->GetWidth();
	}

	void Grid::gaurdInit(unsigned width, unsigned height) {
		GridToLargeException exception = GridToLargeException(
				"The max limit of tiles for a grid is set to:" +
				StrConverter::intToString(MAX_TILES) +
				". To change this number define the macro "
				"MAX_TILES before including the header file Grid.h -- "
				"width: " + StrConverter::intToString(width) +
				", height: " + StrConverter::intToString(height)
				, width, height);
		if (width > MAX_TILES) {
			throw exception;
		}
		if (height > MAX_TILES) {
			throw exception;
		}
		if (_tilesLength > MAX_TILES) {
			throw exception;
		}
	}

	void Grid::init(unsigned width, unsigned height) {
		_tilesLength = (unsigned) (width * height);
		gaurdInit(width, height);
		_size = new Size(width, height);
		_tiles = new vector<Tile*>();
		for (unsigned y = 0; y < height; y++) {
			for (unsigned x = 0; x < width; x++) {
				_tiles->push_back(new Tile(x, y));
			}
		}
		// bind tiles to each other
		for (unsigned y = 0; y < height; y++) {
			for (unsigned x = 0; x < width; x++) {

				try {
					if (y < height - 2) {
						_tiles->at(getTileIndex(x, y))->SetTop(
								_tiles->at(
								getTileIndex(x, y + 1)
								)
								);
					}

					if (y != 0) {
						_tiles->at(getTileIndex(x, y))->SetBottom(
								_tiles->at(
								getTileIndex(x, y - 1)
								)
								);
					}

					if (x < width - 2) {
						_tiles->at(getTileIndex(x, y))->SetRight(
								_tiles->at(
								getTileIndex(x + 1, y)
								)
								);
					}

					if (x != 0) {
						_tiles->at(getTileIndex(x, y))->SetLeft(
								_tiles->at(
								getTileIndex(x - 1, y)
								)
								);
					}
				} catch (const out_of_range& oor) {

					// the default exception is just crap
					cout << "binding failed at point:"
							<< " x:" << StrConverter::intToString(x)
							<< " y:" << StrConverter::intToString(y)
							<< endl << "message: "
							<< oor.what()
							<< endl;
				}

			}
		}
	}

	Grid::Grid() {
		init(C_default_w, C_default_h);
	}

	Grid::Grid(unsigned width, unsigned height) {
		init(width, height);
	}

	Grid::~Grid() {
		if(_tiles){
			delete _tiles;
		}
		if(_size){
			delete _size;
		}
		_tiles = NULL;
		_size = NULL;


	}

	void sizeMessage(unsigned x, unsigned y) {

		// I used to just log this, but usualy when this happens the aplication crashed anyways,
		// so this will do fine
		throw "Unable to find tile at "
		"x: " + StrConverter::intToString(x)
				+ "y: " + StrConverter::intToString(y);
	};

	Tile* Grid::getTileAt(unsigned x, unsigned y) const {
		unsigned desiredIndex = getTileIndex(x, y);
		if (desiredIndex < 0) {
			sizeMessage(x, y);
		}
		if (desiredIndex >= _tilesLength) {
			sizeMessage(x, y);
		}
		return _tiles->at(desiredIndex);
	}

	Tile* Grid::getTileAt(Point& p) const {
		return getTileAt((int) p.GetX(), (int) p.GetY());
	}

	void Grid::traverseRow(unsigned y, IGridTraveller* traveller) {
		for (unsigned x = 0; x < _size->GetWidth(); x++) {
			traverse(x, y, traveller);
		}
	}

	void Grid::traverseCollumn(unsigned x, IGridTraveller* traveller) {
		for (unsigned y = 0; y < _size->GetHeight(); y++) {
			traverse(x, y, traveller);
		}
	}

	void Grid::traverseTiles(IGridTraveller* traveller) {
		for (unsigned x = 0; x < _size->GetWidth(); x++) {
			traverseCollumn(x, traveller);
		}
	}

	Size* Grid::getSize() const {
		return _size;
	}
}
