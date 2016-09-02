//
// Created by cvalenza on 8/28/16.
//

#include "Game.h"
#include "Joystick.h"
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
	ground->setResAnim(res::ui.getResAnim("sky"));
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
	move->setY(getHeight() - move->getHeight());
}

void Game::doUpdate(const UpdateState& us)
{
	player->update(us);
}