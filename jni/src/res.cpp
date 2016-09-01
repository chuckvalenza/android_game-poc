//
// Created by cvalenza on 8/27/16.
//

#include "res.h"

namespace res {
	Resources ui;

	void load()
	{
		// this will load the resources for the application
		ui.loadXML("xmls/ui.xml");
	}

	void free()
	{
		ui.free();
	}
}