#ifndef CONTAINERS_H
#define CONTAINERS_H

#include <gtk/gtk.h>

typedef struct {
    int cl_spacing;
    int r_spacing;
    int margin_top;
}Grid;

typedef struct {
    GtkOrientation orientation;
    int spacing;
    bool homogeneous;
}Box;

GtkWidget* create_grid(Grid *gridConfig);
GtkWidget* create_box(Box *boxConfig);
#endif