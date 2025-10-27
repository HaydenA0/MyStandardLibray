#include <stdlib.h>
#include <string.h>
typedef struct DArray {
  unsigned char *data;
  unsigned int element_size;
  unsigned int size;
  unsigned int capacity;
} Darray;
void darray_set_element(unsigned char *data, unsigned int index,
                        unsigned int element_size, void *value) {
  memcpy(data + index * element_size, value, element_size);
}
Darray new_uninit_array(unsigned int element_size, unsigned int size) {
  Darray uninitialized_array;
  uninitialized_array.size = size;
  uninitialized_array.capacity = 2 * (uninitialized_array.size + 1);
  uninitialized_array.element_size = element_size;

  uninitialized_array.data = (unsigned char *)malloc(
      uninitialized_array.element_size * uninitialized_array.size);

  return uninitialized_array;
}
Darray same_value_init_array(unsigned int element_size, unsigned int size,
                             void *init_value) {
  Darray output_array;
  output_array.size = size;
  output_array.capacity = 2 * (output_array.size + 1);
  output_array.element_size = element_size;

  output_array.data =
      (unsigned char *)malloc(output_array.element_size * output_array.size);
  for (int i = 0; i < output_array.size; i++) {
    darray_set_element(output_array.data, i, output_array.element_size,
                       init_value);
  }
  return output_array;
}
