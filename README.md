# Qt Create Process From Service Example

这是一个演示如何使用qtservice静态库的Qt项目。

## 项目结构

```
QtCreateProcessFromServiceExample/
├── CMakeLists.txt              # 根目录CMake配置
├── qtservice/                  # qtservice静态库
│   ├── CMakeLists.txt         # 静态库构建配置
│   └── src/                   # 源代码
│       ├── qtservice.h        # 主要头文件
│       ├── qtservice.cpp      # 主要实现
│       ├── qtservice_win.cpp  # Windows平台实现
│       ├── qtservice_unix.cpp # Unix平台实现
│       └── ...                # 其他源文件
├── QServiceExample/           # 使用静态库的示例
│   ├── CMakeLists.txt        # 示例构建配置
│   ├── main.cpp              # 主程序
│   ├── service_example.h     # 服务示例头文件
│   └── service_example.cpp   # 服务示例实现
└── tests/                    # 单元测试
    ├── CMakeLists.txt        # 测试构建配置
    ├── test_qtservice.cpp    # 基本功能测试
    ├── test_service_controller.cpp # 服务控制器测试
    └── test_service_base.cpp # 服务基类测试
```

## 构建说明

### 前提条件
- CMake 3.16 或更高版本
- Qt 5 或 Qt 6
- 支持C++11的编译器

### 构建步骤

1. 创建构建目录：
```bash
mkdir build
cd build
```

2. 配置项目：
```bash
cmake ..
```

3. 构建项目：
```bash
cmake --build .
```

### 构建产物

- `libqtservice.a` (Linux/macOS) 或 `qtservice.lib` (Windows) - qtservice静态库
- `QServiceExample` - 使用静态库的示例程序
- `qtservice_tests` - 单元测试程序

## 使用方法

### 运行示例程序

```bash
# 查看帮助
./QServiceExample --help

# 安装服务（需要管理员权限）
./QServiceExample --install

# 启动服务
./QServiceExample --start

# 查看服务状态
./QServiceExample --status

# 停止服务
./QServiceExample --stop

# 卸载服务（需要管理员权限）
./QServiceExample --uninstall
```

### 运行单元测试

```bash
# 运行所有测试
./qtservice_tests

# 或者使用ctest
ctest
```

## 静态库特性

- **跨平台支持**: 支持Windows和Unix/Linux系统
- **Qt集成**: 完全集成Qt框架
- **服务管理**: 提供完整的服务生命周期管理
- **日志功能**: 内置日志记录功能
- **命令行支持**: 提供命令行参数解析

## 开发说明

### 添加新的服务

1. 继承`QtService<QCoreApplication>`类
2. 重写必要的虚函数：
   - `start()` - 服务启动时调用
   - `stop()` - 服务停止时调用
   - `createApplication()` - 创建应用程序实例
   - `executeApplication()` - 执行应用程序

### 使用静态库

在你的CMakeLists.txt中：

```cmake
# 链接静态库
target_link_libraries(your_target qtservice)

# 设置包含目录
target_include_directories(your_target PRIVATE
    ${CMAKE_SOURCE_DIR}/qtservice/src
)
```

## 许可证

本项目使用BSD-3-Clause许可证。

## 致谢

qtservice文件夹的代码来源于: https://github.com/qtproject/qt-solutions/tree/master/qtservice