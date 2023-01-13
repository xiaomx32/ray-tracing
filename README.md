## 1、运行代码生成可执行文件

在根目录下打开命令行工具，运行

    $ cmake -S source -B ./build

    $ cmake -B build

在 `build/Debug` 文件夹下会生成 `main.exe` 可执行文件。

## 2、得到图片

运行

    $main.exe > image.ppm

则会生成 `.pmm` 文件。