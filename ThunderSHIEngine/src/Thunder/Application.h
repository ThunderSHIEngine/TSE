#pragma once
#include "Core.h"
#include "Events/Event.h"
namespace Thunder
{
	class THUNDER_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();


	private:


	};
	//to be defined in client
	Application* CreateApplication();

}


