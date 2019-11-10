
/// GameEngine
#include<Core.h>

class GameApplication : public Application
{
public:

	GameApplication() {}
	~GameApplication() {}


};



Application*  CreateApplication()
{
	return new GameApplication();
}
