#include "../my_string.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_creation_and_destruction()
{
    printf("--- Running Creation and Destruction Tests ---\n");

    MyString s1 = new_string("hello world");
    assert(s1.size == 11);
    assert(s1.capacity >= 11);
    assert(strcmp(s1.string_proper, "hello world") == 0);
    destroy_string(&s1);
    assert(s1.size == 0);
    assert(s1.capacity == 0);

    MyString s2 = new_string("");
    assert(s2.size == 0);
    assert(s2.capacity >= 0);
    assert(strcmp(s2.string_proper, "") == 0);
    destroy_string(&s2);
    assert(s2.size == 0);
    assert(s2.capacity == 0);

    MyString s3 = new_string("a\0b");
    assert(s3.size == 1);
    assert(strcmp(s3.string_proper, "a") == 0);
    destroy_string(&s3);

    printf("Creation and Destruction Tests Passed.\n\n");
}

void test_copying()
{
    printf("--- Running Copy Tests ---\n");

    MyString s1 = new_string("original");
    MyString s2 = copy_string(&s1);

    assert(s1.size == s2.size);
    assert(s1.capacity == s2.capacity);
    assert(strcmp(s1.string_proper, s2.string_proper) == 0);
    assert(s1.string_proper != s2.string_proper);

    append_literal(&s1, " changed");
    assert(strcmp(s1.string_proper, "original changed") == 0);
    assert(strcmp(s2.string_proper, "original") == 0);

    destroy_string(&s1);
    destroy_string(&s2);

    MyString empty_orig = new_string("");
    MyString empty_copy = copy_string(&empty_orig);
    assert(empty_copy.size == 0);
    assert(strcmp(empty_copy.string_proper, "") == 0);
    destroy_string(&empty_orig);
    destroy_string(&empty_copy);

    printf("Copy Tests Passed.\n\n");
}

void test_comparison()
{
    printf("--- Running Comparison Tests ---\n");
    MyString s1 = new_string("hello");
    MyString s2 = new_string("hello");
    MyString s3 = new_string("world");
    MyString s4 = new_string("hell");
    MyString s5 = new_string("hello ");
    MyString s6 = new_string("");

    assert(compare_strings(&s1, &s2) == 1);
    assert(compare_strings(&s1, &s1) == 1);
    assert(compare_strings(&s1, &s3) == 0);
    assert(compare_strings(&s1, &s4) == 0);
    assert(compare_strings(&s1, &s5) == 0);
    assert(compare_strings(&s1, &s6) == 0);
    assert(compare_strings(&s6, &s6) == 1);

    destroy_string(&s1);
    destroy_string(&s2);
    destroy_string(&s3);
    destroy_string(&s4);
    destroy_string(&s5);
    destroy_string(&s6);

    printf("Comparison Tests Passed.\n\n");
}

void test_appending()
{
    printf("--- Running Appending Tests ---\n");

    MyString s1 = new_string("start");
    append_literal(&s1, "-middle");
    assert(s1.size == 12);
    assert(strcmp(s1.string_proper, "start-middle") == 0);

    MyString s2 = new_string("-end");
    append_string(&s1, &s2);

    assert(s1.size == 16);
    assert(strcmp(s1.string_proper, "start-middle-end") == 0);

    append_literal(&s1, "");

    assert(s1.size == 16);
    assert(strcmp(s1.string_proper, "start-middle-end") == 0);

    MyString s_empty = new_string("");
    append_string(&s1, &s_empty);

    assert(s1.size == 16);

    append_string(&s_empty, &s1);
    assert(s_empty.size == s1.size);
    assert(compare_strings(&s_empty, &s1));

    destroy_string(&s1);
    destroy_string(&s2);
    destroy_string(&s_empty);

    printf("Appending Tests Passed.\n\n");
}
void test_modification()
{
    printf("--- Running Modification Tests ---\n");

    MyString s1 = new_string("Hllo");
    int result = insert_char(&s1, 'e', 1);
    assert(result == 0);
    assert(s1.size == 5);
    assert(strcmp(s1.string_proper, "Hello") == 0);

    result = insert_char(&s1, '!', 5);
    assert(result == 0);
    assert(s1.size == 6);
    assert(strcmp(s1.string_proper, "Hello!") == 0);

    result = insert_char(&s1, 'C', 0);
    assert(result == 0);
    assert(s1.size == 7);
    assert(strcmp(s1.string_proper, "CHello!") == 0);

    result = insert_char(&s1, 'X', -1);
    assert(result == 1);
    assert(s1.size == 7);

    result = insert_char(&s1, 'Y', 8);
    assert(result == 1);
    assert(s1.size == 7);

    replace_char(&s1, 'l', 'L');
    assert(strcmp(s1.string_proper, "CHeLLo!") == 0);

    replace_char(&s1, 'Z', 'X');
    assert(strcmp(s1.string_proper, "CHeLLo!") == 0);

    destroy_string(&s1);

    MyString s_empty = new_string("");
    result = insert_char(&s_empty, 'A', 0);
    assert(result == 0);
    assert(s_empty.size == 1);
    destroy_string(&s_empty);

    printf("Modification Tests Passed.\n\n");
}

void test_limits()
{
    printf("--- Running Limit and Stress Tests ---\n");

    printf("Testing repeated appends...\n");
    MyString s_append = new_string("");
    for (int i = 0; i < 20000; i++)
    {
        int res = append_literal(&s_append, "a");
        assert(res == 0);
    }
    assert(s_append.size == 20000);
    assert(s_append.string_proper[0] == 'a');
    assert(s_append.string_proper[19999] == 'a');
    destroy_string(&s_append);

    printf("Testing repeated insertions (worst case)...\n");
    MyString s_insert = new_string("");
    for (int i = 0; i < 2000; i++)
    {
        int res = insert_char(&s_insert, 'x', 0);
        assert(res == 0);
    }
    assert(s_insert.size == 2000);
    assert(s_insert.string_proper[0] == 'x');
    assert(s_insert.string_proper[1999] == 'x');
    destroy_string(&s_insert);

    printf("Testing large string creation...\n");
    size_t large_size = 5 * 1024 * 1024;
    char *large_buffer = (char *)malloc(large_size + 1);
    assert(large_buffer != NULL);
    memset(large_buffer, 'B', large_size);
    large_buffer[large_size] = '\0';

    MyString s_large = new_string(large_buffer);
    assert(s_large.size == large_size);
    assert(s_large.string_proper[0] == 'B');
    assert(s_large.string_proper[large_size - 1] == 'B');

    printf("Testing large string append...\n");
    MyString s_large_append = new_string("start");
    int res = append_literal(&s_large_append, large_buffer);
    assert(res == 0);
    assert(s_large_append.size == 5 + large_size);
    assert(strncmp(s_large_append.string_proper, "start", 5) == 0);
    assert(s_large_append.string_proper[5] == 'B');
    assert(s_large_append.string_proper[s_large_append.size - 1] == 'B');

    free(large_buffer);
    destroy_string(&s_large);
    destroy_string(&s_large_append);

    printf("Limit and Stress Tests Passed.\n\n");
}

int main()
{
    printf("Starting MyString library test suite.\n\n");

    test_creation_and_destruction();
    test_copying();
    test_comparison();
    test_appending();
    test_modification();
    test_limits();

    printf("======================================\n");
    printf("All MyString tests passed successfully!\n");
    printf("======================================\n");

    return 0;
}
