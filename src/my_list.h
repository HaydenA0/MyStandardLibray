#ifndef MY_LIST_H
#define MY_LIST_H

typedef struct Darray {
  unsigned char *data;
  unsigned int element_size;
  unsigned int size;
  unsigned int capacity;
} Darray;

void darray_set_element(unsigned char *data, unsigned int index,
                        unsigned int element_size, void *value);

Darray new_uninit_array(unsigned int element_size, unsigned int size);

Darray same_value_init_array(unsigned int element_size, unsigned int size,
                             void *init_value);

void set_element(Darray *Array, int index, void *value);

void *get_element(Darray *Array, int index);

#endif
