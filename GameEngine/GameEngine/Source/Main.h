#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern Application* CreateApplication();

int main(int Argc, char** Argv)
{
	Application* App = CreateApplication();
	App->Run();
	delete App;

	return 0;
}

#endif
