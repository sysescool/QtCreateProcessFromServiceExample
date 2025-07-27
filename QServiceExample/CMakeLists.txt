cmake_minimum_required(VERSION 3.16)
project(QServiceExample)

# 查找 Qt6 Core（这是 Qt 官方的包）
find_package(Qt6 REQUIRED COMPONENTS Core)

# 设置源文件
set(SOURCES
    main.cpp
)

# 创建可执行文件
add_executable(QServiceExample ${SOURCES})

# 直接链接 qtservice 库（来自 add_subdirectory）
target_link_libraries(QServiceExample
    PRIVATE
    Qt6::Core
    QtServiceStatic    # 或 QtServiceShared
)

target_include_directories(QtServiceStatic
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:include/qtservice>
)
target_include_directories(QtServiceShared
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:include/qtservice>
)
