cmake_minimum_required(VERSION 3.22.1)

project(git)

set(SOURCES candle.cpp)

# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )
# FetchContent_MakeAvailable(googletest)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(TEST_SOURCES tests.cpp main.cpp)
add_executable(${PROJECT_NAME}_tests ${TEST_SOURCES} ${SOURCES})

target_link_libraries(${PROJECT_NAME}_tests GTest::GTest GTest::Main)

gtest_discover_tests(${PROJECT_NAME}_tests)

enable_testing()

add_test(NAME CandleTests COMMAND ${PROJECT_NAME}_tests)