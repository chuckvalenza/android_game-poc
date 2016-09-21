//
// Created by cvalenza on 9/18/16.
//

#ifndef OXYGINE_HW_EQUIPMENTBUTTON_H
#define OXYGINE_HW_EQUIPMENTBUTTON_H

#include "Unit.h"
#include "Game.h"

using namespace oxygine;

DECLARE_SMART(EquipmentButton, spEquipmentButton);

class EquipmentButton : public Unit {
	private:
		std::string equipment;
		std::string equip_sprite_str;
		bool pressed;
		void onEvent(Event *ev);
		spSprite button;
		spSprite equip_sprite;
	public:
		EquipmentButton();
		void setEquipment(std::string equip);
		void setEquipmentMenu(std::string equip);
		bool getStatus();
		void _init();
		void setX(float x);
		void setY(float y);
		float getWidth();
		float getHeight();
};

#endif //OXYGINE_HW_EQUIPMENTBUTTON_H
