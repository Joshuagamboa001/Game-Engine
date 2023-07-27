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

	}

	void OnEvent(Hazel::Event& event) override
	{
		if (event.GetEventType() == Hazel::EventType::KeyPressed)
		{
			Hazel::KeyPressedEvent& e = (Hazel::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HAZEL_KEY_TAB)
				HAZEL_TRACE("Tab key is pressed (event)!");
			HAZEL_TRACE("{0}", (char)e.GetKeyCode());
		}
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