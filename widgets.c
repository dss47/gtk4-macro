#include "widgets.h"

GtkWidget* create_window(GtkApplication *app, Window *config) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), config->title);
    gtk_window_set_default_size(GTK_WINDOW(window), config->width, config->height);
    if (config->maximized) {
        gtk_window_maximize(GTK_WINDOW(window));
    }
    return window;
}