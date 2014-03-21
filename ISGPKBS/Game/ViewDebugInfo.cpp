#include "ViewDebugInfo.h"

namespace isgp{

	ViewDebugInfo::ViewDebugInfo(Camera* cam,Level* level)
	{
		_background = new Sprite(
			GridGraphicTranslator().FromTo(
				*level->GetGrid()->GetSize()
			)
		);
		_cam = cam;
		_level = level;
		_quil = new SpriteGraphics(_background);
	}

	void ViewDebugInfo::Paint(Graphics* g) {
		g->DrawSprite(_background,_cam->ToFrom(Vector2D()), _cam->GetPosition() - Vector2D(384,384), Size(AbstractWindow::WindowSize));
	}

	ViewDebugInfo::~ViewDebugInfo(void)
	{
		// don't delete level because we did not create it
		if(_background){
			delete _background;
		}
		if(_quil){
			delete _quil;
		}
	}


	void ViewDebugInfo::ReceiveTile(Tile* tile) 
{
	if(_f1)
	{

		Vector2D position = *tile->GetPosition() * Level::tileSize;
		_quil->DrawLine(position, position + Vector2D(Level::tileSize.GetWidth(), 0));
		_quil->DrawLine(position, position + Vector2D(0, Level::tileSize.GetHeight()));

		
	}
	tile->Paint(_quil);
	}
}