#include "my_ls.h"

void my_swap(struct folder *folder_arr1, struct folder *folder_arr2, int len)
{
    struct folder *temp = (struct folder*)malloc(len*sizeof(struct folder));

    *temp = *folder_arr1;
    *folder_arr1 = *folder_arr2;
    *folder_arr2 = *temp;
    free(temp);
}

void my_bubble_sort(struct folder *folder_arr, int n)
{
    int j;
    int do_it_again = 1;

    while (do_it_again == 1)
    {
        j = 0;
        do_it_again = 0;
        while (j < n-1)
        {
            if (folder_arr[j].time == folder_arr[j+1].time)
            {
                if (folder_arr[j].nanosec < folder_arr[j+1].nanosec)
                {
                    my_swap(&folder_arr[j], &folder_arr[j+1], n);
                    do_it_again = 1;
                }
                else if (folder_arr[j].nanosec == folder_arr[j+1].nanosec)
                {
                    if (my_strcmp(folder_arr[j].file, folder_arr[j+1].file) >= 1)
                    {
                        my_swap(&folder_arr[j], &folder_arr[j+1], n);
                        do_it_again = 1;
                    }
                }
            }            
            else if (folder_arr[j].time < folder_arr[j+1].time)
            {
                my_swap(&folder_arr[j], &folder_arr[j+1], n);
                do_it_again = 1;
            }
            j+=1;
        }
    }
}
