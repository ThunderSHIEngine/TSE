#include "tepch.h"
#include "Application.h"
#include "Log.h"
#include <GLFW/glfw3.h>

namespace Thunder
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{

	}
	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}
	void Application::PushOverLay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}
	void Application::OnEvent(Event& event_)
	{
		EventDispatcher dispatcher(event_);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));


		TE_CORE_TACE("{0}", event_);
	}

	void Application::Run()
	{
		//WindowResizeEvent e(1280, 720);
		//TE_CLIENT_TACE(e);
		while (m_Runing)
		{
			glClearColor(0.5, 0.6, 0.6, 0.5);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent e)
	{
		m_Runing = false;
		return true;
	}

}
