
# add_executable(rdLog main.cpp)
aux_source_directory(. DIR_SRCS)

add_executable(rdLogTest ${DIR_SRCS})

target_include_directories(rdLogTest PRIVATE ../xxLog/include)

# target_link_directories(rdLogTest PRIVATE ../xxLog/include)

target_link_libraries(rdLogTest PRIVATE rdLog)
