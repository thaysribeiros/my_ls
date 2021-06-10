# -*- Makefile -*-
CC = gcc
CFLAGS += -Wall -Wextra -Werror -g3 -fsanitize=address
LINKERFLAG = -lm
SOURCES = my_ls.h main.c init_option.c print_option.c sort_files_first.c fill_folder.c my_ls.c  my_strcmp.c sort_struct_arr.c count_files.c is_file.c my_bubble_sort.c  my_super_ls.c get_path.c my_strlen.c print_struct.c
OBJECTS = $(SOURCES: .c=.o)
TARGET = my_ls


$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	@rm -f $(TARGET) $(OBJECTS) core
