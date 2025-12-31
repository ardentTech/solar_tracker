cmake_minimum_required(VERSION 4.1)
project(cmake_testapp C)

set(CMAKE_C_STANDARD 23)

set(MAIN_FILE main.c)
add_executable(cmake_testapp
        ${MAIN_FILE}
        general.c)
add_executable(cmake_testapp_calc calc.c)
add_library(cmake_testapp_lib STATIC calc_lib.c calc_lib.h)

target_include_directories (cmake_testapp_lib PUBLIC includes/math)
target_include_directories (cmake_testapp_lib PUBLIC includes/general)

find_library(TEST_LIBRARY cmake_testapp_lib lib)
target_link_libraries(cmake_testapp LINK_PUBLIC ${TEST_LIBRARY})

enable_testing()
add_subdirectory(ctest)