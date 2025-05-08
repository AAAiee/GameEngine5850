#Collect all source files in ENGINE_SRC
file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS "Source/*.cpp" "Source/*.h")

# Create a shared-library target called Engine
add_library(Engine SHARED ${ENGINE_SRC})

#Expose the Source/ directory as a public include path while 
#the project is built from the source tree
target_include_directories(Engine 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Source>
)   

#Expose the Source/ directory as a public include path while the project is built from the source tree
target_compile_definitions(Engine
    PUBLIC
    $<$<CONFIG:Debug>:DEBUG>
    $<$<CONFIG:Release>:RELEASE>
    $<$<CONFIG:Dist>:DIST>
)


#Window-specific flags
if (MSVS)
      target_compile_options(Engine PRIVATE /EHsc /Zc:preprocessor /Zc:__cplusplus)
endif()








