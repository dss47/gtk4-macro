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

#define ENTRY_CONFIG_DEFAULT ((entry_config){ \
    .placeholder = NULL, \
    .default_text = NULL, \
    .purpose_hint = NULL, \
    .password = false, \
    .editable = true, \
    .max_length = 0, \
    .style = WIDGET_STYLE_CONFIG_DEFAULT, \
    .on_changed = NULL, \
    .user_data = NULL, \
})

typedef struct {
    const char **options;
    guint selected_index;
    bool enable_search;
    widget_style_config style;
    void (*on_selected)(GtkDropDown *dropdown, GParamSpec *pspec, gpointer user_data);
    gpointer user_data;
} dropdown_config;

#define DROPDOWN_CONFIG_DEFAULT ((dropdown_config){ \
    .options = NULL, \
    .selected_index = 0, \
    .enable_search = false, \
    .style = WIDGET_STYLE_CONFIG_DEFAULT, \
    .on_selected = NULL, \
    .user_data = NULL, \
})

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

#define SPIN_BUTTON_CONFIG_DEFAULT ((spin_button_config){ \
    .min_value = 0.0, \
    .max_value = 100.0, \
    .step = 1.0, \
    .page = 5.0, \
    .value = 0.0, \
    .digits = 0, \
    .numeric_only = false, \
    .wrap = false, \
    .style = WIDGET_STYLE_CONFIG_DEFAULT, \
    .on_value_changed = NULL, \
    .user_data = NULL, \
})

GtkWidget *create_entry(const entry_config *config);
GtkWidget *create_dropdown(const dropdown_config *config);
GtkWidget *create_spin_button(const spin_button_config *config);

#endif
