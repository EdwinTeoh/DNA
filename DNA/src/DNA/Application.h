#pragma once

#include "Core.h"

namespace DNA {
	class DNA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}
