//
// Created by cvalenza on 8/30/16.
//

#include "Player.h"
#include "Game.h"
#include "res.h"
#include "Joystick.h"
#include "math.h"

void Player::_init()
{
	view->setPosition(game->getSize() / 2);
	character = new Sprite;
	character->setResAnim(res::ui.getResAnim("player"));
	character->attachTo(view);
	character->setAnchor(0.5f, 0.5f);

	weapon = new Sprite;
	weapon->setResAnim(res::ui.getResAnim("sword"));
	weapon->attachTo(character);
	weapon->setVisible(false);
}

void Player::_update(const UpdateState& us)
{
	weapon->setVisible(false);

	Vector2 dir;

	if (game->move->getDirection(dir)) {
		Vector2 pos = view->getPosition();
		pos = pos + dir * (us.dt / 1000.0f) * 5;
		view->setPosition(pos);

		float angle = atan2f(dir.y, dir.x);

		if (angle >= -3 && angle <= 1.5) {
			angle += M_PI / 2;
		} else {
			angle -= 1.5f * M_PI;
		}

		view->setRotation(angle);
	}

	if (game->look->getDirection(dir)) {
		float angle = atan2f(dir.y, dir.x);

		if (angle >= -3 && angle <= 1.5) {
			angle += M_PI / 2;
		} else {
			angle -= 1.5f * M_PI;
		}

		view->setRotation(angle);
	}
}