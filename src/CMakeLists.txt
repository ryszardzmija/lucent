add_library(${PROJECT_NAME} STATIC)
target_sources(${PROJECT_NAME} PRIVATE color_buffer.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME}_app)
target_sources(${PROJECT_NAME}_app PRIVATE main.cpp)
target_link_libraries(${PROJECT_NAME}_app PRIVATE ${PROJECT_NAME} ${PROJECT_NAME}_platform_deps)
