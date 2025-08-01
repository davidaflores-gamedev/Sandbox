#include "Engine/Core/Application.hpp"
#include "Engine/Core/Logger/Logger.hpp"

class Sandbox : public Nightbloom::Application
{
public: Sandbox() : Application("Nightbloom Sandbox") {}

	  void OnStartup() override
	  {
		  LOG_INFO("Sandbox application started");
	  }

	  void OnUpdate(float deltaTime) override
	  {
		  // Update logic here
		  // Update game logic
		 // LOG_INFO("Updating Sandbox: Delta Time = {:.3f} seconds", deltaTime);

		  m_FrameTime += deltaTime;
		  m_FrameCount++;

		  // Update title every second instead of every 60 frames
		  if (m_FrameTime >= 5.0f)
		  {
			  float fps = m_FrameCount / m_FrameTime;
			  //GetWindow()->SetTitle(std::format("NightBloom Sandbox - FPS: {:.1f}", fps));
			  LOG_INFO("FPS: {:.1f}", fps);
			  m_FrameTime = 0.0f;
			  m_FrameCount = 0;
		  }
	  }

private: 
	float m_FrameTime = 0.0f; // Time accumulated for FPS calculation
	int m_FrameCount = 0;      // Frame count for FPS calculation
};

Nightbloom::Application* Nightbloom::CreateApplication()
{
	return new Sandbox();
}