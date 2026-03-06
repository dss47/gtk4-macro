#ifndef GTK_WRAPPER_INPUT_H
#define GTK_WRAPPER_INPUT_H

#include <gtk/gtk.h>
#include <stdbool.h>

#include "common.h"

typedef struct {
    const char *placeholder;
    const char *default_text;
    const char *purpose_hint;
    bool password;
    bool editable;
    int max_length;
    widget_style_config style;
    void (*on_changed)(GtkEditable *editable, gpointer user_data);
    gpointer user_data;
} entry_config;

typedef struct {
    const char **options;
    guint selected_index;
    bool enable_search;
    widget_style_config style;
    void (*on_selected)(GtkDropDown *dropdown, GParamSpec *pspec, gpointer user_data);
    gpointer user_data;
} dropdown_config;

typedef struct {
    double min_value;
    double max_value;
    double step;
    double page;
    double value;
    guint digits;
    bool numeric_only;
    bool wrap;
    widget_style_config style;
    void (*on_value_changed)(GtkSpinButton *spin, gpointer user_data);
    gpointer user_data;
} spin_button_config;

GtkWidget *create_entry(const entry_config *config);
GtkWidget *create_dropdown(const dropdown_config *config);
GtkWidget *create_spin_button(const spin_button_config *config);

#endif
