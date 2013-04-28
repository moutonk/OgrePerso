#pragma once
#include <stddef.h>
#include <OgreRenderWindow.h>
#include <OgreRoot.h>
#include "Events.h"

class Window
{
	Window(void);
	static Window		*instance;

	IEvents				*events;
	Ogre::Root			*root;
	Ogre::RenderWindow	*win;

public:
	~Window(void);

	static Window*		getInstance()
	{
		if (instance == NULL)
			instance = new Window;
		return instance;
	}

	Ogre::RenderWindow	*getWin() {return this->win;};

	void		createWindow();
};

