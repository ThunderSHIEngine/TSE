#include "tepch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"
#include <GLFW/glfw3.h>

namespace Thunder
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		//WindowResizeEvent e(1280, 720);
		//TE_CLIENT_TACE(e);
		while (m_Runing)
		{
			glClearColor(0.5, 0.3, 0.6, 0.5);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}



}
