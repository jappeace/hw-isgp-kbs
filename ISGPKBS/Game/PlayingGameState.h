#pragma once

#include "IGameState.h"
#include "Level.h"

namespace isgp {
	class PlayingGameState : public IGameState {
	public:
		PlayingGameState(Graphics* graphics);
		~PlayingGameState();
		void Paint(Graphics* g) override;
		void Update(double elapsed) override;
	private:
		Level* _level;
		Graphics* _graphics;
		Camera* _camera;
	};
}
