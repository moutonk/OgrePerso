#include "Events.h"
#include "Window.h"

Events::Events(void)
{
	this->isRunning = false;
	this->isKeyPressed = false;
	this->keyRepeatActive = true;
}

void	Events::initialisation()
{
	OIS::ParamList pl;
	size_t windowHnd = 0;
	std::ostringstream windowHndStr;
 
	Window::getInstance()->getWin()->getCustomAttribute("WINDOW", &windowHnd);
	windowHndStr << windowHnd;
	pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));
	pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_FOREGROUND" )));
	pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_NONEXCLUSIVE")));
	pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_FOREGROUND")));
	pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_NONEXCLUSIVE")));

	this->inputManager = OIS::InputManager::createInputSystem(pl);
	this->keyboard = static_cast<OIS::Keyboard*>(this->inputManager->createInputObject(OIS::OISKeyboard, true));
	this->keyboard->setEventCallback(this);
	this->mouse = static_cast<OIS::Mouse*>(this->inputManager->createInputObject( OIS::OISMouse, true ) );
	this->mouse->setEventCallback(this);
}

bool	Events::mouseMoved( const OIS::MouseEvent &arg )
{
	//std::cout << "move" << std::endl;
	return true;
}

bool	Events::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
	if (id == OIS::MouseButtonID::MB_Left)
		std::cout << "Buttob left pressed: " << arg.state.X.abs << " " << arg.state.Y.abs << std::endl;
	if (id == OIS::MouseButtonID::MB_Right)
		std::cout << "Buttob right pressed: " << arg.state.X.abs << " " << arg.state.Y.abs << std::endl;
	return true;
}

bool	Events::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
    return true;
}

bool	Events::keyPressed(const OIS::KeyEvent &e)
{
	this->isKeyPressed = true;

	if (e.key == OIS::KC_UNASSIGNED) /*KEY AUTO REPEAT*/
	{
		OIS::KeyEvent	keyEvent(NULL, this->keyPressedId, 0);
		this->interpretKeyPressed(keyEvent);
	}
	else /*KEY SINGLE REPEAT*/
	{
		this->keyPressedId = e.key;
		this->interpretKeyPressed(e);
	}
    return true;
}

void	Events::interpretKeyPressed(OIS::KeyEvent e)
{
	switch (e.key)
	{
		case OIS::KC_ESCAPE: 
			exit (0);
			break;
		case OIS::KC_LEFT: 
			std::cout << "LEFT\n";
			break;
		case OIS::KC_RIGHT: 
			std::cout << "RIGHT\n";
			break;
		case OIS::KC_UP: 
			std::cout << "UP\n";
			break;
		case OIS::KC_DOWN: 
			std::cout << "DOWN\n";
			break;
		default:
			break;
	}
}

bool	Events::keyReleased( const OIS::KeyEvent &e )
{
	this->isKeyPressed = false;
    return true;
}

void		Events::eventsLoop()
{
	OIS::KeyEvent	keyEvent(NULL, OIS::KC_UNASSIGNED, 0);

	while (isRunning == true)
	{
		boost::this_thread::sleep(boost::posix_time::millisec(100));
		if (this->keyRepeatActive == true && this->isKeyPressed == true) /*KEY AUTO REPEAT*/
			this->keyPressed(keyEvent);
		this->keyboard->capture();
		this->mouse->capture();
	}
}

void		Events::run()
{
	std::cout << "******** Thread Events Launched ********" << std::endl;
	this->isRunning = true;
	this->eventsLoop();
	std::cout << "******** Thread Events Ended ********" << std::endl;
}

void		Events::launchThread()
{
	thread = boost::shared_ptr<boost::thread>(new boost::thread(boost::bind(&Events::run, this)));
}

void		Events::stopThread()
{
	if (this->thread != NULL)
	{
		this->isRunning = false;
		//this->mThread->interrupt();
	}
}

Events::~Events(void)
{
}
