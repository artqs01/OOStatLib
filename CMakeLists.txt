project(statlib)
cmake_minimum_required(VERSION 3.3)
# -fsanitize=address -fsanitize=undefined -fno-builtin -fno-omit-frame-pointer
# set (CMAKE_GENERATOR "Unix Makefiles")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -march=native -O3 -ffast-math -ftree-vectorize")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_executable(statlib
	"${PROJECT_SOURCE_DIR}/src/main.cpp"
)

target_link_libraries(statlib PRIVATE m)
target_include_directories(statlib PRIVATE "${PROJECT_SOURCE_DIR}/src")
