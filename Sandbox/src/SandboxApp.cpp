#include <Hazel.h>

class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		HAZEL_INFO("ExampleLayer::Update");
	}

	void OnEvent(Hazel::Event& event) override
	{
		HAZEL_TRACE("{0}", event);
	}
};



class SandBox : public Hazel::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer()); 
		PushOverlay(new Hazel::ImGuiLayer());
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