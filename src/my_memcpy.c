#include <stdlib.h>
int my_memcpy(unsigned char *destination, const unsigned char *source, const unsigned int size)
{
    if (destination == NULL || source == NULL)
    {
        return 1;
    }
    for (int i = 0; i < size; i++)
    {
        destination[i] = source[i];
    }
    return 0;
}
