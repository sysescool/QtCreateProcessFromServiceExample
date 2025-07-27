cmake_minimum_required(VERSION 3.16)

project(QtCreateProcessFromServiceExample LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt配置
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 查找Qt包
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

# 添加子目录
add_subdirectory(qtservice)       # qt service 静态库
add_subdirectory(QServiceExample) # 使用静态库的示例
#add_subdirectory(tests)           # 单元测试目录
