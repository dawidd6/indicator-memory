#include <libappindicator/app-indicator.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ICON "com.github.dawidd6.indicator-memory"

/* Vars */
AppIndicator *indicator;
GtkWidget *menu;
GtkWidget *item_quit;
double mem_total, mem_avail;
char title[50];
FILE *file;

/* Functions' declarations */
static inline gboolean update(gpointer ptr);

/* Main */
int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    file = fopen("/proc/meminfo", "r");

    menu = gtk_menu_new();
    indicator = app_indicator_new("indicator-memory", ICON, APP_INDICATOR_CATEGORY_APPLICATION_STATUS);
    app_indicator_set_status(indicator, APP_INDICATOR_STATUS_ACTIVE);
    app_indicator_set_menu(indicator, GTK_MENU(menu));
    app_indicator_set_title(indicator, "Memory Indicator");

    item_quit = gtk_menu_item_new_with_label("Quit");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), item_quit);
    g_signal_connect(item_quit, "activate", gtk_main_quit, NULL);

    update(NULL);

    g_timeout_add_seconds(3, update, NULL);
    gtk_widget_show_all(menu);
    gtk_main();
    fclose(file);
    return 0;
}

/* Functions' definitions */
gboolean update(gpointer ptr)
{
    fscanf(file, "MemTotal: %lf kB\n", &mem_total);
    fscanf(file, "MemFree: %*s kB\n");
    fscanf(file, "MemAvailable: %lf kB\n", &mem_avail);

    sprintf(title, "%.2lf GB / %.2lf GB", (mem_total - mem_avail) / 1024 / 1024,
                                (mem_total) / 1024 / 1024);

    app_indicator_set_label(indicator, title, NULL);
    fflush(file);
    rewind(file);
    return 1;
}
