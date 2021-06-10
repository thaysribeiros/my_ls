#include "my_ls.h"

int array_len(struct ls_option option)
{
    int i = 0;
    while (option.directories[i] != NULL)
    {
        i += 1;
    }
    return i;
}

int main(int ac, char** av)
{
    struct ls_option option;
    
    init_option(ac, av, &option);
    //print_option(&option); //for debugguing purposes
    if (option.error_option == true)
    {
        return EXIT_FAILURE;
    }
    if (option.directories == NULL)
    {
        my_super_ls(&option, ".");
    }
    if (option.directories != NULL)
    {
        sort_files_first(option, array_len(option));
    }
    if (option.directories != NULL)
    {
        int index = 0;
        while (option.directories[index] != NULL)
        {
            if(is_file(option.directories[index]) != -1)
            {
                if (array_len(option) > 1 && is_file(option.directories[index]) == 0)
                {
                    printf("%s:\n", option.directories[index]);
                }
                my_super_ls(&option, option.directories[index]);
                if(index < array_len(option)-1 && is_file(option.directories[index+1]) == 0)
                {
                    printf("\n");
                    printf("\n");
                }
            }
            index += 1; 
        }
    }
    if (option.error_dir_file == true)
    {
        return EXIT_FAILURE;
    }
    else
    {
        return EXIT_SUCCESS;
    }
}
