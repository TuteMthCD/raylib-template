cmake_minimum_required (VERSION 3.16)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(PRUEBA)

add_executable(hola src/hola.c)
add_executable(ray src/ray.c)

#set(RAYLIB ${CMAKE_SOURCE_DIR}/src/raylib/)

target_link_libraries(ray ${CMAKE_SOURCE_DIR}/src/raylib/libraylib.a)
target_include_directories(ray PRIVATE ${CMAKE_SOURCE_DIR}/src/raylib)
target_link_libraries(ray m)

add_custom_target(ray_exe ALL
    DEPENDS ray
    COMMAND ./ray
    COMMENT "VAMOOOOOOOOOOOOS PAPA COMPILO"
    COMMENT "EJECUTANAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAANDO"
)
