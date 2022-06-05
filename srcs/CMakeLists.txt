cmake_minimum_required(VERSION 3.16.0)

# add_subdirectoryでそれぞれのプロジェクトディレクトリの共有ライブラリを作成する
file(GLOB dir_list LIST_DIRECTORIES true RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ./*)
list(FILTER dir_list EXCLUDE REGEX "^(.gitignore|.vscode|.*.txt|.*.cpp|.*.md|build|test|docs|figures|.*.png|.*.jpg|opencv_sample)$")
foreach(dir ${dir_list})       
    message("add subdirectory "${dir}) 
    add_subdirectory(${dir})
endforeach()


foreach(dir ${dir_list})
    set(DIR_MAIN ${dir}_main)
    add_executable(${DIR_MAIN} ${DIR_MAIN}.cpp)
    target_link_libraries(${DIR_MAIN}
        ${dir_list}
        ${OpenCV_LIBRARIES}    
    )
endforeach()

set(DIR_MAIN ${DIR_NAME}_main)

