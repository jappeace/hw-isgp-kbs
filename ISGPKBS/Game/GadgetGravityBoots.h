#pragma once

#include "Entity.h"
#include "Gadget.h"
namespace isgp {

	class GadgetGravityBoots : public Gadget
	{
	public:
		GadgetGravityBoots(Vector2D position, Player* player);
		~GadgetGravityBoots(void);

		void Paint(Graphics* g);
		void Update(const double);
		virtual void OnCollide() override;
	private:
		IBehaviour* _gravityBootsBehaviour;
		int _activationTime;
		double _pickedUpTime;
		bool _pickedUp;
		bool _finished;
		int _spawnPos;
		double _bounceHeight;
		double _vel;
		bool _up;
	};
}
