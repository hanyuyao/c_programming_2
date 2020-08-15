#include <allegro5/base.h>
#include <random>
#include <string>

#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "ElectricBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

class Turret;

ElectricBullet::ElectricBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent) :
	Bullet("play/bullet-7.png", 300, 1, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
}
void ElectricBullet::OnExplode(Enemy* enemy) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(2, 10);
	getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-4.png", dist(rng), enemy->Position.x, enemy->Position.y));
}

