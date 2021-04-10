# TODO: Add tests and install targets if needed.
cmake_minimum_required (VERSION 3.15)

project ("order_form")

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
    add_compile_options (/permissive-)
endif ()

add_executable(order_form)

add_subdirectory (include)
add_subdirectory (src)
