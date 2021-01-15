file(GLOB_RECURSE
    HEADER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)

file(GLOB_RECURSE
    SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

list(APPEND
    SRC_FILES
    ${HEADER_FILES} ${SOURCE_FILES})

message(STATUS "build target : HestiaBase")

foreach(filename ${SRC_FILES})
    DIR_SOURCE_GROUP(${filename} ${CMAKE_CURRENT_SOURCE_DIR})
endforeach()

add_library(HestiaBase
    STATIC
    ${SRC_FILES})

set_target_properties(HestiaBase
    PROPERTIES FOLDER "code")

target_include_directories(HestiaBase
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../..)