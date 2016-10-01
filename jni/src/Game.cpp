//
// Created by cvalenza on 8/28/16.
//

#include "Game.h"
#include "Joystick.h"
#include "EquipmentButton.h"
#include "Player.h"
#include "res.h"

Game::Game()
{
}

void Game::init()
{
	// setSize is inherited from Actor and sets the size of the game
	// (which we get from the size of the scene)
	setSize(getStage()->getSize());

	// create the background
	spSprite ground = new Sprite;
	ground->setResAnim(res::ui.getResAnim("ground"));
	float stage_width = getWidth();
	float bg_width = ground->getWidth();
	float stage_height = getHeight();
	float bg_height = ground->getHeight();
	ground->setScale(stage_width / bg_width, stage_height / bg_height);
	ground->attachTo(this);

	// create the player
	player = new Player;
	player->init(this);

	// create joystick
	move = new Joystick;
	move->attachTo(this);
	move->setY(getHeight() * 0.2f);

	look = new Joystick;
	look->attachTo(this);
	look->setY(getHeight() * 0.2f);
	look->setX(getWidth() - look->getWidth());

	slot1 = new EquipmentButton;
	slot1->init(this);
	slot1->setEquipment("sword");
	slot1->setEquipmentMenu("sword_equipmenu");
	slot1->setY(getHeight() - slot1->getHeight());
	slot1->setX(getWidth() / 2 - slot1->getWidth() * 1.5 - slot1->getWidth() * 0.75);

	slot2 = new EquipmentButton;
	slot2->init(this);
	slot2->setEquipment("alt_sword");
	slot2->setEquipmentMenu("alt_sword_equipmenu");
	slot2->setY(getHeight() - slot2->getHeight());
	slot2->setX(getWidth() / 2 - slot2->getWidth() * 0.75);

	slot3 = new EquipmentButton;
	slot3->init(this);
	slot3->setY(getHeight() - slot3->getHeight());
	slot3->setX(getWidth() / 2 + slot3->getWidth() * 0.75);
}

void Game::setPlayerRHWeapon(std::string weap)
{
	player->setRHWeapon(weap);
}

void Game::doUpdate(const UpdateState& us)
{
	player->update(us);
}