# Set minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Set Project Name and language used
project(empty LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Google Testing Environment
####################################### Start
add_definitions(-DGTEST_LANGUAGE_CXX11)

find_package(Threads REQUIRED)
include(GoogleTest)

if ($ENV{GOOGLETEST_DIR})
    set(GOOGLETEST_DIR $ENV{GOOGLETEST_DIR})
else ()
    if (NOT ${CMAKE_CURRENT_SOURCE_DIR}/googletest STREQUAL "")
        message(WARNING "Using googletest src dir specified at Qt Creator wizard")
    endif ()
    set(GOOGLETEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/googletest)
endif ()

if (EXISTS ${GOOGLETEST_DIR})
    set(GTestSrc ${GOOGLETEST_DIR}/googletest)
    set(GMockSrc ${GOOGLETEST_DIR}/googlemock)
elseif (UNIX AND EXISTS /usr/src/gtest)
    set(GTestSrc /usr/src/gtest)
    message(WARNING "Using gtest from system")
    if (EXISTS /usr/src/gmock)
        set(GMockSrc /usr/src/gmock)
    endif ()
else ()
    message( FATAL_ERROR "No googletest src dir found - set GOOGLETEST_DIR to enable!")
endif ()

set(GTestFiles ${GTestSrc}/src/gtest-all.cc)
set(GTestIncludes ${GTestSrc} ${GTestSrc}/include)
if (NOT ${GMockSrc} STREQUAL "")
    list(APPEND GTestFiles ${GMockSrc}/src/gmock-all.cc)
    list(APPEND GTestIncludes ${GMockSrc} ${GMockSrc}/include)
endif ()

include_directories(${GTestIncludes})
####################################### End

# Add source code
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
list(APPEND source_code ${CMAKE_CURRENT_SOURCE_DIR}/src/EmptyClass.cpp)
list(APPEND source_code ${CMAKE_CURRENT_SOURCE_DIR}/src/EmptyClass.hpp)

# Add Unit Tests code
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/test)
list(APPEND test_code ${CMAKE_CURRENT_SOURCE_DIR}/test/test_emptyclass.hpp)

# Add Eigen Library
include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/eigen/include)

# Build executable
add_executable(${PROJECT_NAME} main.cpp ${source_code} ${test_code} ${GTestFiles})

# Set Unit Tests
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)
gtest_discover_tests(${PROJECT_NAME})

