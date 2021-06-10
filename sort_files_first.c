#include "my_ls.h"

void sort_files_first(struct ls_option option, int len)
{
    int i;
    int do_it_again = 1; 
    char* temp;

    while (do_it_again == 1)
    {
        i = 0;
        do_it_again = 0;
        while (i < len-1)
        {
            if((is_file(option.directories[i]) == 1 || is_file(option.directories[i]) == 0) && is_file(option.directories[i+1]) == -1)
            {
                temp = option.directories[i];
                option.directories[i] = option.directories[i+1];
                option.directories[i+1] = temp;
                do_it_again = 1;
            }
            if(is_file(option.directories[i]) == 0 && is_file(option.directories[i+1]) == 1)
            {
                temp = option.directories[i];
                option.directories[i] = option.directories[i+1];
                option.directories[i+1] = temp;
                do_it_again = 1;
            }
            if(is_file(option.directories[i]) == 0 && is_file(option.directories[i+1]) == 0)
            {
                if(my_strcmp(option.directories[i], option.directories[i+1]) >= 1)
                {
                    temp = option.directories[i];
                    option.directories[i] = option.directories[i+1];
                    option.directories[i+1] = temp;
                    do_it_again = 1;
                }
            }
            if(is_file(option.directories[i]) == 1 && is_file(option.directories[i+1]) == 1)
            {
                if(my_strcmp(option.directories[i], option.directories[i+1]) >= 1)
                {
                    temp = option.directories[i];
                    option.directories[i] = option.directories[i+1];
                    option.directories[i+1] = temp;
                    do_it_again = 1;
                }
            }
            i += 1;
        }
    }
}
