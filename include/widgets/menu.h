#ifndef GTK_WRAPPER_MENU_H
#define GTK_WRAPPER_MENU_H

#include <gtk/gtk.h>
#include <stddef.h>
#include <stdbool.h>

#include "common.h"

typedef enum {
    MENU_ITEM_ACTION = 0,
    MENU_ITEM_SUBMENU,
    MENU_ITEM_SECTION
} menu_item_kind;

typedef enum {
    MENU_LAYOUT_HORIZONTAL = 0,
    MENU_LAYOUT_VERTICAL
} menu_layout_mode;

typedef void (*menu_item_callback)(GSimpleAction *action, GVariant *parameter, gpointer user_data);

typedef struct menu_item_config menu_item_config;

struct menu_item_config {
    const char *label;
    menu_item_kind kind;
    const menu_item_config *children;
    size_t child_count;
    bool enabled;
    menu_item_callback on_activate;
    gpointer user_data;
};

#define MENU_ITEM_CONFIG_DEFAULT ((menu_item_config){ \
    .label = NULL, \
    .kind = MENU_ITEM_ACTION, \
    .children = NULL, \
    .child_count = 0, \
    .enabled = true, \
    .on_activate = NULL, \
    .user_data = NULL, \
})

typedef struct {
    const char *label;
    const menu_item_config *items;
    size_t item_count;
} menu_section_config;

#define MENU_SECTION_CONFIG_DEFAULT ((menu_section_config){ \
    .label = NULL, \
    .items = NULL, \
    .item_count = 0, \
})

typedef struct {
    const menu_section_config *sections;
    size_t section_count;
    GActionMap *action_map;
    menu_layout_mode layout;
    bool show_arrow_indicators;
    widget_style_config style;
} menubar_config;

#define MENUBAR_CONFIG_DEFAULT ((menubar_config){ \
    .sections = NULL, \
    .section_count = 0, \
    .action_map = NULL, \
    .layout = MENU_LAYOUT_HORIZONTAL, \
    .show_arrow_indicators = true, \
    .style = WIDGET_STYLE_CONFIG_DEFAULT, \
})

GtkWidget *create_menubar(const menubar_config *config);
GtkWidget *create_menu_panel(const menubar_config *config);

#endif
