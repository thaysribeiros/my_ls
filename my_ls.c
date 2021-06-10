#include "my_ls.h"

struct folder *my_ls(char* directory)
{
    int len = count_files(directory);
    struct folder *folder_arr = (struct folder*)malloc(len*sizeof(struct folder));
    int index = 0;

	struct dirent *entry; //structure type used to return information about directory entries
  struct timespec;

	DIR* folder = opendir(directory);

	while ((entry = readdir(folder))) //information about a specific entry read from a dir 
	{
        char* path = get_path(directory, entry->d_name);
        fill_folder(&folder_arr[index], entry->d_name, path);
        free(path);
        index += 1;
	}
    closedir(folder); //the loop spins as long as the value returned from readdir() isn’t NULL.
    return(folder_arr);
}
