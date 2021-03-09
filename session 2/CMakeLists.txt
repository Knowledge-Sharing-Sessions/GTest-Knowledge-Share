add_executable(gtest_session_2 mock.cpp databasereadermock.h randomnumbergeneratormock.h)
target_include_directories(gtest_session_2 PRIVATE "../production_code")
target_link_libraries(gtest_session_2 gtest gmock_main)
add_test(NAME gtest_session_2_test COMMAND gtest_session_3)