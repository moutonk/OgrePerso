#pragma once

#include "IEvents.h"
#include <OISKeyboard.h>
#include <OISMouse.h>
#include <OISInputManager.h>
#include <OgreRenderWindow.h>
#include <OgreRoot.h>

class Events : public OIS::MouseListener, public OIS::KeyListener, public IEvents
{
	bool								keyRepeatActive;
	bool								isKeyPressed;
	OIS::KeyCode						keyPressedId;

	bool								isRunning;
	OIS::InputManager					*inputManager;
	OIS::Keyboard						*keyboard;
	OIS::Mouse							*mouse;
	OIS::MouseListener					*mouseListener;
	boost::shared_ptr<boost::thread>	thread;

public:
	Events(void);
	~Events(void);

	virtual bool	keyPressed( const OIS::KeyEvent &e );
    virtual bool	keyReleased( const OIS::KeyEvent &e );

	virtual bool	mouseMoved( const OIS::MouseEvent &arg );
	virtual bool	mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
	virtual bool	mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );

	virtual void	eventsLoop();
	virtual void	initialisation();
	virtual void	launchThread();
	virtual void	run();
	virtual void	stopThread();
	virtual void	interpretKeyPressed(OIS::KeyEvent e);
	virtual void	enableKeyAutoRepeat(bool active) {this->keyRepeatActive = active;};
};

