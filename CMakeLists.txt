# winrt cmake reference https://github.com/microsoft/cppwinrt/issues/1080
cmake_minimum_required(VERSION 3.14)

project(cppwinrt-cmake)

set(OPENAPI_MAIN_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(OPENAPI_MAIN_PROJECT ON)
endif()

option(OPENAPI_BuildExamples  "Build examples"                                      ${OPENAPI_MAIN_PROJECT})
option(OPENAPI_UseCXXModules  "Use CXX modules"                                      ${OPENAPI_MAIN_PROJECT})

if(NOT WIN32)
    message(FATAL_ERROR "Only Windows is supported.")
endif()

message(STATUS "Fetching winrt nuget")
include(FetchContent)
FetchContent_Declare(cppwinrt_nuget
  URL "https://github.com/microsoft/cppwinrt/releases/download/2.0.220131.2/Microsoft.Windows.CppWinRT.2.0.220131.2.nupkg"
  URL_HASH "SHA256=899c1c676c72404aea4c07ebd7e3314c245867f95918c79fc122642df85e168c"
)
FetchContent_GetProperties(cppwinrt_nuget)
if(NOT cppwinrt_nuget_POPULATED)
  message(STATUS "Configuring winrt nuget")
  FetchContent_Populate(cppwinrt_nuget)
  # install winrt in the bin dir by running the install cmd. This should be optimized/skipped when already installed. TODO:
  execute_process(
    COMMAND ${cppwinrt_nuget_SOURCE_DIR}/bin/cppwinrt.exe -in local -output ${cppwinrt_nuget_BINARY_DIR}/include
    COMMAND_ECHO STDOUT
    COMMAND_ERROR_IS_FATAL ANY
  )
endif()

add_library(cppwinrt INTERFACE)

target_link_libraries(cppwinrt INTERFACE WindowsApp.lib)

target_include_directories(cppwinrt INTERFACE "${cppwinrt_nuget_BINARY_DIR}/include")

if(OPENAPI_BuildExamples)
    add_subdirectory(examples)
endif()

if(OPENAPI_UseCXXModules)
    add_subdirectory(modules)
    add_subdirectory(modules-examples)
endif()