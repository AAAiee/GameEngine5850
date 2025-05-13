#Collect all source files in ENGINE_SRC
file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS "Source/*.cpp" "Source/*.h")


# add build path to SDL3 
set(SDL_DISABLE_GIT_INFO ON CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE) 
set(SLD_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/sdl3)
add_subdirectory(${SDL_PATH} EXCLUDE_FROM_ALL)

# Create a static linked lib target called Engine
add_library(Engine STATIC ${ENGINE_SRC})

#Expose the Source/ directory as a public include path while 
#the project is built from the source tree
target_include_directories(Engine 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Source>
)   

#Links SDL3 to Engine statically
target_link_libraries(Engine PRIVATE SDL3::SDL3-static)
target_include_directories(Engine PRIVATE ${SDL_PATH}/include)

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








