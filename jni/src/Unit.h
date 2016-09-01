//
// Created by cvalenza on 8/30/16.
//

#ifndef OXYGINE_HW_UNIT_H
#define OXYGINE_HW_UNIT_H

#include "oxygine-framework.h"

using namespace oxygine;

class Game;

class Unit : public Object {
	private:
	public:
		Unit();
		void init(Game* g);
		void update(const UpdateState& us);
	protected:
		spActor view;
		Game* game;

		virtual void _init() {}
		virtual void _update(const UpdateState& us) {}
};

#endif //OXYGINE_HW_UNIT_H
