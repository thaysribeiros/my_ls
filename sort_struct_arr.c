#include "my_ls.h"

void sort_struct_arr(struct folder *folder_arr, int files_count)
{
    int i = 0;
    int j;
    char* temp; 

    while (i < files_count)
    {
        j = i+1;
        while (j < files_count)
        {
            if (my_strcmp(folder_arr[i].file, folder_arr[j].file) >= 1)
            {
                temp = folder_arr[i].file;
                folder_arr[i].file = folder_arr[j].file;
                folder_arr[j].file = temp;
            }
            j += 1;
        }
        i += 1;
    }
}
