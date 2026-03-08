#ifndef GTK_WRAPPER_DISPLAY_H
#define GTK_WRAPPER_DISPLAY_H

#include <gtk/gtk.h>
#include <stdbool.h>

#include "common.h"

typedef struct {
    double fraction;
    const char *text;
    GtkOrientation orientation;
    bool show_text;
    bool inverted;
    bool pulse_once;
    widget_style_config style;
} progress_bar_config;

#define PROGRESS_BAR_CONFIG_DEFAULT ((progress_bar_config){ \
    .fraction = 0.0, \
    .text = NULL, \
    .orientation = GTK_ORIENTATION_HORIZONTAL, \
    .show_text = false, \
    .inverted = false, \
    .pulse_once = false, \
    .style = WIDGET_STYLE_CONFIG_DEFAULT, \
})

typedef struct {
    int size;
    bool spinning;
    widget_style_config style;
} spinner_config;

#define SPINNER_CONFIG_DEFAULT ((spinner_config){ \
    .size = 0, \
    .spinning = false, \
    .style = WIDGET_STYLE_CONFIG_DEFAULT, \
})

typedef struct {
    const char *text;
    bool selectable;
    bool wrap;
    PangoEllipsizeMode ellipsize;
    int max_width_chars;
    widget_style_config style;
} label_config;

#define LABEL_CONFIG_DEFAULT ((label_config){ \
    .text = NULL, \
    .selectable = false, \
    .wrap = false, \
    .ellipsize = PANGO_ELLIPSIZE_NONE, \
    .max_width_chars = 0, \
    .style = WIDGET_STYLE_CONFIG_DEFAULT, \
})

typedef struct {
    const char *icon_name;
    const char *file_path;
    int pixel_size;
    bool keep_aspect;
    widget_style_config style;
} image_config;

#define IMAGE_CONFIG_DEFAULT ((image_config){ \
    .icon_name = NULL, \
    .file_path = NULL, \
    .pixel_size = 0, \
    .keep_aspect = true, \
    .style = WIDGET_STYLE_CONFIG_DEFAULT, \
})

GtkWidget *create_progress_bar(const progress_bar_config *config);
GtkWidget *create_spinner(const spinner_config *config);
GtkWidget *create_label(const label_config *config);
GtkWidget *create_image(const image_config *config);

#endif
