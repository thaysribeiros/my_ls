#include "my_ls.h"

int is_file(const char* file)
{
    DIR* directory = opendir(file);

    if(directory != NULL)
    {
        closedir(directory);
        return 0;
    }
    if(errno == ENOTDIR)
    {
        return 1;
    }
    return -1;
}
