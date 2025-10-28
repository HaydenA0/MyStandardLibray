#include "my_string.h"
#include <stdio.h>

int main(void)
{
    MyString string = new_string("");
    printf("capacity : %d\n", string.capacity);
    printf("size : %d\n", string.size);
    insert_char(&string, '2', 0);
    printf("capacity : %d\n", string.capacity);
    printf("size : %d\n", string.size);
    temp_print_string(&string);
    destroy_string(&string);

    return 0;
}
