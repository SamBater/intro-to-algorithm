cmake_minimum_required(VERSION 3.0)
project(algorithm)
set(CMAKE_CXX_STANDARD 11)

add_library(COMMONLIB common/common.cpp)
link_libraries(COMMONLIB)

include_directories(common)




foreach(CHPATER_INDEX RANGE 2 6 1)
    set(prefix "src/chapter")
    file(GLOB SOURCES
        "${prefix}${CHPATER_INDEX}/*.cpp"
    )

    foreach(SRC ${SOURCES})
        get_filename_component(loc ${SRC} NAME_WLE)
        
        add_executable(${loc} ${SRC})
    endforeach(SRC)
    
endforeach(CHPATER_INDEX)



