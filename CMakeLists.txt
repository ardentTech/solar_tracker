cmake_minimum_required(VERSION 4.1)
project(solar_tracker C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

enable_language(C ASM)

#set(MAIN_FILE main.c)
#add_executable(solar_tracker
#        src/main.c
#        general.c)
#add_library(solar_tracker_lib STATIC calc_lib.c calc_lib.h)
#
#target_include_directories (solar_tracker_lib PUBLIC includes/math)
#target_include_directories (solar_tracker_lib PUBLIC includes/general)
#
#find_library(TEST_LIBRARY solar_tracker_lib lib)
#target_link_libraries(solar_tracker LINK_PUBLIC ${TEST_LIBRARY})
add_subdirectory(external)
if(CMAKE_BUILD_TYPE STREQUAL "Test")
    enable_testing() # this will include(CTest)
    add_subdirectory(ctest)
else()
    add_subdirectory(src)
endif()