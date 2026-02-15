#include "activates.h"
#include "widgets.h"
#include "button.h"
#include "containers.h"

void activatewin1(GtkApplication *app, gpointer user_data) {
    (void)user_data;

    Window winConfig = {
        .title = "My University Project",
        .width = 600,
        .height = 400,
        .maximized = false
    };
    GtkWidget *window = create_window(app, &winConfig);

    Grid gridConfig = {
        .cl_spacing = 10,
        .margin_top = 5,
        .r_spacing = 5,
    };
    GtkWidget *grid = create_grid(&gridConfig);
    Box boxConfig = {
        .orientation = GTK_ORIENTATION_HORIZONTAL,
        .spacing = 10,
        .homogeneous = true
    };
    GtkWidget *box = create_box(&boxConfig);

    button btnConfig = {
        .label = "_Submit",
        .css_class = "",
        .has_frame = true,
        .use_underline = true,
        .width = 200,
        .height = 150
    };
    GtkWidget *submit_button = create_button(&btnConfig);
    Radiobutton R1 = {
        .label = "Option A",
        .group_with = NULL,
        .is_active = false
    };
    GtkWidget *radio1 = create_radio_button(&R1);
    Radiobutton R2 = {
        .label = "Option B",
        .group_with = radio1,
        .is_active = false
    };
    GtkWidget *radio2 = create_radio_button(&R2);
    Radiobutton R3 = {
        .label = "Option C",
        .group_with = radio1,
        .is_active = false
    };
    GtkWidget *radio3 = create_radio_button(&R3);
    gtk_box_append(GTK_BOX(box),radio1);
    gtk_box_append(GTK_BOX(box),radio2);
    gtk_box_append(GTK_BOX(box),radio3);
    gtk_grid_attach(GTK_GRID(grid),submit_button , 0,0,1,1);
    gtk_grid_attach(GTK_GRID(grid),box , 0,1,1,1);
    gtk_window_set_child(GTK_WINDOW(window), grid);
    gtk_window_present(GTK_WINDOW(window));
}