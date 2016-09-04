//
// Created by cvalenza on 8/29/16.
//

#include "Joystick.h"
#include "res.h"

Joystick::Joystick() : pressed(false), dir(0, 0)
{
	// create the joystick sprite and make it translucent
	setResAnim(res::ui.getResAnim("joystick"));
	setAlpha(128);

	// set up to handle touch events
	addEventListener(TouchEvent::TOUCH_DOWN, CLOSURE(this, &Joystick::onEvent));
	addEventListener(TouchEvent::TOUCH_UP, CLOSURE(this, &Joystick::onEvent));
	addEventListener(TouchEvent::MOVE, CLOSURE(this, &Joystick::onEvent));

	// set up the button press sprite
	finger = new Sprite;
	finger->setResAnim(res::ui.getResAnim("finger"));
	finger->attachTo(this);
	finger->setVisible("false");
	finger->setAnchor(Vector2(0.5f, 0.5f));
	finger->setTouchEnabled(false);
}

void Joystick::onEvent(Event* ev)
{
	TouchEvent* te = safeCast<TouchEvent*>(ev);

	// case where player presses the joystick
	if (te->type == TouchEvent::TOUCH_DOWN) {
		finger->setVisible(true);
		setColor(Color::Red);
		pressed = true;
	}

	// case where player lifts finger off joystick
	if (te->type == TouchEvent::TOUCH_UP) {
		finger->setVisible(false);
		setColor(Color::White);
		pressed = false;
	}

	// to be filled in later
	if (te->type == TouchEvent::MOVE) {

	}

	Vector2 center = getSize() / 2;
	dir = te->localPosition - center;

	if (dir.length() > 100) {
		dir.normalizeTo(100);
	}

	finger->setPosition(center + dir);

	// reset the direction if the joystick is not pressed
	if (!pressed) {
		dir = Vector2(0, 0);
	}
}

bool Joystick::getDirection(Vector2& d) const
{
	d = dir;
	return pressed;
}