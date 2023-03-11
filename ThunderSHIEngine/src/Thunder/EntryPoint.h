#pragma once

#ifdef TE_PLATFORM_WINDOWS

extern Thunder::Application* Thunder::CreateApplication();

int main(int argc, char** argv)
{
	Thunder::Log::Init();
	TE_CORE_WARN("Initialized Log!!!");
	int a = 5;
	TE_CLIENT_INFO("Hello Thunder!!! Var = {0}", a);

	auto app = Thunder::CreateApplication();
	app->Run();
	delete app;
}







#endif // TE_PLATFORM_WINDOWS


