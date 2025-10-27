#include "my_io.h"
#include "my_string.h"
int main(void)
{

    int file_d = my_open("file", 'o');
    {
        MyString new_line = new_string("This is the header \n");
        my_write_file(&new_line, file_d);
        destroy_string(&new_line);
    }
    MyString new_line = new_string("This is a line \n");
    for (int i = 0; i < 13; i++)
    {
        my_write_append(&new_line, file_d);
    }
    my_close(file_d);
    destroy_string(&new_line);

    return 0;
}
