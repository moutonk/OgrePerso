#pragma once
#include <OIS.h>
#include <OISEvents.h>

class	IEvents
{
	virtual void	eventsLoop() = 0;
	virtual void	run() = 0;
	virtual void	stopThread() = 0;
	virtual void	interpretKeyPressed(OIS::KeyEvent) = 0;

public:
	virtual void	initialisation() = 0;
	virtual void	launchThread() = 0;
	virtual void	enableKeyAutoRepeat(bool) = 0;
};