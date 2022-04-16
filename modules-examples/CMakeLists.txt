file(GLOB SOURCES
    *.ixx
)

FetchContent_GetProperties(cmake_cxx_modules)
if(NOT cmake_cxx_modules_POPULATED)
    message(FATAL_ERROR "cmake_cxx_modules not fetched")
endif()
list(APPEND CMAKE_MODULE_PATH ${cmake_cxx_modules_SOURCE_DIR})
include(CXXModules)

foreach(source_file ${SOURCES})
    # strip file extension
    get_filename_component(source_name ${source_file} NAME_WE)
    set(_exe_name ${source_name}_mod)
    add_module_executable(${_exe_name} ${source_file})
    #set_property(TARGET ${source_name} PROPERTY CXX_STANDARD 17)
    target_link_module_libraries(${_exe_name} cppwinrt_module)
endforeach()