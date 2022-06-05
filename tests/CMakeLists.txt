cmake_minimum_required(VERSION 3.16.0)

# testについてファイル名の取得
file(GLOB_RECURSE test_srcs
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "*.cpp"
)

foreach(test_src ${test_srcs})
    get_filename_component(test_filename ${test_src} NAME_WE)
    set(test_exe test_${test_filename})
    add_executable(${test_exe} ${test_src})    
    #target_include_directories(${test_exe} PRIVATE ${OpenCV_INCLUDE_DIRS})    
    target_link_libraries(${test_exe} PRIVATE
        gtest
        gtest_main
        pthread
        python3.8                
        automaton
        ${OpenCV_LIBRARIES}            
    )    
    add_test(test ${test_exe})
endforeach()
