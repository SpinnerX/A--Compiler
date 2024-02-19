cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME A-Compiler)
set(CMAKE_CXX_STANDARD 20)
# add_compile_options(-fsanitize=address)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "") # works (in creating the compile_commands.json file)

project(${PROJECT_NAME})

set(
	all_src
	src/main.cc
	src/tokenizer/token.cc
	src/parser/parserTree.cc
)

add_executable(${PROJECT_NAME} ${all_src})

target_include_directories(
	${PROJECT_NAME}
	PUBLIC
	include/
	include/tokenizer
)
