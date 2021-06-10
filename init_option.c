#include "my_ls.h"

int init_option(int ac, char** av, struct ls_option *option)
{
    option->option_a = false;
    option->option_t = false;
    option->error_option = false; 
    option->error_dir_file = false;
    option->directories = NULL;

    int i = 1;

    while (i < ac && av[i][0] == '-')
    {     
        if (my_strcmp(av[i], "-a") == 0 || my_strcmp(av[i], "-at") == 0 || my_strcmp(av[i], "-ta") == 0)
        {
            option->option_a = true; 
        }
        if (my_strcmp(av[i], "-t") == 0 || my_strcmp(av[i], "-at") == 0 || my_strcmp(av[i], "-ta") == 0)
        {
            option->option_t = true;
        }
        if (my_strcmp(av[i], "-t") != 0 && my_strcmp(av[i], "-a") != 0 && my_strcmp(av[i], "-at") != 0 && my_strcmp(av[i], "-ta") != 0)
        {
            option->error_option = true; 
            printf("my_ls: invalid option -- '%s'\n", av[i]);
            printf("Try 'my_ls --help' for more information.\n");
        }
        i += 1;
    }
    if (av[i] != NULL)
    {
        option->directories = &av[i];
        while (av[i] != NULL)
        { 
            if(is_file(av[i]) == -1)
            {
                option->error_dir_file = true;
                printf("my_ls: cannot access '%s': No such file or directory\n", av[i]);
            }
            i += 1;
        }
    }
    return 0;
}
