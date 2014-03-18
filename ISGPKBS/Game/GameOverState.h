#include "IGameState.h"
#include "IMenu.h"

namespace isgp {

	// Game state that is used after the player dies.
	class GameOverState : public IGameState {
	public:
		void Paint(Graphics* g) override;
		void Update(double elapsed) override;
	private:
		IMenu* _menu;
	};
}