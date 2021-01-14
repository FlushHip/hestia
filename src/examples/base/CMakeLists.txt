add_executable(HestiaHello
    ${CMAKE_CURRENT_SOURCE_DIR}/example.cpp)

target_link_libraries(HestiaHello HestiaBase)

set_target_properties(HestiaHello
    PROPERTIES FOLDER "examples")