project(GameEngine)

#Collect all source files in ENGINE_SRC
file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS "Source/*.cpp" "Source/*.h")

include(FetchContent)

# spdlog
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.x
)
FetchContent_MakeAvailable(spdlog)

#SDL
set (SDL_STATIC ON CACHE BOOL "Build static sdl3" FORCE)
set (SDL_SHARED OFF CACHE BOOL "Disable shared SDL3 build" FORCE)
FetchContent_Declare(
    SDL
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG main
)
FetchContent_MakeAvailable(SDL)

# Create a static linked lib target called Engine
add_library(Engine STATIC ${ENGINE_SRC})

# link external libraries
target_link_libraries(Engine PRIVATE spdlog::spdlog SDL3-static)

#Expose the Source/ directory as a public include path while 
#the project is built from the source tree
target_include_directories(Engine 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Source>
)   

target_compile_definitions(Engine
    PUBLIC
    $<$<CONFIG:Debug>:DEBUG>
    $<$<CONFIG:Release>:RELEASE>
    $<$<CONFIG:Dist>:DIST>
)


#Window-specific flags
if (MSVC)
      target_compile_options(Engine PRIVATE /EHsc /Zc:preprocessor /Zc:__cplusplus)
endif()








