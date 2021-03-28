cmake_minimum_required(VERSION 3.10)

project(intersectors2D LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11) 
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

set(include_eigen ${CMAKE_CURRENT_SOURCE_DIR}/eigen/include)

include_directories(${include_eigen})

add_executable(intersectors2D main.cpp test_intersector2D2D.h test_intersector2D1D.h Intersector2D1D.h Intersector2D1D.cpp Intersector2D2D.h Intersector2D2D.cpp   ${GTestFiles})

target_link_libraries(intersectors2D PRIVATE Threads::Threads)

gtest_discover_tests(intersectors2D)

