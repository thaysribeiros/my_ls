#ifndef MY_LS_H
#define MY_LS_H
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <errno.h>
#include <sys/time.h>

struct folder {
    long unsigned time;
    time_t nanosec;
    char* file;
};

struct ls_option {
    bool option_a; 
    bool option_t;
    bool error_option; 
    bool error_dir_file;
    char** directories;
};

int init_option(int ac, char** av, struct ls_option *option);
int my_strcmp(char* str1, char* str2);
int is_file(const char* file);
void print_option(struct ls_option *option);
void my_super_ls(struct ls_option *option, char* directory);
int my_strlen(char* str);
char* get_path(char* directory, char* name);
void fill_folder(struct folder* current_entry, char* name, char* path);
int count_files(char* directory);
struct folder *my_ls(char* directory);
void my_bubble_sort(struct folder *folder_arr, int n);
void sort_struct_arr(struct folder *folder_arr, int files_count);
void print_struct(struct folder *folder_arr, struct ls_option *option, int len);
void sort_files_first(struct ls_option option, int len);
void print_struct(struct folder *folder_arr, struct ls_option *option, int len);

#endif
