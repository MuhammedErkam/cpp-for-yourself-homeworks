cmake_minimum_required(VERSION 3.16..3.24)
project(no_strings_attached VERSION 0.0.1 
                            DESCRIPTION "Trying Split And Trim Strings And Test It Using GoogleTest" 
                            LANGUAGES CXX)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

add_library(cxx_setup INTERFACE)
target_compile_options(cxx_setup
  INTERFACE -Wall -Wpedantic -Wextra)
target_compile_features(cxx_setup INTERFACE cxx_std_17)
target_include_directories(cxx_setup
  INTERFACE ${PROJECT_SOURCE_DIR})

include(CTest)
# 🚨 Make sure CMakeLists.txt file exists in the subdirectories!
add_subdirectory(${PROJECT_NAME})
add_subdirectory(external)
add_subdirectory(examples)

# 💡 Some things (e.g. tests or installation) are missing here.
# 💡 Stay tuned for these in future lectures!