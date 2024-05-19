cmake_minimum_required(VERSION 3.22.1)

project(MyDWMStatus)

file(GLOB SRC src/*.cpp)

add_executable(main ${SRC})
target_link_libraries(main X11)