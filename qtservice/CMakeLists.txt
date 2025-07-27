cmake_minimum_required(VERSION 3.10)

project(qtservice)

# 设置头文件
set(HEADERS
    src/qtservice.h
    src/qtservice_p.h
)
# 设置源文件
set(SOURCES
    src/qtservice.cpp
)

if (WIN32)
    # 查找包
    find_package(Qt6 REQUIRED COMPONENTS Core)

    # 添加 Win32 特有源文件
    list(APPEND SOURCES src/qtservice_win.cpp)
endif()


if (UNIX)

endif()


# 创建动态库
add_library(QtServiceShared SHARED ${SOURCES} ${HEADERS})
# 创建静态库
add_library(QtServiceStatic STATIC ${SOURCES} ${HEADERS})


# 设置包含路径
target_include_directories(QtServiceShared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(QtServiceStatic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# 链接 Qt 库
target_link_libraries(QtServiceShared PRIVATE Qt6::Core)
target_link_libraries(QtServiceStatic PRIVATE Qt6::Core)

set_target_properties(QtServiceShared PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

set_target_properties(QtServiceStatic PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
