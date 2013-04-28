#pragma comment(lib, "OgreMain_d.lib")
#pragma comment(lib, "OIS_d.lib")
#pragma comment(lib, "RenderSystem_GL_d.lib")
#pragma comment(lib, "RenderSystem_Direct3D9_d.lib")

#include "Window.h"
#include "Events.h"

int main(int ac, char**av)
{
	Window::getInstance()->createWindow();

	std::cout << "waiting input" << std::endl;
	std::string s;
	while (std::getline(std::cin,  s))
		std::cout << s << std::endl;
	return 0;
}

