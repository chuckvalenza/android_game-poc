//
// Created by cvalenza on 9/18/16.
//

#include "EquipmentButton.h"
#include "res.h"

void EquipmentButton::_init()
{
	view->setPosition(game->getSize() / 2);

	button = new Sprite;
	button->setResAnim(res::ui.getResAnim("equip_quickslot"));
	button->setAnchor(0.0f, 0.5f);
	button->attachTo(view);
	button->addEventListener(TouchEvent::TOUCH_DOWN, CLOSURE(this, &EquipmentButton::onEvent));
	button->addEventListener(TouchEvent::TOUCH_UP, CLOSURE(this, &EquipmentButton::onEvent));

	equip_sprite = new Sprite;
	equip_sprite_str = "sword_equipmenu";
	equip_sprite->setResAnim(res::ui.getResAnim(equip_sprite_str));
	equip_sprite->setAnchor(-0.27f, 0.5f);
	equip_sprite->attachTo(view);
	equip_sprite->addEventListener(TouchEvent::TOUCH_DOWN, CLOSURE(this, &EquipmentButton::onEvent));
	equip_sprite->addEventListener(TouchEvent::TOUCH_UP, CLOSURE(this, &EquipmentButton::onEvent));

	view->setScale(1.5f);
}

void EquipmentButton::setX(float x)
{
	view->setX(x);
}

void EquipmentButton::setY(float y)
{
	view->setY(y);
}

float EquipmentButton::getWidth()
{
	return button->getWidth();
}

float EquipmentButton::getHeight()
{
	return button->getHeight();
}

EquipmentButton::EquipmentButton() : pressed(false)
{
	equipment = "";
	equip_sprite_str = "";
}

void EquipmentButton::setEquipmentMenu(std::string equip)
{
	equip_sprite_str = equip;
	equip_sprite->setResAnim(res::ui.getResAnim(equip_sprite_str));
}
void EquipmentButton::setEquipment(std::string equip)
{
	equipment = equip;
}

void EquipmentButton::onEvent(Event* ev)
{
	TouchEvent* te = safeCast<TouchEvent*>(ev);

	if (te->type == TouchEvent::TOUCH_DOWN) {
		button->setColor(Color::Red);
		pressed = true;
	}

	if (te->type == TouchEvent::TOUCH_UP) {
		game->setPlayerRHWeapon(equipment);
		button->setColor(Color::White);
		pressed = false;
	}
}
