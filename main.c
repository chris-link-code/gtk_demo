#include <gtk/gtk.h>

static void print_hello(GtkWidget *widget, gpointer data) {
    g_print("Hello World\n");
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW (window), "Window");
    gtk_window_set_default_size(GTK_WINDOW (window), 600, 400);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(box, GTK_ALIGN_CENTER);

    gtk_window_set_child(GTK_WINDOW (window), box);

    button = gtk_button_new_with_label("Hello World");

    g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), window);

    gtk_box_append(GTK_BOX (box), button);

    gtk_widget_show(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

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

    app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION (app), argc, argv);
    g_object_unref(app);

    return status;
}
