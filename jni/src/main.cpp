/**
 * main.cpp
 *
 * Author: Chuck Valenza
 *
 * Description:
 *	Recreation of the demo project in Oxygine so I can become acquainted with how to develop in it
 *   and feel comfortable with the project structure and compilation process.
 */

// These are all part of the oxygine framework
#include "core/oxygine.h"
#include "Stage.h"
#include "DebugActor.h"

// These are from my project
#include "example.h"

// I don't like using namespaces on whole files, I'll have to refactor this out later...
using namespace oxygine;

/**
 * Implement the basic game logic that occurs each loop
 */
int gameLoop()
{
	bool done = core::update(); // this will update things in the oxygine engine. input events are
								// passed to Stage::instance.handleEvent. if core::update returns
								// true, the program has been terminated by the user
	example_update(); // update things in our game? not really sure as it is empty in the demo
	getStage()->update(); // update the stage and all actors

	if (core::beginRendering()) {
		Color clear_color(32, 32, 32, 255);
		Rect viewport(Point(0, 0), core::getDisplaySize());

		getStage()->render(clear_color, viewport); // render the next stage
		core::swapDisplayBuffers(); // swap the current buffer out
	}

	return done ? 1 : 0;
}

/**
 * The main run function that will be executed by our main
 */
void run()
{
	ObjectBase::__startTracingLeaks(); // starts checking for leaked objects

	// set up the application description
	core::init_desc desc;
	desc.title = "Chuck's Game";

	example_preinit();
	core::init(&desc);

	// The Stage is the root node for objects in our scene. Think of it as a stage in theater
	Stage::instance = new Stage(true);
	Point size = core::getDisplaySize();
	getStage()->setSize(size);

	// This is just to show debug information: FPS, memory usage, etc...
	DebugActor::show();

	// initializes the example game
	example_init();

	// execute the game logic loop
	while (1) {
		if (gameLoop()) {
			break;
		}
	}

	// at this point in the program, the user has exited the game loop and wishes to exit the game,
	// time to clean up the objects that still exist in memory and were supposed to be freed
	ObjectBase::dumpCreatedObjects();

	// delete all existing objects by hand
	example_destroy();

	// "release" (free?) the engine objects and the game stage
	core::release();

	// reattempt to free un-freed memory
	ObjectBase::dumpCreatedObjects();

	// stop the thread checking for memory leaks
	ObjectBase::__stopTracingLeaks();
}

#ifdef __S3E__
int main(int argc, char* argv[])
{
	run();
	return 0;
}
#endif


#ifdef OXYGINE_SDL

#include "SDL_main.h"
#include "SDL.h"

extern "C" {
	void one(void* param) { gameLoop(); }
	void oneEmsc() { gameLoop(); }

	int main(int argc, char* argv[])
	{
		run();
		return 0;
	}
};
#endif