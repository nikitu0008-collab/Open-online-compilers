cmake_minimum_required(VERSION 3.15)
project(OnlineCompilerFinder VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(CURL REQUIRED)
if(NOT CURL_FOUND)
    message(FATAL_ERROR "libcurl не найден. Установите его: MSYS2: pacman -S mingw-w64-ucrt-x86_64-curl, Linux: sudo apt install libcurl4-openssl-dev, macOS: brew install curl")
endif()

add_executable(online_compiler_finder startOnlineCompiler.cpp)

target_link_libraries(online_compiler_finder PRIVATE CURL::libcurl)

if(WIN32)
    target_link_libraries(online_compiler_finder PRIVATE shell32)
endif()

set_target_properties(online_compiler_finder PROPERTIES
    VERSION ${PROJECT_VERSION}
    OUTPUT_NAME "ocf"
)
