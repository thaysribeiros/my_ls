#include "my_ls.h"

char* my_strcpy(char* dst, char* src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dst[i] = src[i];
        i +=1;
    }
    dst[i] = '\0';
    return dst; 
}
char* my_strcat(char* destination, const char* source)
{
	//Makes ptr point to the end of destination string
	char* ptr = destination + my_strlen(destination);

	//Appends characters of source to the destination string
	while (*source != '\0') {
		*ptr++ = *source++;
    }
	*ptr = '\0';
	return destination;
}

char* get_path(char* directory, char* name)
{
    size_t path_len;
    path_len = my_strlen(directory);
    char* full_name = malloc(sizeof(char*) * _POSIX_PATH_MAX + 1);

    my_strcpy(full_name, directory);
    if (full_name[path_len - 1] != '/')
    {
        my_strcat(full_name, "/");
    }
    my_strcat(full_name, name);
    return full_name;
}
