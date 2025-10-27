// my_string.c
#include <stdio.h>
#include <stdlib.h>
typedef struct MyString {

  char *string_proper;
  int size;
  int capacity;

} MyString;
int calculate_string_length(char *string) {
  int length = 0;
  while (string[length] != '\0') {
    length++;
  }
  return length;
}

MyString error_string();

MyString new_string(char *string) {
  int length = calculate_string_length(string);
  MyString new_string;
  new_string.size = length;
  new_string.capacity = 2 * new_string.size;
  new_string.string_proper = (char *)malloc(sizeof(char) * new_string.capacity);
  for (int i = 0; i < new_string.size; i++) {
    new_string.string_proper[i] = string[i];
  }
  new_string.string_proper[new_string.size] = '\0';
  return new_string;
}

void destroy_string(MyString *string) {
  free(string->string_proper);
  string->capacity = 0;
  string->size = 0;
}

void temp_print_string(MyString *string) {

  for (int i = 0; i < string->size; ++i) {
    printf("%c", string->string_proper[i]);
  }
  printf("\n");
}

MyString copy_string(MyString *string_to_copy) {
  MyString copied_string;
  copied_string.capacity = string_to_copy->capacity;
  copied_string.size = string_to_copy->size;
  copied_string.string_proper =
      (char *)malloc(sizeof(char) * copied_string.capacity);
  for (int i = 0; i < copied_string.size; i++) {
    copied_string.string_proper[i] = string_to_copy->string_proper[i];
  }
  copied_string.string_proper[copied_string.size] = '\0';
  return copied_string;
}

int append_literal(MyString *string, char *string_to_append) {

  int string_to_append_size = calculate_string_length(string_to_append);
  int new_size = string_to_append_size + string->size;
  int old_size = string->size;
  if (new_size >= string->capacity) {
    string->capacity = new_size * 2;
    char *new_buffer = (char *)realloc(string->string_proper, string->capacity);
    if (new_buffer == NULL) {
      return 1;
    }
    string->size = new_size;
    string->string_proper = new_buffer;
  }
  for (int i = 0; i < string_to_append_size; i++) {
    string->string_proper[old_size + i] = string_to_append[i];
  }
  string->size = new_size;
  string->string_proper[string->size] = '\0';
  return 0;
}

int compare_strings(MyString *string1, MyString *string2) {
  if (string1->size != string2->size) {
    return 0;
  }
  for (int i = 0; i < string1->size; i++) {
    if (string1->string_proper[i] != string2->string_proper[i]) {
      return 0;
    }
  }
  return 1;
}

int append_string(MyString *string, MyString *string_to_append) {
  return append_literal(string, string_to_append->string_proper);
}

int insert_char(MyString *string, char character, int index) {
  if (index < 0 || index > string->size) {
    return 1;
  }
  if (string->size + 1 >= string->capacity) {
    string->capacity *= 2;
    char *new_buffer = (char *)realloc(string->string_proper, string->capacity);
    if (new_buffer == NULL) {
      return 1;
    }
    string->string_proper = new_buffer;
  }
  for (int i = string->size; i > index; i--) {
    string->string_proper[i] = string->string_proper[i - 1];
  }
  string->string_proper[index] = character;
  string->size++;
  string->string_proper[string->size] = '\0';
  return 0;
}

int replace_char(MyString *string, char old_character, char new_character) {
  for (int i = 0; i < string->size; i++) {
    if (string->string_proper[i] == old_character) {
      string->string_proper[i] = new_character;
    }
  }
  return 0;
}
