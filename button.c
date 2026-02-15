#include "button.h"

GtkWidget *create_button(button *btnConfig) {
    if (btnConfig == NULL) {
        return gtk_button_new();
    }
    const char *label = btnConfig->label ? btnConfig->label : "";
    
    GtkWidget *btn = btnConfig->use_underline ? gtk_button_new_with_mnemonic(label): gtk_button_new_with_label(label);
    gtk_widget_set_size_request(btn, btnConfig->width, btnConfig->height);

    gtk_button_set_has_frame(GTK_BUTTON(btn), btnConfig->has_frame);

    if (btnConfig->css_class && btnConfig->css_class[0] != '\0') {
        gtk_widget_add_css_class(btn, btnConfig->css_class);
    }

    if (btnConfig->icon && btnConfig->icon[0] != '\0') {
        GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
        GtkWidget *image = gtk_image_new_from_icon_name(btnConfig->icon);
        gtk_box_append(GTK_BOX(box), image);

        if (label[0] != '\0') {
            GtkWidget *lbl = btnConfig->use_underline ? gtk_label_new_with_mnemonic(label): gtk_label_new(label);
            gtk_box_append(GTK_BOX(box), lbl);
        }

        gtk_button_set_child(GTK_BUTTON(btn), box);
    }

    return btn;
}

GtkWidget *create_radio_button(Radiobutton *btnConfig){
    GtkWidget *radio = gtk_check_button_new_with_label(btnConfig->label);
    if(btnConfig->group_with != NULL){
        gtk_check_button_set_group(GTK_CHECK_BUTTON(radio),GTK_CHECK_BUTTON(btnConfig->group_with));
    }
    gtk_check_button_set_active(GTK_CHECK_BUTTON(radio),btnConfig->is_active);
    return radio;
}