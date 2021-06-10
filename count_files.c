#include "my_ls.h"

int count_files(char* directory)
{
    struct dirent *entry;
    int nbr_files = 0;

    DIR *folder = opendir(directory);
    while ((entry = readdir(folder)))
    {
        nbr_files +=1;
    }
    closedir(folder);
    return nbr_files;
}
