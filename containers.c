#include "containers.h"

GtkWidget* create_grid(Grid *gridConfig){
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_column_spacing(GTK_GRID(grid),gridConfig->cl_spacing);
    gtk_grid_set_row_spacing(GTK_GRID(grid),gridConfig->r_spacing);
    gtk_widget_set_margin_top(grid,gridConfig->margin_top);
    return grid;
}

GtkWidget* create_box(Box *boxConfig){
    GtkWidget *box = gtk_box_new(boxConfig->orientation,boxConfig->spacing);
    gtk_box_set_homogeneous(GTK_BOX(box),boxConfig->homogeneous);
    return box;
}