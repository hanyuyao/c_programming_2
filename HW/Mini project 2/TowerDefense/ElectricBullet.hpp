#ifndef ELECTRICBULLET_HPP
#define ELECTRICBULLET_HPP
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
struct Point;
}  // namespace Engine

class ElectricBullet : public Bullet {
public:
	explicit ElectricBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
	void OnExplode(Enemy* enemy) override;
};
#endif // ELECTRICBULLET_HPP

