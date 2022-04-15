file(GLOB SOURCES
    *.cpp
)

foreach(source_file ${SOURCES})
    # strip file extension
    get_filename_component(source_name ${source_file} NAME_WE)
    add_executable(${source_name} ${source_file})

    set_property(TARGET ${source_name} PROPERTY CXX_STANDARD 17)
    target_link_libraries(${source_name} PRIVATE cppwinrt)
endforeach()