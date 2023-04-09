cmake_minimum_required(VERSION 3.24)

project(StackTest)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

option(BUILD_SHARED_STACK_LIBS "Build shared libraries" OFF)

# Use FetchContent to download and include Google Test
include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG        release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add test executable
add_executable(StackTest
	tests.cpp
	main.cpp
)

# Link test executable with Google Test and your project's libraries
if(BUILD_SHARED_STACK_LIBS)
	target_link_libraries(StackTest
		gtest_main
		stack_shared
	)
else()
	target_link_libraries(StackTest
		gtest_main
		stack_static
	)
endif()

target_compile_options(StackTest PRIVATE -fprofile-arcs -ftest-coverage)

# Add include directories for your project and Google Test
target_include_directories(StackTest
	PRIVATE
	${CMAKE_SOURCE_DIR}/inc
	${CMAKE_SOURCE_DIR}/test
	${gtest_SOURCE_DIR}/include
)

# Set library path for linking
link_directories(${STACK_LIBRARY_PATH})

# Discover tests
include(GoogleTest)
gtest_discover_tests(StackTest)
