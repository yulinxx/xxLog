find_package(log4cplus CONFIG REQUIRED)
 
if (log4cplus_FOUND)
    MESSAGE("----------log4cplus FOUND")
    message(${CMAKE_CURRENT_BINARY_DIR})
    message("log4cplus_INCLUDE_DIR: ${log4cplus_INCLUDE_DIR}\n")
    message("log4cplus_LIBRARIES: ${log4cplus_LIBRARIES}\n")
    message("log4cplus_LIBRARY_DEBUG: ${log4cplus_LIBRARY_DEBUG}\n")

    INCLUDE_DIRECTORIES(${log4cplus_INCLUDE_DIR})
else (log4cplus_FOUND)
    MESSAGE(FATAL_ERROR "log4cplus NOT FOUND")
endif (log4cplus_FOUND)

aux_source_directory(./src DIR_SRCS)

add_library(rdLog ${DIR_SRCS})

target_include_directories(rdLog PRIVATE ./include)

target_link_libraries(rdLog PRIVATE log4cplus::log4cplus)

file(COPY ./res/log.properties  DESTINATION ${EXECUTABLE_OUTPUT_PATH})