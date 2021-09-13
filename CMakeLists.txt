cmake_minimum_required(VERSION 3.20)
project(NYASH C)

set(CMAKE_C_STANDARD 11)

add_executable(NYASH
        main.c
        processor/init.c
        processor/init.h
        processor/prompt.c
        processor/prompt.h utils/parse.c utils/parse.h commands/pwd.c commands/pwd.h utils/tokenize.c utils/tokenize.h utils/lists.c utils/lists.h)
