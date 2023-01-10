cmake_minimum_required(VERSION 3.24)
project(gtk_demo C)

set(CMAKE_C_STANDARD 17)

# 坑
# gtk的安装路径绝对不能有空格

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTK4 REQUIRED gtk4)

include_directories(${GTK4_INCLUDE_DIRS})

link_directories(${GTK4_LIBRARY_DIRS})

add_executable(gtk_demo main.c)

target_link_libraries(gtk_demo ${GTK_LIBRARIES})

# Find GTK, glib and GTKGLArea
# GTK_INCLUDE_DIR   - Directories to include to use GTK
# GTK_LIBRARIES     - Files to link against to use GTK
# GTK_FOUND         - GTK was found
# GTK_GL_FOUND      - GTK's GL features were found

IF (GTK_FOUND)
    message(${GTK_FOUND})
ELSE (GTK_FOUND)
    message("not find gtk")
ENDIF (GTK_FOUND)

# 打印变量
#message(${GTK_FOUND})
message(${GTK4_INCLUDE_DIRS})
message(${GTK4_LIBRARY_DIRS})
#message(${GTK_LIBRARIES})
