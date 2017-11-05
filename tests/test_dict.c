#include "test.h"
#include <aiv/dict.h>

int test_dict_new()
{
    aiv_dict_t *dict = aiv_dict_new(1, NULL);
    if (!dict)
        return -1;

    return 0;
}

int test_dict_new_zero_hash_map_size()
{
    int err;
    aiv_dict_t *dict = aiv_dict_new(0, &err);
    if (!dict)
        return err;

    return -1;
}

int test_dict_add()
{

    aiv_dict_t *dict = aiv_dict_new(10, NULL);
    if (!dict)
        return -1;
    int ret = 0;
    const char *foo = "hello";
    ret = aiv_dict_add(dict, (void *)foo, strlen(foo), "bo");
    if(ret)
    {
        aiv_dict_destroy(dict);
        return ret;
    }

    const char *foo2 = "ciao";
    ret = aiv_dict_add(dict, (void *)foo2, strlen(foo2), "bo");
    if(ret)
    {
        aiv_dict_destroy(dict);
        return ret;
    }

    const char *foo3 = "hello_world";
    ret = aiv_dict_add(dict, (void *)foo3, strlen(foo3), "bo");

    aiv_dict_destroy(dict);
    return ret;
}

int test_dict_get()
{

    aiv_dict_t *dict = aiv_dict_new(10, NULL);
    if (!dict)
        return -1;
    
    int ret = 0;

    const char *foo = "hello";
    ret = aiv_dict_add(dict, (void *)foo, strlen(foo), "bo");
    if(ret)
    {
        aiv_dict_destroy(dict);
        return ret;
    }

    void *data = aiv_dict_get(dict, "hello", 5);

    if(strcmp(data, "bo"))
    {
        aiv_dict_destroy(dict);
        return -1;
    }

    aiv_dict_destroy(dict);
    return ret;

}

int test_dict_remove()
{
    aiv_dict_t *dict = aiv_dict_new(10, NULL);
    if (!dict)
        return -1;
    
    int ret = 0;

    const char *foo = "hello";
    ret = aiv_dict_add(dict, (void *)foo, strlen(foo), "bo");
    if(ret)
    {
        aiv_dict_destroy(dict);
        return ret;
    }

    void *data = aiv_dict_remove(dict, "hello", 5);

    if(strcmp(data, "bo"))
    {
        aiv_dict_destroy(dict);
        return -1;
    }

    data = aiv_dict_get(dict, "hello", 5);

    if(data)
    {
        aiv_dict_destroy(dict);
        return -1;
    }

    data = aiv_dict_remove(dict, "hello_1", 5);
    if(data)
    {
        aiv_dict_destroy(dict);
        return -1;
    }

    aiv_dict_destroy(dict);
    return ret;
}

int test_dict_len()
{
    aiv_dict_t *dict = aiv_dict_new(10, NULL);
    if (!dict)
        return -1;

    int ret = 0;
    int len = aiv_dict_len(dict);

    if(len)
    {
        aiv_dict_destroy(dict);
        return -1;
    }

    const char *foo = "hello";
    ret = aiv_dict_add(dict, (void *)foo, strlen(foo), "bo");
    if(ret)
    {
        aiv_dict_destroy(dict);
        return ret;
    }

    len = aiv_dict_len(dict);
    if(len != 1)
    {
        aiv_dict_destroy(dict);
        return -1;
    }


    const char *bar = "hello_1";
    ret = aiv_dict_add(dict, (void *)bar, strlen(bar), "bo_1");
    if(ret)
    {
        aiv_dict_destroy(dict);
        return ret;
    }

    len = aiv_dict_len(dict);
    if(len != 2)
    {
        aiv_dict_destroy(dict);
        return -1;
    }

    aiv_dict_remove(dict, "hello", 5);

    len = aiv_dict_len(dict);
    if(len != 1)
    {
        aiv_dict_destroy(dict);
        return -1;
    }

    
    aiv_dict_destroy(dict);
    return ret;
}

int test_dict_iterator()
{
    aiv_dict_t *dict = aiv_dict_new(4, NULL);
    if(!dict)
        return -1;

    int ret = 0;

    const char *foo = "hello";
    ret = aiv_dict_add(dict, (void *)foo, strlen(foo), "bo");
    if(ret)
    {
        aiv_dict_destroy(dict);
        return ret;
    }

    const char *bar = "ciao";
    ret = aiv_dict_add(dict, (void *)bar, strlen(bar), "bo");
    if(ret)
    {
        aiv_dict_destroy(dict);
        return ret;
    }

    const char *foobar = "hellociao";
    ret = aiv_dict_add(dict, (void *)foobar, strlen(foobar), "bo");
    if(ret)
    {
        aiv_dict_destroy(dict);
        return ret;
    }

    unsigned int counter = 0;

    aiv_dict_iterator_t iterator;
    aiv_dict_iterator_init(&iterator, dict);

    while(!aiv_dict_iterator_move_next(&iterator))
    {
        counter++;
        if(counter == 10)
            break;
    }

    aiv_dict_destroy(dict);
    fprintf(stdout, "%d\n", counter);
    if(counter != 3)
        ret = -1;

    return ret;
}

void test_dict_run()
{
    test(test_dict_new);
    test_equal(test_dict_new_zero_hash_map_size, AIV_INVALID_SIZE);
    test(test_dict_add);
    test(test_dict_get);
    test(test_dict_remove);
    test(test_dict_len);
    test(test_dict_iterator);
}