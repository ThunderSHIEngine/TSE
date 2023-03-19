#pragma once
#include "Thunder.h"

class ExampleLayer : public Thunder::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{

	}
	void OnUpdate() override
	{
		TE_CLIENT_INFO("ExampleLayer::Update");
	}
	void OnEvent(Thunder::Event& event_)override
	{
		TE_CLIENT_TACE("{0}", event_);
	}
};


class SandBox : public Thunder::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
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