cmake_minimum_required(VERSION 3.20)
project(NYASH C)

set(CMAKE_C_STANDARD 11)

add_executable(NYASH
        main.c
        processor/init.c
        processor/init.h
        processor/prompt.c
        processor/prompt.h utils/parse.c utils/parse.h commands/pwd.c commands/pwd.h utils/tokenize.c utils/tokenize.h utils/vector.c utils/vector.h commands/echo.c commands/echo.h commands/cd.c commands/cd.h commands/ls.c commands/ls.h processor/sysCommands.c processor/sysCommands.h commands/pinfo.c commands/pinfo.h commands/repeat.c commands/repeat.h commands/history.c commands/history.h utils/list.c utils/list.h processor/child_handler.c processor/child_handler.h utils/job_list.c utils/job_list.h utils/colours.h commands/jobs.c commands/jobs.h commands/sig.c commands/sig.h commands/fg.c commands/fg.h commands/bg.c commands/bg.h commands/replay.c commands/replay.h commands/baywatch.c commands/baywatch.h)
