#include "my_ls.h"

void print_struct(struct folder *folder_arr, struct ls_option *option, int len)
{
    int i = 0;
    while (i < len)
    {
        if (option->option_a == true)
        {
            printf("%s  ", folder_arr[i].file);
            i += 1;
        }
        else
        {
            if (folder_arr[i].file[0] != '.')
            {
                printf("%s  ", folder_arr[i].file);
            }
            i += 1;
        }
    }
}
