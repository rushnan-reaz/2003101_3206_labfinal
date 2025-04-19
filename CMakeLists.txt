cmake_minimum_required(VERSION 3.14)
project(factory_pattern VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include GoogleTest
include_directories(/home/rushnan-reaz/unittest/googletest/googletest/include)

# Main executable
add_executable(factory_demo src/main.cpp)

# Test executable
add_executable(factory_test test/factory_test.cpp)
target_link_libraries(factory_test
    /home/rushnan-reaz/unittest/googletest/build/lib/libgtest.a
    /home/rushnan-reaz/unittest/googletest/build/lib/libgtest_main.a
    pthread)

# Enable testing
enable_testing()
add_test(NAME FactoryTests COMMAND factory_test)