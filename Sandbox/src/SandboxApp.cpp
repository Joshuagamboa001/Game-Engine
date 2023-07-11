#include <Hazel.h>

class SandBox : public Hazel::Application
{
public:
	SandBox()
	{

	}

	~SandBox()
	{

	}
};

// Goes to Entry Point so main can run in GameEngine.dll and not Sandbox.exe
Hazel::Application* Hazel::CreateApplication()
{
	return new SandBox();
}