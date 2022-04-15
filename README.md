# cppwinrt-cmake
build winrt in cmake

winrt repo `https://github.com/microsoft/cppwinrt`

# Usage
```cmake
include(FetchContent)
FetchContent_Declare(cppwinrt_cmake
    GIT_REPOSITORY https://github.com/cpp-openapi/cppwinrt-cmake.git
    GIT_TAG <main>
)
FetchContent_GetProperties(cppwinrt_cmake)
if(NOT cppwinrt_cmake_POPULATED)
   add_subdirectory(${cppwinrt_cmake_SOURCE_DIR} ${cppwinrt_cmake_BINARY_DIR} EXCLUDE_FROM_ALL) 
endif()
```

# Info
winrt is shipped in windows sdk and in nuget.
The lib in windows sdk is old and some features and bug fixes are missing.
This project defines cmake targets to fetch winrt from nuget and expose it as a cmake target to be linked against.

# TODO
* Use cpp modules.