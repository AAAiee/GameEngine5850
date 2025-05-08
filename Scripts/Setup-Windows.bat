@echo off
rem -----------------------------------------------------------
rem  Build-Windows.bat : configure + build with MSVC / MSBuild
rem -----------------------------------------------------------

setlocal EnableExtensions EnableDelayedExpansion

:: 1. Detect launch method
:: If from command line → use first argument as CONFIG
:: If double-clicked → use default = Debug
set "CONFIG=Debug"
if not "%~1"=="" (
    set "CONFIG=%~1"
)

:: 2. Show current config
echo.
echo [INFO] Building configuration: %CONFIG%
echo.

:: 3. Move to the repo root (assuming script is in Scripts/)
cd /d "%~dp0.."

:: 4. Create build folder if needed
if not exist build (
    mkdir build
)
cd build

:: 5. Run CMake configure (once)
if not exist CMakeCache.txt (
    echo [INFO] Running CMake configuration with MSVC...
    cmake .. -G "Visual Studio 17 2022" -A x64 || goto :fail
)

:: 6. Build using MSBuild (via CMake)
echo [INFO] Building with MSBuild...
cmake --build . --config %CONFIG% || goto :fail

echo.
echo [SUCCESS] Binaries are in:
echo   ..\Binaries\Windows-x64\%CONFIG%
goto :end

:fail
echo.
echo [FAILED] Build stopped due to errors.

:end
:: Only pause if launched by double-click (no args passed)
if "%~1"=="" pause
endlocal

