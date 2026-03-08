#ifndef GTK_WRAPPER_WINDOW_H
#define GTK_WRAPPER_WINDOW_H

#include <gtk/gtk.h>
#include <stdbool.h>

#include "common.h"

typedef struct {
    const char *title;
    const char *icon_name;
    const char *widget_name;
    const char *background_color;
    const char *background_image_path;
    int default_width;
    int default_height;
    int min_width;
    int min_height;
    int max_width;
    int max_height;
    bool resizable;
    bool decorated;
    bool modal;
    bool maximized;
    bool present_on_create;
    widget_style_config style;
} window_config;

#define WINDOW_CONFIG_DEFAULT ((window_config){ \
    .title = NULL, \
    .icon_name = NULL, \
    .widget_name = NULL, \
    .background_color = NULL, \
    .background_image_path = NULL, \
    .default_width = -1, \
    .default_height = -1, \
    .min_width = 0, \
    .min_height = 0, \
    .max_width = 0, \
    .max_height = 0, \
    .resizable = true, \
    .decorated = true, \
    .modal = false, \
    .maximized = false, \
    .present_on_create = false, \
    .style = WIDGET_STYLE_CONFIG_DEFAULT, \
})

GtkWidget *create_window(GtkApplication *app, const window_config *config);

#endif
