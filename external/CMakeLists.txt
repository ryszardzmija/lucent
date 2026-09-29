# SDL
set(SDL_TEST_LIBRARY OFF CACHE BOOL "Disable building SDL test library" FORCE)
set(SDL_TESTS OFF CACHE BOOL "Disable SDL tests" FORCE)

set(SDL_AUDIO OFF CACHE BOOL "Disable SDL audio subsystem" FORCE)
set(SDL_GPU OFF CACHE BOOL "Disable SDL GPU subsystem" FORCE)
set(SDL_RENDER OFF CACHE BOOL "Disable SDL rendering subsystem" FORCE)
set(SDL_CAMERA OFF CACHE BOOL "Disable SDL camera subsystem" FORCE)
set(SDL_JOYSTICK OFF CACHE BOOL "Disable SDL joystick subsystem" FORCE)
set(SDL_HAPTIC OFF CACHE BOOL "Disable SDL haptic subsystem" FORCE)
set(SDL_HIDAPI OFF CACHE BOOL "Disable SDL hidapi subsystem" FORCE)
set(SDL_POWER OFF CACHE BOOL "Disable SDL power subsystem" FORCE)
set(SDL_SENSOR OFF CACHE BOOL "Disable SDL sensor subsystem" FORCE)
set(SDL_DIALOG OFF CACHE BOOL "Disable SDL dialog subsystem" FORCE)
set(SDL_TRAY OFF CACHE BOOL "Disable SDL tray subsystem" FORCE)

add_subdirectory(SDL)

add_library(${PROJECT_NAME}_platform_deps INTERFACE)
target_link_libraries(${PROJECT_NAME}_platform_deps INTERFACE SDL3::SDL3)

# GTest
add_subdirectory(googletest)

add_library(${PROJECT_NAME}_testing_deps INTERFACE)
target_link_libraries(${PROJECT_NAME}_testing_deps INTERFACE GTest::gtest_main)
