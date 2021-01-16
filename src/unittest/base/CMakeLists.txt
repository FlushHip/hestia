add_executable(HestiaBaseTest
    string_unittest.cpp)

target_link_libraries(HestiaBaseTest
    HestiaBase
    gtest_main)

set_target_properties(HestiaBaseTest
    PROPERTIES FOLDER "unittests")

add_test(NAME HestiaBaseTest
    COMMAND HestiaBaseTest)