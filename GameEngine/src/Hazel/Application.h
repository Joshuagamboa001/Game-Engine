#pragma once


#include "Core.h"
#include "Hazel/LayerStack.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Events/Events.h"
#include "Window.h"

#include "Hazel/ImGui/ImGuiLayer.h"

#include "Hazel/Renderer/Shader.h"

namespace Hazel {
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() {
			return *s_Instance;
		}

		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		std::unique_ptr<ImGuiLayer> m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;
	private:
		static Application* s_Instance;
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}


