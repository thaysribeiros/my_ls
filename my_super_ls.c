#include "my_ls.h"

void free_folder(struct folder* folder_arr, int len)
{
    int i = 0;
    while (i < len)
    {
        free(folder_arr[i].file);
        i += 1;
    }
    free(folder_arr);
}

void my_super_ls(struct ls_option *option, char* directory)
{
    int len = 0;
    struct folder *folder_arr = NULL;

    if (is_file(directory)) 
    {
        char* filename = directory;
        char* path = get_path(directory, filename);
        directory = ".";
        len = 1;
        folder_arr = malloc(len*sizeof(struct folder));
        fill_folder(&folder_arr[0], filename, path);
        free(path);
    }
    else 
    {
        len = count_files(directory);
        folder_arr = my_ls(directory);
    }
    if (option->option_t == true)
    {
        my_bubble_sort(folder_arr, len);
    }
    else 
    {
        sort_struct_arr(folder_arr, len);
    }
    print_struct(folder_arr, option, len);
    free_folder(folder_arr, len);
}
