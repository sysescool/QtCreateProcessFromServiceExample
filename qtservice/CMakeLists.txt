cmake_minimum_required(VERSION 3.10)

project(qtservice)

# 设置头文件和源文件
set(PUBLIC_HEADERS
    src/qtservice.h
)
set(PRIVATE_HEADERS
    src/qtservice_p.h
)
set(SOURCES
    src/qtservice.cpp
)

if (WIN32)
    find_package(Qt6 REQUIRED COMPONENTS Core)
    list(APPEND SOURCES src/qtservice_win.cpp)
endif()

# 创建静态库
add_library(QtServiceStatic STATIC ${SOURCES} ${PUBLIC_HEADERS} ${PRIVATE_HEADERS})
target_link_libraries(QtServiceStatic PRIVATE Qt6::Core)
target_include_directories(QtServiceStatic
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>  # 构建时头文件路径
        $<INSTALL_INTERFACE:include>                        # 安装后头文件路径
)

# 创建动态库
add_library(QtServiceShared SHARED ${SOURCES} ${PUBLIC_HEADERS} ${PRIVATE_HEADERS})
target_link_libraries(QtServiceShared PRIVATE Qt6::Core)
target_include_directories(QtServiceShared
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:include>
)

# 设置输出路径
foreach(target QtServiceStatic QtServiceShared)
    set_target_properties(${target} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    )
endforeach()

# 安装头文件到 include/qtservice
install(FILES ${PUBLIC_HEADERS}
    DESTINATION include/qtservice
)

# 安装库
install(TARGETS QtServiceStatic QtServiceShared
    EXPORT QtServiceTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

# 安装导出目标
install(EXPORT QtServiceTargets
    FILE QtServiceTargets.cmake
    NAMESPACE QtService::
    DESTINATION lib/cmake/QtService
)

# 安装配置文件（用于 find_package）
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/QtServiceConfigVersion.cmake"
    VERSION 1.0.0
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/QtServiceConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/QtServiceConfig.cmake"
    INSTALL_DESTINATION lib/cmake/QtService
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/QtServiceConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/QtServiceConfigVersion.cmake"
    DESTINATION lib/cmake/QtService
)
