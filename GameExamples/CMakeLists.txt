# -------------------------------------------------------------
#  App/CMakeLists.txt  – builds the sample game executable
# -------------------------------------------------------------

project(GameExamples)
# 1. Collect every *.cpp / *.h under Source/
file(GLOB_RECURSE APP_SRC CONFIGURE_DEPENDS
     "Source/*.cpp" "Source/*.h")

# 2. Create the executable target
add_executable(Game ${APP_SRC})

# 3. App’s own header search path (only needed while building *Game* itself)
target_include_directories(Game
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Source)

# 4. Link against the engine shared/static library
target_link_libraries(Game
    PRIVATE Engine)      # Engine exported include-paths & defs propagate

# 5. Per-configuration symbols so source can gate code with #ifdef DEBUG/RELEASE
target_compile_definitions(Game
    PRIVATE
        $<$<CONFIG:Debug>:DEBUG>
        $<$<CONFIG:Release>:RELEASE>
        $<$<CONFIG:Dist>:DIST>
)

# 6. Windows-specific tweaks (optional)
if(MSVC)
    # Tell MSVC to treat the main source file as UTF-8 and use warnings-as-errors
    target_compile_options(Game PRIVATE /utf-8 /W4 /WX)
    target_compile_definitions(Game PRIVATE WINDOWS)   # example macro
endif()