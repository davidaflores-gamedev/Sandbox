@echo off
echo Generating Nightbloom Sandbox project files...

REM First check if engine is built
if not exist "..\NightBloom\Build\NightbloomEngineConfig.cmake" (
    echo ERROR: Engine must be built first!
    echo Please run GenerateProject.bat in NightBloom folder
    pause
    exit /b 1
)

if not exist "Build" mkdir Build
cd Build

cmake .. -G "Visual Studio 17 2022" -A x64

if %ERRORLEVEL% NEQ 0 (
    echo CMake generation failed!
    pause
    exit /b %ERRORLEVEL%
)

echo.
echo Sandbox project generated successfully!
echo Open Build\NightbloomSandbox.sln in Visual Studio
pause