#pragma once
//
//#include "Hazel/Core/Base.h"
//#include "Hazel/Core/Timestep.h"
#include "Thunder/Core.h"
#include "Thunder/Events/Event.h"

namespace Thunder {

	class THUNDER_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		//virtual void OnUpdate(Timestep ts) {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}