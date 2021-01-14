cmake_minimum_required(VERSION 3.12)

file(READ ${CMAKE_CURRENT_SOURCE_DIR}/../version HESTIA_VERSION_STR)

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

set_property(GLOBAL
    PROPERTY USE_FOLDERS ON)
set_property(GLOBAL
    PROPERTY PREDEFINED_TARGETS_FOLDER "_other")
set_property(GLOBAL
    PROPERTY CMAKE_CXX_KNOWN_FEATURES cxx_std_17)

add_subdirectory(hestia/base)
add_subdirectory(examples/base)