#pragma once

#ifdef GE_PLATFORM_WINDOWS

#include "Log.h"

extern Application* CreateApplication();

int main(int Argc, char** Argv)
{
	Log::Get().Init();

	Application* App = CreateApplication();
	App->Run();
	delete App;

	return 0;
}

#endif
