add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.cpp color_buffer.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_platform)
