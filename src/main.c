#include "my_string.h"
#include <stdio.h>

int main(void)
{
    MyString s1 = new_string("test");
    MyString s2 = new_string("test");
    MyString s3 = new_string("Test");

    if (compare_strings(&s1, &s2))
    {
        printf("s1 and s2 are equal.\n"); // This will print
    }
    if (!compare_strings(&s1, &s3))
    {
        printf("s1 and s3 are not equal.\n"); // This will print
    }

    destroy_string(&s1);
    destroy_string(&s2);
    destroy_string(&s3);
}
