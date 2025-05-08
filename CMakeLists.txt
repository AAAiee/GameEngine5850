cmake_minimum_required(VERSION 3.20)


project(GameEngine LANGUAGES CXX)
#--- Global compiler options ----------
set(CMAKE_CXX_STANDARD 17) # C++ 17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



# ---------- pick an arch label ----------
if (MSVC AND CMAKE_VS_PLATFORM_NAME)
    set(_arch "${CMAKE_VS_PLATFORM_NAME}")   # x64 / Win32 / ARM64 …
else()
    set(_arch "${CMAKE_SYSTEM_PROCESSOR}")
endif()

# ---------- outputs under <source>/Binaries/<OS>-<arch>/<cfg> ----------
set(_out "${CMAKE_SOURCE_DIR}/Binaries/${CMAKE_SYSTEM_NAME}-${_arch}")

foreach(type RUNTIME LIBRARY ARCHIVE)
    set(CMAKE_${type}_OUTPUT_DIRECTORY "${_out}/$<CONFIG>")
endforeach()


# Game Object and Engine
add_subdirectory(GameExamples)
add_subdirectory(GameEngine)

#start-up project in VS to be Game
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Game)

