# cmake_minimum_required(VERSION 3.12.4)


# set(CMAKE_TOOLCHAIN_FILE D:/Install/vcpkg/scripts/buildsystems/vcpkg.cmake)

# project(rdLog VERSION 0.1 LANGUAGES CXX)

# set (CMAKE_CXX_STANDARD 17) 
# # set (CMAKE_CXX_STANDARD 11)

# message(" --------------------------- ")
# add_executable(rdLog main.cpp)

# find_package(log4cplus REQUIRED)

# if(log4cplus_FOUND)
# 	message("FFFFFFFFFFFFFF")
#     MESSAGE(STATUS ${log4cplus_INCLUDE_DIRS})
# 	include_directories(${log4cplus_INCLUDE_DIRS})

# 	MESSAGE(STATUS ${log4cplus2_LIBRARIES})
# 	target_link_libraries(rdLog ${log4cplus2_LIBRARIES})
# endif(log4cplus_FOUND)


# message(" 1111 -------------------------- ")
# # target_link_libraries(rdLog log4cplusD)
# target_link_libraries(rdLog PRIVATE log4cplus::log4cplusD)

# message(" 2222-------------------------- ")



cmake_minimum_required(VERSION 3.12.4)

set(CMAKE_TOOLCHAIN_FILE D:/Install/vcpkg/scripts/buildsystems/vcpkg.cmake)
# set(VCPKG_TARGET_TRIPLET x64-windows-static)

# set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

project(rdLog VERSION 0.1 LANGUAGES CXX)
# set (CMAKE_CXX_STANDARD 17)

# find_package(log4cplus CONFIG REQUIRED)
find_package(log4cplus CONFIG REQUIRED)
 
if (log4cplus_FOUND)
    MESSAGE("----------log4cplus FOUND")
    # message(${log4cplus_INCLUDE_DIRS})
    message(${CMAKE_CURRENT_BINARY_DIR})
    message("log4cplus_INCLUDE_DIR: ${log4cplus_INCLUDE_DIR}\n")
    message("log4cplus_LIBRARIES: ${log4cplus_LIBRARIES}\n")
    message("log4cplus_LIBRARY_DEBUG: ${log4cplus_LIBRARY_DEBUG}\n")

    INCLUDE_DIRECTORIES(${log4cplus_INCLUDE_DIR})
else (log4cplus_FOUND)
    MESSAGE(FATAL_ERROR "log4cplus NOT FOUND")
endif (log4cplus_FOUND)


# add_executable(rdLog main.cpp)
aux_source_directory(. DIR_SRCS)

add_executable(rdLog ${DIR_SRCS})

target_include_directories(rdLog PRIVATE .)

# target_link_libraries(rdLog PRIVATE log4cplus::log4cplusSU)
# target_link_libraries(rdLog PRIVATE log4cplus::log4cplusD)
target_link_libraries(rdLog PRIVATE log4cplus::log4cplus)

file(COPY ./log.properties  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)