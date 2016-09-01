//
// Created by cvalenza on 8/30/16.
//

#include "Unit.h"
#include "Game.h"

Unit::Unit() : game(0)
{

}

void Unit::init(Game* g)
{
	game = g;
	view = new Actor;
	view->attachTo(game);
	_init();
}

void Unit::update(const UpdateState& us)
{
	_update(us);
}