#ifndef GTK_WRAPPER_DIALOG_H
#define GTK_WRAPPER_DIALOG_H

#include <gtk/gtk.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct {
    const char *label;
    const char *appearance;
} alert_button_config;

#define ALERT_BUTTON_CONFIG_DEFAULT ((alert_button_config){ \
    .label = NULL, \
    .appearance = NULL, \
})

typedef struct {
    GtkWindow *parent;
    const char *message;
    const char *detail;
    const alert_button_config *buttons;
    size_t button_count;
    int default_button;
    int cancel_button;
    bool modal;
    void (*on_response)(int response_index, gpointer user_data);
    gpointer user_data;
} alert_dialog_config;

#define ALERT_DIALOG_CONFIG_DEFAULT ((alert_dialog_config){ \
    .parent = NULL, \
    .message = NULL, \
    .detail = NULL, \
    .buttons = NULL, \
    .button_count = 0, \
    .default_button = -1, \
    .cancel_button = -1, \
    .modal = true, \
    .on_response = NULL, \
    .user_data = NULL, \
})

void show_alert_dialog(const alert_dialog_config *config);

#endif
