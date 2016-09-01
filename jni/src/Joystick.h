//
// Created by cvalenza on 8/29/16.
//

#ifndef OXYGINE_HW_JOYSTICK_H
#define OXYGINE_HW_JOYSTICK_H

#include "oxygine-framework.h"

using namespace oxygine;

DECLARE_SMART(Joystick, spController);

class Joystick : public Sprite {
	private:
		spSprite finger;
		Vector2 dir;
		bool pressed;

		void onEvent(Event *ev);
	public:
		Joystick();
		bool getDirection(Vector2& dir) const;
};

#endif //OXYGINE_HW_JOYSTICK_H