#include "my_ls.h"


void fill_folder(struct folder* current_entry, char* name, char* path) 
{
    struct stat filestat;
    struct timespec;

    stat(path, &filestat);
    current_entry->file = strdup(name);
    current_entry->time = filestat.st_mtim.tv_sec;
    current_entry->nanosec = filestat.st_mtim.tv_nsec;
}
