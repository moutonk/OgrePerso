#include "Window.h"

Window		*Window::instance = NULL;

Window::Window(void)
{
	this->win = NULL;
	this->root = NULL;
	this->events = new Events;
}


Window::~Window(void)
{
}

void	Window::createWindow()
{
	this->root = new Ogre::Root("plugins_d.cfg", "ogre.cfg", "Ogre.log");
	if(this->root->showConfigDialog())
    {
        this->win = this->root->initialise(true, "Window de test");
		this->events->initialisation();
		this->events->launchThread();
	}
}
