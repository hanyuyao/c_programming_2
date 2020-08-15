#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "ElectricBullet.hpp"
#include "Group.hpp"
#include "ElectricTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

const int ElectricTurret::Price = 350;
ElectricTurret::ElectricTurret(float x, float y) :
	Turret("play/tower-base.png", "play/turret-7.png", x, y, 200, Price, 0.2) {
	// Move center downward, since we the turret head is slightly biased upward.
	//Anchor.y += 8.0f / GetBitmapHeight();
}
void ElectricTurret::CreateBullet() {
	Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
	float rotation = atan2(diff.y, diff.x);
	Engine::Point normalized = diff.Normalize();
	Engine::Point normal = Engine::Point(-normalized.y, normalized.x);
	// Change bullet position to the front of the gun barrel.
	getPlayScene()->BulletGroup->AddNewObject(new ElectricBullet(Position + normalized * 36 + normal * 6, diff, rotation, this));
	getPlayScene()->BulletGroup->AddNewObject(new ElectricBullet(Position + normalized * 36 , diff, rotation, this));
	getPlayScene()->BulletGroup->AddNewObject(new ElectricBullet(Position + normalized * 36 - normal * 6, diff, rotation, this));
	AudioHelper::PlayAudio("electric.wav");
}

