add_executable(${PROJECT_NAME}_tests)
target_sources(${PROJECT_NAME}_tests PRIVATE color_buffer_tests.cpp)
target_link_libraries(${PROJECT_NAME}_tests PRIVATE ${PROJECT_NAME} ${PROJECT_NAME}_testing_deps)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_tests)
