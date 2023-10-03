# Information cmake
cmake_minimum_required(VERSION 3.0.2)

# set variables

# add subdirectory
add_subdirectory( ../submodules/spdlog build/spdlog )
add_subdirectory( ../submodules/unicorn build/unicorn )
add_subdirectory( ../submodules/lief build/lief )


set(UNICORN_LINK_LIBRARIES ${UNICORN_LINK_LIBRARIES}  unicorn )

# add executable and target libraries
add_executable(covinhas main.cpp)

target_include_directories (covinhas PRIVATE 
		../include/
		../packages/
		../submodules/unicorn/include
		../interfaces
		../submodules/lief/include
)

file(GLOB_RECURSE SOURCES
        *.cpp
)

target_sources(covinhas PRIVATE 
		${SOURCES}
)

target_link_libraries(covinhas PRIVATE spdlog::spdlog  ${UNICORN_LINK_LIBRARIES} LIEF::LIEF )
