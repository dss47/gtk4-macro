#ifndef GTK_WRAPPER_TOGGLE_H
#define GTK_WRAPPER_TOGGLE_H

#include <gtk/gtk.h>
#include <stdbool.h>

#include "common.h"

typedef struct {
    const char *label;
    bool active;
    bool inconsistent;
    widget_style_config style;
    void (*on_toggled)(GtkCheckButton *button, gpointer user_data);
    gpointer user_data;
} checkbox_config;

#define CHECKBOX_CONFIG_DEFAULT ((checkbox_config){ \
    .label = NULL, \
    .active = false, \
    .inconsistent = false, \
    .style = WIDGET_STYLE_CONFIG_DEFAULT, \
    .on_toggled = NULL, \
    .user_data = NULL, \
})

typedef struct {
    const char *label;
    bool active;
    bool state;
    widget_style_config style;
    void (*on_active_changed)(GtkSwitch *sw, GParamSpec *pspec, gpointer user_data);
    gpointer user_data;
} switch_config;

#define SWITCH_CONFIG_DEFAULT ((switch_config){ \
    .label = NULL, \
    .active = false, \
    .state = false, \
    .style = WIDGET_STYLE_CONFIG_DEFAULT, \
    .on_active_changed = NULL, \
    .user_data = NULL, \
})

GtkWidget *create_checkbox(const checkbox_config *config);
GtkWidget *create_switch_row(const switch_config *config, GtkWidget **out_switch);

#endif
