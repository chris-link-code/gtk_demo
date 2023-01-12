# note

pacman -S mingw-w64-x86_64-gtk4

pacman -S mingw-w64-x86_64-toolchain base-devel


C:\File\program\msys2\mingw64

设置系统环境变量

设置Path（如果为32为则将32改为64）

新建MINGW_HOME

{安装目录}\msys2\mingw64

新建C_INCLUDE_PATH

%MINGW_HOME%\include

新建LIBRARY_PATH

%MINGW_HOME%\lib

变量Path中添加如下值

%MINGW_HOME%\bin

https://blog.csdn.net/weixin_41708670/article/details/83926528




pkg-config gtk+-2.0 --cflags和pkg-config gtk+-2.0 --libs

cmd
pkg-config --cflags gtk4
pkg-config --libs gtk4

-- Checking for module 'gtk4'
-- Found gtk4, version 4.8.2
-- Configuring done
-- Generating don

https://gitlab.gnome.org/GNOME/gtk
https://www.gtk.org/docs/getting-started/hello-world/
https://developer-old.gnome.org/gtk3/stable/GtkWindow.html
https://docs.gtk.org/gtk4/getting_started.html
https://docs.gtk.org/gtk4/index.html
https://www.cnblogs.com/libra13179/p/12531758.html
https://blog.csdn.net/Rong_Toa/article/details/85856499
https://zhuanlan.zhihu.com/p/130430726
https://docs.gtk.org/gtk4/visual_index.html


https://cmake.org/cmake/help/latest/module/FindGTK.html
https://discourse.gnome.org/t/pkg-config-libs-gtk-3-0-problem/3288/11
https://bbs.archlinux.org/viewtopic.php?id=129298


https://blog.csdn.net/weixin_33898876/article/details/93154353
https://www.cnblogs.com/QuLory/archive/2013/01/13/2859036.html



日志
zlog
https://github.com/HardySimpson/zlog
http://hardysimpson.github.io/zlog/
https://blog.csdn.net/weixin_46245859/article/details/126071399
https://blog.csdn.net/hhhjjjj/article/details/84821660

不过目前我还没发现怎样在Windows上使用zlog

zlog是一个高性能、线程安全、灵活、概念清晰的纯C日志函数库。
事实上，在C的世界里面没有特别好的日志函数库（就像JAVA里面的的log4j，或者C++的log4cxx）。
C程序员都喜欢用自己的轮子。printf就是个挺好的轮子，但没办法通过配置改变日志的格式或者输出文件。syslog是个系统级别的轮子，不过速度慢，而且功能比较单调。log4c异常坑爹（有内存泄漏、效率低等等），而且已经停止开发
所以我（难易）写了zlog。

zlog有这些特性：
* syslog分类模型，基于规则路由过滤，比log4j模型要正确高效
* 日志格式定制，类似于log4j的pattern layout
* 多种输出，包括动态文件、静态文件、stdout、stderr、syslog、用户自定义输出函数
* 运行时手动或自动刷新配置（同时保证安全）
* 高性能，在我的笔记本上达到338'638条日志每秒, 大概是syslog(3)配合rsyslogd的1000倍速度
* 高可靠性和速度之间的平衡，用户自定义多少条日志后fsync数据到硬盘
* 用户自定义等级
* 多线程和多进程环境下保证安全转档
* 精确到微秒
* 简单调用包装dzlog（一个程序默认只用一个分类）
* MDC，线程键-值对的表，可以扩展用户自定义的字段
* 自诊断，可以在运行时输出zlog自己的日志和配置状态
* 不依赖其他库，只要是个POSIX系统就成(当然还要一个C99兼容的vsnprintf)[/size]
官网：
http://hardysimpson.github.io/zlog





/**
预定义宏
ANSI C 定义了许多宏。在编程中您可以使用这些宏，但是不能直接修改这些预定义的宏。
__DATE__	当前日期，一个以 "MMM DD YYYY" 格式表示的字符常量。
__TIME__	当前时间，一个以 "HH:MM:SS" 格式表示的字符常量。
__FILE__	这会包含当前文件名，一个字符串常量。
__LINE__	这会包含当前行号，一个十进制常量。
__STDC__	当编译器以 ANSI 标准编译时，则定义为 1。
*/

printf("File :%s\n", __FILE__);
printf("Date :%s\n", __DATE__);
printf("Time :%s\n", __TIME__);
printf("Line :%d\n", __LINE__);
printf("ANSI :%d\n", __STDC__);
printf("STDC_VERSION :%d\n", __STDC_VERSION__);

printf("arguments number: %d\n", argc);
if (argc > 0) {
    for (int i = 0; i < argc; ++i) {
        printf("argument[%d]: %s\n", i, argv[i]);
    }
} else {
    printf("There is no argument");
}