#include "Hzpch.h"
#include "OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Hazel {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		HAZEL_CORE_ASSERT(windowHandle, "Window handle is null!");
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HAZEL_CORE_ASSERT(status, "Failed to initialize Glad!");

		HAZEL_CORE_INFO("OpenGL Info");
		HAZEL_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		HAZEL_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		HAZEL_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));
	
	}
	void OpenGLContext::SwapBuffers()
	{



		glfwSwapBuffers(m_WindowHandle);
	}
}