cmake_minimum_required(VERSION 2.8)

project(face_detection)

set(PYBIND11_CPP_STANDARD -std=c++11)
set(CMAKE_CXX_FLAGS "-O3 -Wall -DPIC -fPIC")
add_subdirectory(pybind11)

# hello.cppとgood_morning.cppをコンパイルして共有ライブラリlibgreetings.soを作成
pybind11_add_module(face_detection SHARED face_detection.cpp

add_executable(a.out face_detection.cpp)
# a.outを作成する際にlibgreetings.soをリンク
target_link_libraries(a.out greetings)
