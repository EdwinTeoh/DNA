#pragma once

#ifdef DNA_WINDOWS

extern DNA::Application* DNA::CreateApplication();

int main(int argc, char** argv)
{
	auto app = DNA::CreateApplication();
	app->Run();
	delete app;
}

#endif