//------------------------------------------------------------------------------
// Main.cpp
//
// Entry point for the Nightbloom Sandbox
// Copyright (c) 2024 Your Name. All rights reserved.
//------------------------------------------------------------------------------

#include <iostream>
#include "Engine/Core/Base.hpp"
#include "Engine/Core/Logger/Logger.hpp"
#include "Engine/Core/Logger/ConsoleLogger.hpp"
#include "Engine/Core/Logger/FileLogger.hpp"

namespace Nightbloom
{
	void EngineInit()
	{
		// Initialize logging system
		Logger& logger = Logger::Get();

		// Add console output with colors
		logger.AddSink(std::make_shared<ConsoleLogger>(true));

		// Add file output
		logger.AddSink(std::make_shared<FileLogger>("NightBloom.log"));

		// Set default log level
		logger.SetLogLevel(LogLevel::Trace);

		//LOG_INFO_S("NightBloom Engine Initialized");

		LOG_INFO("NightBloom Engine Initialized");
		LOG_INFO("Version {}.{}.{}",
			NIGHTBLOOM_VERSION_MAJOR,
			NIGHTBLOOM_VERSION_MINOR,
			NIGHTBLOOM_VERSION_PATCH);
	}
	void EngineShutdown()
	{
		LOG_INFO("Shutting down...");
		Logger::Get().ClearSinks();
	}
}

int main(int argc, char** argv)
{
	Nightbloom::EngineInit();

//	LOG_INFO("Playform: {}",
//#ifdef NIGHTBLOOM_PLATFORM_WINDOWS
//		"Windows"
//#elif defined(NIGHTBLOOM_PLATFORM_LINUX)
//		"Linux"
//#elif defined(NIGHTBLOOM_PLATFORM_MACOS)
//		"macOS"
//#else
//		"Unknown Platform"
//#endif
//	);

	LOG_INFO("Sandbox Application Running!\n");
	LOG_DEBUG("Command line args: {}", argc);

	LOG_TRACE("This is a trace message");
	LOG_DEBUG("This is a debug message");
	LOG_INFO("This is an info message");
	LOG_WARN("This is a warning message");
	LOG_ERROR("This is an error message");

	// Shutdown the engine gracefully
	Nightbloom::EngineShutdown();

	// Keep console open on Windows
#ifdef NIGHTBLOOM_PLATFORM_WINDOWS
	std::cout << "\nPress Enter to exit...";
	std::cin.get();
#endif

	return 0;
}