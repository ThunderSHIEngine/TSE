#pragma once


#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "LayerStack.h"

namespace Thunder
{
	class THUNDER_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();

		void OnEvent(Event& event_);

		void PushLayer(Layer* layer);
		void PushOverLay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent e);
		std::unique_ptr<Window> m_Window;
		bool m_Runing = true;

		LayerStack m_LayerStack;

	};
	//to be defined in client
	Application* CreateApplication();

}


