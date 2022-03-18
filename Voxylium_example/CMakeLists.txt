cmake_minimum_required(VERSION 3.21)
project(Voxylium_example)

set(CMAKE_CXX_STANDARD 23)

# add source files to executable
set(SOURCE_FILES main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# append cmake module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

# link to voxylium library
find_package(Voxylium REQUIRED)
include_directories(${VOXYLIUM_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${VOXYLIUM_LIBRARY})

# link to GLFW library
find_package(GLFW REQUIRED)
include_directories(${GLFW_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${GLFW_LIBRARY})

# link to vulkan library (configured for windows (VK_USE_PLATFORM_WIN32_KHR) needs to be changed if not on windows !!!
find_package(Vulkan REQUIRED)
target_compile_definitions(${PROJECT_NAME} PRIVATE VK_USE_PLATFORM_WIN32_KHR)
target_include_directories(${PROJECT_NAME} PRIVATE Vulkan::Vulkan)
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)