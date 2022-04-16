# read the fetched location
FetchContent_GetProperties(cppwinrt_nuget)
if(NOT cppwinrt_nuget_POPULATED)
    message(FATAL_ERROR "cppwinrt_nuget not found")
endif()

# setup module infra
message(STATUS "Fetching cmake module tool")
include(FetchContent)
FetchContent_Declare(cmake_cxx_modules
  GIT_REPOSITORY https://github.com/cpp-openapi/CMakeCxxModules.git
  GIT_TAG b2a646229cff3c9f0ce85f10648d4c57de2b2411)
FetchContent_GetProperties(cmake_cxx_modules)
if(NOT cmake_cxx_modules_POPULATED)
    FetchContent_Populate(cmake_cxx_modules)
    list(APPEND CMAKE_MODULE_PATH ${cmake_cxx_modules_SOURCE_DIR})
    include(CXXModules)
endif()

add_compile_options(/bigobj)
add_module_library(cppwinrt_module
    ${cppwinrt_nuget_BINARY_DIR}/include/winrt/winrt.ixx 
)

target_include_directories(cppwinrt_module PUBLIC "${cppwinrt_nuget_BINARY_DIR}/include")
