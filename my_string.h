// my_string.h
#ifndef STRING_WRAPPER_H
#define STRING_WRAPPER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct MyString {
  char *string_proper;
  int size;
  int capacity;
} MyString;

int calculate_string_length(char *string);

MyString new_string(char *string);

void destroy_string(MyString *string);

void temp_print_string(MyString *string);

MyString copy_string(MyString *string_to_copy);
int append_literal(MyString *string, char *string_to_append);
int compare_strings(MyString *string1, MyString *string2);
int append_string(MyString *string, MyString *string_to_append);
int insert_char(MyString *string, char character, int index);
int replace_char(MyString *string, char old_character, char new_character);

#endif
