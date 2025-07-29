//------------------------------------------------------------------------------
// Main.cpp
//
// Entry point for the Nightbloom Sandbox
// Copyright (c) 2024 Your Name. All rights reserved.
//------------------------------------------------------------------------------

#include <iostream>
#include "Engine/Core/Engine.hpp"
#include "Engine/Core/Base.hpp"
#include "Engine/Core/Logger/Logger.hpp"
#include "Engine/Core/Logger/ConsoleLogger.hpp"
#include "Engine/Core/Logger/FileLogger.hpp"

namespace Nightbloom
{
}

int main(int argc, char** argv)
{
	// Initialize the engine
	Nightbloom::EngineInit();

	// Test Logging
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
