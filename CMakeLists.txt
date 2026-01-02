cmake_minimum_required(VERSION 4.1)
project(cmake_testapp C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

enable_language(C ASM)

#set(MAIN_FILE main.c)
#add_executable(cmake_testapp
#        src/main.c
#        general.c)
#add_library(cmake_testapp_lib STATIC calc_lib.c calc_lib.h)
#
#target_include_directories (cmake_testapp_lib PUBLIC includes/math)
#target_include_directories (cmake_testapp_lib PUBLIC includes/general)
#
#find_library(TEST_LIBRARY cmake_testapp_lib lib)
#target_link_libraries(cmake_testapp LINK_PUBLIC ${TEST_LIBRARY})

add_subdirectory(external)
add_subdirectory(src)

enable_testing() # this will include(CTest)
add_subdirectory(ctest)