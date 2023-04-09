#!/bin/bash

# Default values
BUILD_ALL=false
BUILD_TYPE="static"
RUN_TESTS=false
CLEAN=false
INSTALL_BUILD=false

# Print help message
function print_help() {
  echo "Usage: $0 [OPTIONS]"
  echo ""
  echo "Options:"
  echo "  -s, --static       Build static library (default)"
  echo "  -S, --shared       Build shared library"
  echo "  -a, --all          Build library and run tests"
  echo "  -t, --test         Run tests with pre-built library"
  echo "  -c, --clean        Clean build directory"
  echo "  -h, --help         Print this help message"
  echo "  -i, --install      Install the library"
  echo
  echo "INSTALL_DIR is optional, defaults to /usr/local"
}

# Parse command-line arguments
while [[ $# -gt 0 ]]; do
  case "$1" in
    -s|--static)
      BUILD_TYPE="static"
      shift
      ;;
    -S|--shared)
      BUILD_TYPE="shared"
      shift
      ;;
    -a|--all)
      BUILD_ALL=true
      shift
      ;;
    -t|--test)
      RUN_TESTS=true
      shift
      ;;
    -c|--clean)
      CLEAN=true
      shift
      ;;
    -h|--help)
      print_help
      exit 0
      ;;
    -i|--install)
      INSTALL_BUILD=true
      shift
      ;;
    *)
      echo "Error: Unrecognized option: $1"
      echo ""
      print_help
      exit 1
      ;;
  esac
done

# Echo build options
echo "Build options:"
echo "  CLEAN: $CLEAN"
echo "  TYPE: $BUILD_TYPE"
echo "  ALL: $BUILD_ALL"
echo "  TEST: $RUN_TESTS"
echo "  INSTALL: $INSTALL_BUILD"
echo ""


# Clean build directory
if $CLEAN; then
  rm -rf build
fi

# Build library
if $BUILD_ALL; then
  mkdir -p build
  cd build
  if [ "$BUILD_TYPE" == "static" ]; then
    cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DBUILD_SHARED_STACK_LIBS=OFF -DBUILD_TESTS=OFF ..
    cmake --build . --target=stack_static
  else
    cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DBUILD_SHARED_STACK_LIBS=ON -DBUILD_TESTS=OFF ..
    cmake --build . --target=stack_shared
  fi
  lcov --directory . --capture --output-file coverage.info
  genhtml coverage.info --output-directory coverage_report
  echo "Coverage report generated at $(realpath coverage_report/index.html)"
fi

if $RUN_TESTS; then
  # Check if library exists
  if [ "$BUILD_TYPE" == "static" ]; then
    if [ ! -f "build/main/libstack_static.a" ]; then
      echo "Error: Static library not found, please build the library first"
      exit 1
    fi
  else
    if [ ! -f "build/main/libstack_shared.so" ]; then
      echo "Error: Shared library not found, please build the library first"
      exit 1
    fi
  fi

  mkdir -p build && cd build

  if [ "$BUILD_TYPE" == "static" ]; then
    cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DBUILD_SHARED_STACK_LIBS=OFF -DBUILD_TESTS=ON ..
  else
    cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DBUILD_SHARED_STACK_LIBS=ON -DBUILD_TESTS=ON ..
  fi

  cmake --build . --target=StackTest
  
  # Run tests and generate coverage report
  ctest --verbose --output-on-failure

  if [ "$BUILD_TYPE" == "static" ]; then
    gcov -o CMakeFiles/stack_static.dir/src main/src/stack.c --object-directory build/CMakeFiles/stack_static.dir/src
  else
    gcov -o CMakeFiles/stack_static.dir/src main/src/stack.c --object-directory build/CMakeFiles/stack_shared.dir/src
  fi

  gcov -o CMakeFiles/StackTest.dir test/tests.cpp --object-directory build/test
  lcov --directory . --capture --output-file coverage.info
  genhtml coverage.info --output-directory coverage_report
  echo "Coverage report generated at $(realpath coverage_report/index.html)"
  cd ..
fi

# Install library and headers
if $INSTALL_BUILD; then
  cmake --install .
fi