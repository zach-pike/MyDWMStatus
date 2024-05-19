cmake_minimum_required(VERSION 3.22.1)

include_directories(include/)

project(MyDWMStatus)
set(CXX_STANDARD 20)

file(GLOB SRC src/*.cpp)
file(GLOB LIBS libs/*.a)

add_executable(main ${SRC})

target_link_libraries(main X11 ${LIBS})