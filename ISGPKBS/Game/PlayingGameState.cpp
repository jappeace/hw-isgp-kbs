#include "PlayingGameState.h"
#include "SimpleLevelFactory.h"
#include "Camera.h"

namespace isgp {
	PlayingGameState::PlayingGameState(Graphics* graphics) {
		_graphics = graphics;
		SimpleLevelFactory factory;
		_level = factory.CreateLevel();
		Camera* cam = new Camera(_level->_player, _level->GetGrid());
		_graphics->SetCam(cam);
	}

	PlayingGameState::~PlayingGameState() {
		delete _camera;
	}

	void PlayingGameState::Paint(Graphics* g) {
		_level->Paint(g);
	}

	void PlayingGameState::Update(double elapsed) {
	}
}