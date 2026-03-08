#ifndef GTK_WRAPPER_CONTAINER_H
#define GTK_WRAPPER_CONTAINER_H

#include <gtk/gtk.h>
#include <stdbool.h>

#include "common.h"

typedef struct {
    int column_spacing;
    int row_spacing;
    bool homogeneous_columns;
    bool homogeneous_rows;
    widget_style_config style;
} grid_config;

#define GRID_CONFIG_DEFAULT ((grid_config){ \
    .column_spacing = 0, \
    .row_spacing = 0, \
    .homogeneous_columns = false, \
    .homogeneous_rows = false, \
    .style = WIDGET_STYLE_CONFIG_DEFAULT, \
})

typedef struct {
    GtkOrientation orientation;
    int spacing;
    bool homogeneous;
    widget_style_config style;
} box_config;

#define BOX_CONFIG_DEFAULT ((box_config){ \
    .orientation = GTK_ORIENTATION_VERTICAL, \
    .spacing = 0, \
    .homogeneous = false, \
    .style = WIDGET_STYLE_CONFIG_DEFAULT, \
})

typedef struct {
    GtkStackTransitionType transition;
    guint duration_ms;
    bool vhomogeneous;
    bool hhomogeneous;
    widget_style_config style;
} stack_config;

#define STACK_CONFIG_DEFAULT ((stack_config){ \
    .transition = GTK_STACK_TRANSITION_TYPE_NONE, \
    .duration_ms = 200, \
    .vhomogeneous = false, \
    .hhomogeneous = false, \
    .style = WIDGET_STYLE_CONFIG_DEFAULT, \
})

GtkWidget *create_grid(const grid_config *config);
GtkWidget *create_box(const box_config *config);
GtkWidget *create_stack(const stack_config *config);
GtkWidget *create_stack_sidebar(GtkWidget *stack, const widget_style_config *style);
void stack_add_page(GtkWidget *stack, GtkWidget *child, const char *name, const char *title);

#endif
