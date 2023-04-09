cmake_minimum_required(VERSION 3.24)

project(Stack)

# Build options
option(BUILD_TESTS "Build tests" ON)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Set C standard to C11
set(CMAKE_C_STANDARD 11)

# Enable testing
option(BUILD_TESTS "Enable testing" OFF)

# If BUILD_TESTS is set to ON, add the test subdirectory
if(BUILD_TESTS)
	message("Testing is enabled")
	enable_testing()
endif()

# Add subdirectory for main library
add_subdirectory(main)

# Set library output directory
set(STACK_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Install headers
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/main/inc/ DESTINATION include)

# Install library
if(BUILD_SHARED_LIBS)
    install(TARGETS stack_shared LIBRARY DESTINATION lib)
else()
    install(TARGETS stack_static ARCHIVE DESTINATION lib)
endif()

if(BUILD_TESTS)
    # Add subdirectory for test executable
    add_subdirectory(test)

    # Set test output directory
    set(TEST_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test)

    # Set library path for tests
    set(STACK_LIBRARY_PATH ${STACK_LIBRARY_OUTPUT_DIRECTORY})
endif()



# Display build summary
include(FeatureSummary)
feature_summary(
    WHAT ALL
    INCLUDE_QUIET_PACKAGES
    FATAL_ON_MISSING_REQUIRED_PACKAGES
)
