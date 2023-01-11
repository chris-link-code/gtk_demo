cmake_minimum_required(VERSION 3.24)
project(gtk_demo C)

set(CMAKE_C_STANDARD 17)

# 坑
# gtk的安装路径绝对不能有空格

# 1、cmake的内置命令是不区分大小写的
# 2、cmake不管是内置变量还是自定义变量都是区分大小写的

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTK4 REQUIRED gtk4)

include_directories(${GTK4_INCLUDE_DIRS})

link_directories(${GTK4_LIBRARY_DIRS})

add_executable(gtk_demo main.c)

target_link_libraries(gtk_demo ${GTK4_LIBRARIES})

# 隐藏控制台黑窗口
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -mwindows)

# Find GTK, glib and GTKGLArea
# GTK_INCLUDE_DIR   - Directories to include to use GTK
# GTK_LIBRARIES     - Files to link against to use GTK
# GTK_FOUND         - GTK was found
# GTK_GL_FOUND      - GTK's GL features were found

if (GTK4_FOUND)
    message(${GTK4_FOUND})
else ()
    message("not find gtk")
endif ()

# 打印变量
message(${GTK4_FOUND})
message(${GTK4_INCLUDE_DIRS})
message(${GTK4_LIBRARY_DIRS})
message(${GTK4_LIBRARIES})
message(${GTK4_VERSION})

# 打印当前操作系统类型
message(${CMAKE_SYSTEM_NAME})

# 根据当前操作系统做判断
if (CMAKE_SYSTEM_NAME MATCHES "Windows")
    message("Windows")
elseif (CMAKE_SYSTEM_NAME MATCHES "Linux")
    message("Linux")
endif ()