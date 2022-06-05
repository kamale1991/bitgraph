cmake_minimum_required(VERSION 3.16.0)
project(bitgraph VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/lib)

enable_testing()

# GoogleTest
include(GoogleTest)
include(CTest)
include_directories(/usr/src)
find_package(GTest REQUIRED)

# OpenMP
find_package(OpenMP REQUIRED)
#target_link_libraries(mptest PUBLIC OpenMP::OpenMP_CXX)

# MPI
find_package(MPI REQUIRED)

# MKL
include_directories(/opt/intel/mkl/include)

# OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})    

# Python
include_directories(/usr/include/python3.8)

# scan sub directory
add_subdirectory(srcs)
add_subdirectory(tests)

## PROJECT_NAMEと同じ名前の実行体にmain.cppをリンクする
add_executable(${PROJECT_NAME} 
    main.cpp    
    )
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
target_link_libraries(${PROJECT_NAME} 
    MPI::MPI_CXX
    ${OpenCV_LIBRARIES}
    )