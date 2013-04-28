#include "Test.h"
#include "conio.h"
#include <OgreLog.h>
#include <OgreLogManager.h>

Test::Test(void)
{
	mRoot = new Ogre::Root("plugins_d.cfg", "ogre.cfg", "Ogre.log");
	if(mRoot->showConfigDialog())
    {
         mWindow = mRoot->initialise(true, "Window de test");
		
		size_t hWnd = 0;
		this->mWindow->getCustomAttribute("WINDOW", &hWnd);
		this->mInputManager = OIS::InputManager::createInputSystem(hWnd);
		this->mKeyboard = static_cast<OIS::Keyboard*>(this->mInputManager->createInputObject(OIS::OISKeyboard, false));
	}
}

void		Test::eventsLoop()
{
	while (1)
	{
		boost::this_thread::sleep(boost::posix_time::millisec(1000));
		this->mKeyboard->capture();
		this->getKeyPressed();
		std::cout << "loopEvents" << std::endl;
	}
}

void		Test::getKeyPressed()
{
	if (mKeyboard->isKeyDown(OIS::KC_ESCAPE))
	{
		std::cout << "ESCAPE" << std::endl;
		delete this->mRoot;
		exit (0);
	}
	if (mKeyboard->isKeyDown(OIS::KC_DOWN))
	{
		std::cout << "DOWN" << std::endl;
	}
	if (mKeyboard->isKeyDown(OIS::KC_UP))
	{
		std::cout << "UP" << std::endl;
	}
}

void		Test::run()
{
	std::cout << "run starts" << std::endl;
	this->eventsLoop();
	std::cout << "run ends" << std::endl;
}

void		Test::go()
{
	mThread = boost::shared_ptr<boost::thread>(new boost::thread(boost::bind(&Test::run, this)));
	//mThread->join();
}

Test::~Test(void)
{
}
