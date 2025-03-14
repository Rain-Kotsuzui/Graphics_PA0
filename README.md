# 图形学基础PA0

## 简介

本作业旨在通过绘制直线、圆以及填充颜色来练习图形学的基本概念。

## 功能

- 绘制直线
- 绘制圆
- 填充颜色

## 使用方法

1. 克隆或下载本项目到本地。
2. 使用你喜欢的编程环境（如Visual Studio Code、PyCharm等）打开项目。
3. 运行提供的代码文件，根据需要调整参数。
4. 查看生成的图形。

## 文件结构
```

D:.
│  .gitignore
│  CMakeLists.txt
│  LICENSE
│  README.md
│  run_all.sh
│
├─.vscode
│      launch.json
│      tasks.json
│
├─deps
│  └─vecmath
│      │  CMakeLists.txt
│      │
│      ├─include
│      │      Matrix2f.h
│      │      Matrix3f.h
│      │      Matrix4f.h
│      │      Quat4f.h
│      │      vecmath.h
│      │      Vector2f.h
│      │      Vector3f.h
│      │      Vector4f.h
│      │
│      └─src
│              Matrix2f.cpp
│              Matrix3f.cpp
│              Matrix4f.cpp
│              Quat4f.cpp
│              Vector2f.cpp
│              Vector3f.cpp
│              Vector4f.cpp
│
├─include
│      canvas_parser.hpp
│      element.hpp
│      image.hpp
│
├─src
│      canvas_parser.cpp
│      image.cpp
│      main.cpp
│
└─testcases
        canvas01_basic.txt
        canvas02_emoji.txt
```

## 贡献

如果你有任何改进意见或想要贡献代码，请随时提交Pull Request或开Issue讨论。

## 许可

本项目遵循MIT许可证。请查看LICENSE文件了解更多信息。


