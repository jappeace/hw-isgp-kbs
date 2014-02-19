#include "Grid.h"

using namespace std;

namespace isgp {
	void Grid::Traverse(unsigned x, unsigned y, IGridTraveller* traveller) {
		traveller->ReceiveTile(GetTileAt(x, y));
	}

	unsigned Grid::GetTileIndex(unsigned x, unsigned y) const {
		return x + y * _size->GetWidth();
	}

	void Grid::GuardInit(unsigned width, unsigned height) {
		GridToLargeException exception = GridToLargeException(
				"The max limit of tiles for a grid is set to:" +
				StrConverter::IntToString(MAX_TILES) +
				". To change this number define the macro "
				"MAX_TILES before including the header file Grid.h -- "
				"width: " + StrConverter::IntToString(width) +
				", height: " + StrConverter::IntToString(height)
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

	void Grid::Init(unsigned width, unsigned height) {
		_tilesLength = (unsigned) (width * height);
		GuardInit(width, height);
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
						_tiles->at(GetTileIndex(x, y))->SetTop(
							_tiles->at(
								GetTileIndex(x, y + 1)
							)
						);
					}

					if (y != 0) {
						_tiles->at(GetTileIndex(x, y))->SetBottom(
							_tiles->at(
								GetTileIndex(x, y - 1)
							)
						);
					}

					if (x < width - 2) {
						_tiles->at(GetTileIndex(x, y))->SetRight(
							_tiles->at(
								GetTileIndex(x + 1, y)
							)
						);
					}

					if (x != 0) {
						_tiles->at(GetTileIndex(x, y))->SetLeft(
							_tiles->at(
								GetTileIndex(x - 1, y)
							)
						);
					}
				} catch (const out_of_range& oor) {

					// the default exception is just crap
					cout << "binding failed at point:"
							<< " x:" << StrConverter::IntToString(x)
							<< " y:" << StrConverter::IntToString(y)
							<< endl << "message: "
							<< oor.what()
							<< endl;
				}

			}
		}
	}

	Grid::Grid() {
		Init(C_default_w, C_default_h);
	}

	Grid::Grid(unsigned width, unsigned height) {
		Init(width, height);
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
		"x: " + StrConverter::IntToString(x)
				+ "y: " + StrConverter::IntToString(y);
	};

	Tile* Grid::GetTileAt(unsigned x, unsigned y) const {
		unsigned desiredIndex = GetTileIndex(x, y);
		if (desiredIndex < 0) {
			sizeMessage(x, y);
		}
		if (desiredIndex >= _tilesLength) {
			sizeMessage(x, y);
		}
		return _tiles->at(desiredIndex);
	}

	Tile* Grid::GetTileAt(Point& p) const {
		return GetTileAt((int) p.GetX(), (int) p.GetY());
	}

	void Grid::TraverseRow(unsigned y, IGridTraveller* traveller) {
		for (unsigned x = 0; x < _size->GetWidth(); x++) {
			Traverse(x, y, traveller);
		}
	}

	void Grid::TraverseCollumn(unsigned x, IGridTraveller* traveller) {
		for (unsigned y = 0; y < _size->GetHeight(); y++) {
			Traverse(x, y, traveller);
		}
	}

	void Grid::TraverseTiles(IGridTraveller* traveller) {
		for (unsigned x = 0; x < _size->GetWidth(); x++) {
			TraverseCollumn(x, traveller);
		}
	}

	Size* Grid::GetSize() const {
		return _size;
	}
}
