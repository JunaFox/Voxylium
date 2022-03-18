# paths may need to be changed depending on the setup
set(FIND_VOXYLIUM_PATHS ../Voxylium)

find_path(VOXYLIUM_INCLUDE_DIR voxylium.h
        PATHS ${FIND_VOXYLIUM_PATHS})

find_library(VOXYLIUM_LIBRARY
             NAMES libVoxylium
             PATHS ${FIND_VOXYLIUM_PATHS}/cmake-build-release)