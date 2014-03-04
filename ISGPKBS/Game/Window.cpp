#include "Window.h"
#include "SimpleLevelFactory.h"
#include "GridGraphicTranslator.h"
namespace isgp {
// amount of tiles
const Size g_tiles = Size(50,50);

// Constructors / Destructors      //
Window::Window() {
	ILevelFactory* factory = new SimpleLevelFactory();
	_level = factory->CreateLevel();
	delete factory;
	Grid* g = new Grid(g_tiles.GetWidth(),g_tiles.GetHeight());// level handles destruction of grid
	_level = new Level(g);
	Point position = Point(5,5);
	g->GetTileAt(position)->SetData(new WorldBlock("C:\\tiles\\smile.bmp"));
	for(unsigned i = 20; i < 50; i++) {
		Point position = Point(i, 22);
		g->GetTileAt(position)->SetData(new WorldBlock("C:\\tiles\\smile.bmp"));
		Point position2 = Point(i, 23);
		g->GetTileAt(position2)->SetData(new WorldBlock("C:\\tiles\\smile.bmp"));
		Point position3 = Point(i, 24);
		g->GetTileAt(position2)->SetData(new WorldBlock("C:\\tiles\\smile.bmp"));
	}
}

Window::~Window()
{
}

/////////////////////////////////////
// Member functions                  //
/////////////////////////////////////

void Window::AfterCreate() {
	_cam = new Camera(_level->_player);
	_graphics->SetCam(_cam);
}

INT_PTR CALLBACK dialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	return NULL;
}
void Window::OnPaint(Graphics* g){
	_level->Paint(g);

#ifdef _DEBUG
	GridGraphicTranslator graphicTranslator = GridGraphicTranslator();
	Point topTilePoint = graphicTranslator.ToFrom(_level->_player->_position);
	
	/*vector<Tile*> maaktNietUit;
	maaktNietUit.push_back(_level->_grid->GetTileAt(topTilePoint)->GetTop());
	maaktNietUit.push_back(_level->_grid->GetTileAt(topTilePoint));
	vector<Tile*> includedTiles = _level->_grid->GetSurroundingTiles(maaktNietUit);



	g->SetColor(RGB(255, 0, 0));
	for(unsigned int i = 0; i < includedTiles.size(); i++) {
		Tile* t = includedTiles.at(i);
		Point* p = &graphicTranslator.FromTo(*t->GetPosition());
		g->DrawRect((int)p->GetX(), (int)p->GetY(), (int)p->GetX() + 16, (int)p->GetY() + 16);
		includedTiles.at(i)->Paint(g);
	}

	g->SetColor(RGB(0, 0, 0));*/
#endif
}
void Window::GameLoop(double elapsed) { //elapsed time, in MS
	//update all the game objects now
	_level->_player->Update(elapsed);
	_cam->Update();

	AbstractWindow::GameLoop(elapsed);


short Window::CheckCollision(Player *player, Grid *grid) {
	GridGraphicTranslator graphicTranslator = GridGraphicTranslator();
	Point topTilePoint = graphicTranslator.FromTo(player->_position);

	vector<Tile*> includedTiles = _level->_grid->GetTileAt(topTilePoint)->GetSurroundingTiles();

	return -1;
}

void Window::OnKeyDown(int which) {
	if (which == 37) {
		_level->_player->_leftKey = true;
	}
	if (which == 39) {
		_level->_player->_rightKey = true;
	}
	if (which == 38) {
		_level->_player->_upKey = true;
	}
	if (which == 32) {
		_level->_player->_spaceKey = true;
	}
}

void Window::OnKeyUp(int which) {
	if (which == 37) {
		_level->_player->_leftKey = false;
	}
	if (which == 39) {
		_level->_player->_rightKey = false;
	}
	if (which == 38) {
		_level->_player->_upKey = false;
	}
	if (which == 32) {
		_level->_player->_spaceKey = false;
	}
}

void Window::OnCommand(int from, int command) {
	switch(from){
	case ID_FILE_NEWGAME:
		this->repaint();
		break;
	case ID_HELP_ABOUT:
		MessageBox(
			_hWnd,
			// message:
			"Copyright Team Awesome, Program version: Awesome",
			// title:
			"Licensed under GPL v3",
			MB_OK | MB_ICONEXCLAMATION
		);
		break;
	case ID_FILE_EXIT:
		PostQuitMessage(0);
		break;
	}
}

LRESULT Window::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	return AbstractWindow::MsgProc(hWnd, uMsg, wParam, lParam);
}

}
