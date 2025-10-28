Some memory performance stuff like mystring with capcaity = size
Add this function
MyString new_string_with_capacity(int initial_capacity) {
    MyString new_string;
    new_string.size = 0;
    new_string.capacity = initial_capacity;
    new_string.string_proper = (char *)malloc(sizeof(char) * new_string.capacity);
    if (new_string.string_proper) {
         new_string.string_proper[0] = '\0';
    }
    return new_string;
}

CHeck this g_string_new_take(gchar *init) for ownership from the gnome string library
