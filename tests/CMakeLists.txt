# Information cmake
cmake_minimum_required(VERSION 3.0.2)

include(GoogleTest)

# add subdirectory
add_subdirectory( ../submodules/googletest build/googletest)

add_definitions(-DUNIT_TESTS)
set(PROJECT_SOURCES
	Simple.cpp
)

add_executable(covinhas_test ${PROJECT_SOURCES})

target_include_directories (covinhas_test PRIVATE 
		../include/
		../packages/
)


target_link_libraries(covinhas_test gtest gtest_main)