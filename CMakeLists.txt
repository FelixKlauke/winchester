cmake_minimum_required(VERSION 3.9)
project(winchester)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(winchester main.cpp src/DFA.cpp include/DFA.h src/State.cpp include/State.h src/Transition.cpp include/Transition.h src/PDA.cpp include/PDA.h src/PDAStack.cpp include/PDAStack.h)
