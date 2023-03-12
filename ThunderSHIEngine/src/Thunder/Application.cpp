#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Thunder
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		TE_CLIENT_TACE(e);
		while (true);
	}



}
