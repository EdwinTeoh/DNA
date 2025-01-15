#include <DNA.h>

class Sandbox : public DNA::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

DNA::Application* DNA::CreateApplication()
{
	return new Sandbox();
}