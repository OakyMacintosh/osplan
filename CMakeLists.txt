cmake_minimum_required(VERSION 3.10)
project(osplan C)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add core sources
add_library(osplan_core
    core/osplan.core.c
)

# Optionally, add parse_yml.c and vrg.c if they exist
if(EXISTS "${CMAKE_SOURCE_DIR}/core/parse_yml.c")
    target_sources(osplan_core PRIVATE core/parse_yml.c)
endif()
if(EXISTS "${CMAKE_SOURCE_DIR}/core/vrg.c")
    target_sources(osplan_core PRIVATE core/vrg.c)
endif()

# Add executable if you have a main file (update as needed)
# add_executable(osplan_exec core/main.c)
# target_link_libraries(osplan_exec PRIVATE osplan_core)

# Include directories
target_include_directories(osplan_core PUBLIC ${CMAKE_SOURCE_DIR}/core)
