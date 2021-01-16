cmake_minimum_required(VERSION 3.12)

file(READ ${CMAKE_CURRENT_SOURCE_DIR}/../version HESTIA_VERSION_STR)

# project info
project(hestia
    LANGUAGES C CXX
    VERSION ${HESTIA_VERSION_STR}
    DESCRIPTION "client framework"
    HOMEPAGE_URL "https://github.com/FlushHip/hestia")

message(STATUS
    "build hestia info"
    "\n\tversion: ${CMAKE_PROJECT_VERSION}"
    "\n\tdescription: ${CMAKE_PROJECT_DESCRIPTION}"
    "\n\thomepage: ${CMAKE_PROJECT_HOMEPAGE_URL}")

# include googletest
configure_file(googletest.cmake googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if(result)
    message(FATAL_ERROR "CMake step for googletest failed, result : ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if(result)
    message(FATAL_ERROR "build googletest failed, result : ${result}")
endif()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
    ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
    EXCLUDE_FROM_ALL)

# project setting
set_property(GLOBAL
    PROPERTY USE_FOLDERS ON)
set_property(GLOBAL
    PROPERTY PREDEFINED_TARGETS_FOLDER "_other")
set_property(GLOBAL
    PROPERTY CMAKE_CXX_KNOWN_FEATURES cxx_std_17)

if(WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

enable_testing()

# util macro
macro(DIR_SOURCE_GROUP filename base)
    get_filename_component(DIR ${filename} DIRECTORY)
    if (${base} STREQUAL ${DIR})
        source_group("" FILES ${filename})
    else()
        string(REPLACE "${base}/" "" DIR ${DIR})
        source_group("${DIR}" FILES ${filename})
        message("\tdir_source_group base : ${DIR} | file : ${filename}")
    endif()
endmacro()

# subdirectory
add_subdirectory(hestia/base)
add_subdirectory(examples/base)
add_subdirectory(unittest/base)