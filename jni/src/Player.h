//
// Created by cvalenza on 8/30/16.
//

#ifndef OXYGINE_HW_PLAYER_H
#define OXYGINE_HW_PLAYER_H

#include "Unit.h"

DECLARE_SMART(Player, spPlayer);

class Player : public Unit {
	private:
	public:
	protected:
		void _init();
		void _update(const UpdateState& us);

		spSprite character;
		spSprite weapon;
};

#endif //OXYGINE_HW_PLAYER_H
