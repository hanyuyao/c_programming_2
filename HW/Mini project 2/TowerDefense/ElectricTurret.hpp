#ifndef ELECTRICTURRET_HPP
#define ELECTRICTURRET_HPP
#include "Turret.hpp"

class ElectricTurret: public Turret {
public:
	static const int Price;
    ElectricTurret(float x, float y);
	void CreateBullet() override;
};
#endif // ELECTRICTURRET_HPP

