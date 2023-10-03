# Information cmake
cmake_minimum_required(VERSION 3.0.2)

# Information projec
project(covinhas VERSION 0.1 LANGUAGES CXX)
set(LIB_MAJOR_VERSION "0")
set(LIB_MINOR_VERSION "1")
set(LIB_PATCH_VERSION "0")


# Information for builds
set(FLAGS_DEBUG OFF )
set(BUILD_TESTS ON )
set(BUILD_BENCHMARK OFF )
set(FLAGS_OPTIMIZATIONS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)

# add subdirectory
add_subdirectory( sources/ )
if(BUILD_TESTS)
	add_subdirectory( tests/ )
endif()
if(BUILD_BENCHMARK)
	add_subdirectory( benchmark/ )
endif()

# set flags
set(CMAKE_CXX_FLAGS "-O2 -Os") # default flags

if(FLAGS_OPTIMIZATIONS)
  set(CMAKE_CXX_FLAGS "-ftree-vectorize -mavx -fno-stack-protector -march=native -O2 -Os -fdelete-null-pointer-checks -fdelete-dead-exceptions")
elseif(FLAGS_DEBUG)
  set(CMAKE_CXX_FLAGS "-fsanitize=address -fms-extensions --all-warnings -DDEBUG -g  -O2 -Os  -Wvolatile  -Warray-bounds --extra-warnings")
endif()
