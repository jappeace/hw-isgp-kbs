#pragma once
#include "Entity.h"
#include "Player.h"
namespace isgp {
class Gadget : public Entity
{
protected:
	Player* _player;
public:
	void Update(const double) override;
	virtual void OnCollide() = 0;
};
}
