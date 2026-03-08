#ifndef GTK_WRAPPER_SEPARATOR_H
#define GTK_WRAPPER_SEPARATOR_H

#include <gtk/gtk.h>

#include "common.h"

typedef struct {
    GtkOrientation orientation;
    widget_style_config style;
} separator_config;

#define SEPARATOR_CONFIG_DEFAULT ((separator_config){ \
    .orientation = GTK_ORIENTATION_HORIZONTAL, \
    .style = WIDGET_STYLE_CONFIG_DEFAULT, \
})

GtkWidget *create_separator(const separator_config *config);

#endif
