cmake_minimum_required(VERSION 3.12.4)

set(CMAKE_TOOLCHAIN_FILE D:/Install/vcpkg/scripts/buildsystems/vcpkg.cmake)
# set(VCPKG_TARGET_TRIPLET x64-windows-static)

# set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

project(rdLog VERSION 0.1 LANGUAGES CXX)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

add_subdirectory(xxLog)

add_subdirectory(test)
