#include "my_ls.h"

//This is a function for debugging purposes
char* bool_to_string(bool value) 
{
    static char* false_str = "FALSE";
    static char* true_str  = "TRUE";

    if (value) {
        return true_str;
    }
    else {
        return false_str;
    }
}

void print_option(struct ls_option *option) 
{
    printf("Option A -> %s\n", bool_to_string(option->option_a));
    printf("Option T -> %s\n", bool_to_string(option->option_t));
    printf("Option ERROR_OPTION -> %s\n", bool_to_string(option->error_option));
    printf("Option ERROR_DIR_FILE -> %s\n", bool_to_string(option->error_dir_file));

    if (option->directories) {
        int index = 0;

        while (option->directories[index]) {
            printf("directory[%d] => %s\n", index, option->directories[index]);
            index += 1;
        }
    }
    else {
        printf("No directory\n");
    }
}
