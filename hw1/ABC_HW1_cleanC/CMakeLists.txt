cmake_minimum_required(VERSION 3.20)
project(ABC_HW1_cleanC C)

set(CMAKE_C_STANDARD 11)

add_executable(ABC_HW1_cleanC main.c container.c container.h animal.c animal.h fish.c fish.h bird.c bird.h beast.c beast.h)
