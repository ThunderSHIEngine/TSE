#pragma once

#ifdef TE_PLATFORM_WINDOWS

extern Thunder::Application* Thunder::CreateApplication();

int main(int argc, char** argv)
{
	
	auto app = Thunder::CreateApplication();
	app->Run();
	delete app;
}







#endif // TE_PLATFORM_WINDOWS


