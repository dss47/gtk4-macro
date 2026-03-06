#include "widgets/date.h"

GtkWidget *create_calendar(const calendar_config *config) {
    GtkWidget *calendar = gtk_calendar_new();

    if (config == NULL) {
        return calendar;
    }

    if (config->selected_date != NULL) {
        gtk_calendar_set_date(GTK_CALENDAR(calendar), config->selected_date);
    }
    gtk_calendar_set_show_day_names(GTK_CALENDAR(calendar), config->show_day_names);
    gtk_calendar_set_show_week_numbers(GTK_CALENDAR(calendar), config->show_week_numbers);
    gtk_calendar_set_show_heading(GTK_CALENDAR(calendar), !config->no_month_change);
    apply_widget_style(calendar, &config->style);

    if (config->on_day_selected != NULL) {
        g_signal_connect(calendar, "day-selected", G_CALLBACK(config->on_day_selected), config->user_data);
    }

    return calendar;
}
