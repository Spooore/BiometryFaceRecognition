cmake_minimum_required(VERSION 2.8)


set (CMAKE_AUTOMOC ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)

PROJECT (FaRe)
find_package(OpenCV REQUIRED )
set( NAME_SRC
    src/Program.cpp
    src/PhotosContainer.cpp
    src/Graph.cpp
)

set( NAME_HEADERS
     include/PhotosContainer.h
     include/Graph.h
)

INCLUDE_DIRECTORIES(  ${OpenCV_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( FaRe ${NAME_SRC} ${NAME_HEADERS} )
message("OpenCV_LIBS=${OpenCV_INCLUDE_DIRS}")

target_link_libraries( FaRe ${OpenCV_LIBS} ${catkin_LIBRARIES})
