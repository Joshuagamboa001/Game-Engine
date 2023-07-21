 #pragma once

// Main function is ran here

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char**argv)
{
	//Initializes log
	Hazel::Log::Init();
	HAZEL_CORE_WARN("Initialized Log!");
	HAZEL_WARN("Hello!");

	//Loop that runs application.cpp
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;

}

#endif