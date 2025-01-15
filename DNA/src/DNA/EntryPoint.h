#pragma once

#ifdef DNA_WINDOWS

extern DNA::Application* DNA::CreateApplication();

int main(int argc, char** argv)
{
	DNA::Log::Init();
	DNA_CORE_WARN("Initialized Log");
	int a = 5;
	DNA_INFO("Var={0}", a);

	auto app = DNA::CreateApplication();
	app->Run();
	delete app;
}

#endif