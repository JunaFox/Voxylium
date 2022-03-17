# needs environment variable called GLFW to glfw path
find_path(GLFW_INCLUDE_DIR GLFW/glfw3.h
        PATH_SUFFIXES include
        PATHS $ENV{GLFW})

find_library(GLFW_LIBRARY
        NAMES glfw3
        PATH_SUFFIXES lib
        PATHS $ENV{GLFW})