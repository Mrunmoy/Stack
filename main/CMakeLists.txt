
project(StackLibrary)

set(CMAKE_C_STANDARD 11)

add_compile_options(-Wall -Wextra -Werror -fprofile-arcs -ftest-coverage)

# Add the source files
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/stack.c
)

# Add the header files
set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/stack.h
)

# Create the library target
option(BUILD_SHARED_STACK_LIBS "Build shared libraries" OFF)
if(BUILD_SHARED_STACK_LIBS)
  add_library(stack_shared SHARED ${SOURCES} ${HEADERS})
  target_include_directories(stack_shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
  target_link_libraries(stack_shared gcov)
  install(TARGETS stack_shared LIBRARY DESTINATION lib)
else()
  add_library(stack_static STATIC ${SOURCES} ${HEADERS})
  target_include_directories(stack_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
  target_link_libraries(stack_static gcov)
  install(TARGETS stack_static ARCHIVE DESTINATION lib)
endif() 

# Copy header files to build/include directory
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/inc/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/include)
