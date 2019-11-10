// Copyright Paul Baudy

#pragma once

#include "GameEngine.h"

class GE_API Application
{
public:
	virtual void Run();

};

Application* CreateApplication();