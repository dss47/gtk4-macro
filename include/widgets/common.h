#ifndef GTK_WRAPPER_COMMON_H
#define GTK_WRAPPER_COMMON_H

#include <gtk/gtk.h>
#include <stdbool.h>

typedef struct {
    const char *css_class;
    const char **css_classes;
    int width_request;
    int height_request;
    int margin_top;
    int margin_bottom;
    int margin_start;
    int margin_end;
    GtkAlign halign;
    GtkAlign valign;
    bool set_halign;
    bool set_valign;
    bool set_hexpand;
    bool set_vexpand;
    bool set_sensitive;
    bool set_visible;
    bool hexpand;
    bool vexpand;
    bool sensitive;
    bool visible;
    const char *tooltip;
} widget_style_config;

// Default initializer for widget style configs.
// Usage:
//   widget_style_config style = WIDGET_STYLE_CONFIG_DEFAULT;
//   style.margin_top = 12;
#define WIDGET_STYLE_CONFIG_DEFAULT ((widget_style_config){0})

void apply_widget_style(GtkWidget *widget, const widget_style_config *style);

#endif
