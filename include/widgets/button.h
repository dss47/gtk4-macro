#ifndef GTK_WRAPPER_BUTTON_H
#define GTK_WRAPPER_BUTTON_H

#include <gtk/gtk.h>
#include <stdbool.h>

#include "common.h"

typedef struct {
    const char *label;
    const char *icon_name;
    const char *theme_variant;
    bool use_underline;
    bool has_frame;
    bool can_shrink;
    int icon_size;
    widget_style_config style;
    void (*on_clicked)(GtkButton *button, gpointer user_data);
    gpointer user_data;
} button_config;

#define BUTTON_CONFIG_DEFAULT ((button_config){ \
    .label = NULL, \
    .icon_name = NULL, \
    .theme_variant = NULL, \
    .use_underline = false, \
    .has_frame = true, \
    .can_shrink = true, \
    .icon_size = 0, \
    .style = WIDGET_STYLE_CONFIG_DEFAULT, \
    .on_clicked = NULL, \
    .user_data = NULL, \
})

typedef struct {
    const char *label;
    GtkWidget *group_with;
    bool is_active;
    widget_style_config style;
    void (*on_toggled)(GtkCheckButton *button, gpointer user_data);
    gpointer user_data;
} radio_button_config;

#define RADIO_BUTTON_CONFIG_DEFAULT ((radio_button_config){ \
    .label = NULL, \
    .group_with = NULL, \
    .is_active = false, \
    .style = WIDGET_STYLE_CONFIG_DEFAULT, \
    .on_toggled = NULL, \
    .user_data = NULL, \
})

GtkWidget *create_button(const button_config *config);
GtkWidget *create_radio_button(const radio_button_config *config);

#endif
