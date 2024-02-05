cmake_minimum_required(VERSION 3.26)
project(GR1_Ece_music C)

set(CMAKE_C_STANDARD 11)

add_executable(GR1_Ece_music main.c
        music.c
        music.h)
