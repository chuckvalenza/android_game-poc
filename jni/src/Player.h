//
// Created by cvalenza on 8/30/16.
//

#ifndef OXYGINE_HW_PLAYER_H
#define OXYGINE_HW_PLAYER_H

#include "Unit.h"
#include <chrono>

DECLARE_SMART(Player, spPlayer);

class Player : public Unit {
	private:
		std::chrono::milliseconds atk_anim_timer;
		void move(timeMS dt);
		void attack();
		void swingAnimation(int time_ms);
		void changeAnim(std::string action, int ms);
	protected:
		void _init();
		void _update(const UpdateState& us);

		spSprite character;
		spSprite weapon;
	public:
};

#endif //OXYGINE_HW_PLAYER_H
