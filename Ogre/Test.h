#pragma once

#include <OgreRoot.h>
#include <OISKeyboard.h>
#include <OgreRenderWindow.h>
#include <OISInputManager.h>

class Test
{
	Ogre::Root							*mRoot;
	Ogre::RenderWindow					*mWindow;
	OIS::InputManager					*mInputManager;
	OIS::Keyboard						*mKeyboard;
	boost::shared_ptr<boost::thread>	mThread;

public:
	Test(void);
	~Test(void);
	void	go();
	void	eventsLoop();
	void	getKeyPressed();
	void	run();
};

