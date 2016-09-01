//
// Created by cvalenza on 8/27/16.
// not sure why the example makes this separate from the main.cpp...I guess I may see why later
//

#include "example.h"
#include "oxygine-framework.h"
#include "res.h"
#include "Game.h"

using namespace oxygine;

void example_preinit()
{
}

void example_init()
{
	// load resources? example is vague. not exactly sure what this does.
	res::load();

	// create our game
	spGame game = new Game;
	game->init();
	game->attachTo(getStage());
}

void example_update()
{
}

void example_destroy()
{
	res::free();
}