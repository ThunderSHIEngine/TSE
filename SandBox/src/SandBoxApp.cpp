#pragma once
#include "Thunder.h"
class SandBox : public Thunder::Application
{
public:
	SandBox()
	{

	}
	~SandBox()
	{

	}

private:

};

Thunder::Application* Thunder::CreateApplication()
{
	return new SandBox();
}

//void main()
//{
//	SandBox* sandbox = new SandBox();
//
//	sandbox->Run();
//
//	delete sandbox;
//	//Run();
//}