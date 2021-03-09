add_executable(gtest_session_1 test_case.cpp test_fixture.cpp test_with_parameters.cpp)
target_include_directories(gtest_session_1 PRIVATE "../production_code")
target_link_libraries(gtest_session_1 gtest gmock_main)
add_test(NAME gtest_session_1_test COMMAND gtest_session_1)