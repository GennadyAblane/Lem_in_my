cmake_minimum_required(VERSION 3.17)
project(Lem_in_my C)

set(CMAKE_C_STANDARD 90)

add_executable(Lem_in_my src/main.c inc/lem_in.h src/ft_free.c src/ft_parsing.c src/print_result.c src/init.c src/find_solutions.c src/terminate.c src/bilst_length_cmp.c)

target_include_directories(Lem_in_my PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_include_directories(Lem_in_my PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(Lem_in_my PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib/Libft/inc)
set(FT ${CMAKE_CURRENT_SOURCE_DIR}/lib/Libft/libft.a)
target_link_libraries(Lem_in_my ${FT})

target_include_directories(Lem_in_my PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib/Libftprintf/inc)
set(FT_Printf ${CMAKE_CURRENT_SOURCE_DIR}/lib/Libftprintf/libftprintf.a)
target_link_libraries(Lem_in_my ${FT_Printf})