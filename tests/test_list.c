#include "test.h"
#include <aiv/list.h>

int test_aiv_list_new()
{
    aiv_list_t *list = aiv_list_new(NULL);
    if (!list)
        return -1;

    aiv_list_destroy(list);
    return 0;
}

/*
int test_aiv_list_init()
{
    struct aiv_list list;

    struct aiv_list_item items[100];

    aiv_list_init(&list, items, NULL);

    aiv_list_init(&list, NULL);

    aiv_list_init(&list, NULL);

    return 0;
}*/


int test_aiv_list_append()
{
    aiv_list_t *list = aiv_list_new(NULL);

    if (!list)
        return -1;

    int element = 5;

    int ret = aiv_list_append(list, &element);
    aiv_list_destroy(list);
    return ret;
}

int test_aiv_list_append_null()
{
    aiv_list_t *list = aiv_list_new(NULL);

    if (!list)
        return -1;

    int ret = aiv_list_append(list, NULL);
    aiv_list_destroy(list);
    return ret;
}

int test_aiv_list_remove_empty()
{
    aiv_list_t *list = aiv_list_new(NULL);

    if(!list)
        return -1;
    
    int ret = aiv_list_remove(list, NULL);
    aiv_list_destroy(list);
    return ret;
}

int test_aiv_list_remove()
{
    aiv_list_t *list = aiv_list_new(NULL);

    if(!list)
        return -1;

    int a = 3;
    int ret = aiv_list_append(list, &a);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }
    ret = aiv_list_remove(list, &a);
    aiv_list_destroy(list);
    return ret;
}

int test_aiv_list_remove_two()
{
    aiv_list_t *list = aiv_list_new(NULL);

    if(!list)
        return -1;

    int a = 3;
    const char* c = "ciao";
    int ret = 0;

    ret = aiv_list_append(list, &a);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    ret = aiv_list_append(list, (void *)c);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    ret = aiv_list_remove(list, &a);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    ret = aiv_list_remove(list, (void *)c);
    aiv_list_destroy(list);
    return ret;
}

int test_aiv_list_remove_non_exsistent()
{
    aiv_list_t *list = aiv_list_new(NULL);

    if(!list)
        return -1;

    int a = 3;
    const char* c = "ciao";
    int ret = 0;

    ret = aiv_list_append(list, &a);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    ret = aiv_list_remove(list, &a);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    ret = aiv_list_remove(list, (void *)c);
    aiv_list_destroy(list);
    return ret;
}

int test_aiv_list_remove_index_empty()
{
    aiv_list_t *list = aiv_list_new(NULL);
    
        if(!list)
            return -1;

    int ret = aiv_list_remove_index(list, 100);
    aiv_list_destroy(list);
    return ret;
}

int test_aiv_list_remove_index()
{
    aiv_list_t *list = aiv_list_new(NULL);
    
        if(!list)
            return -1;

    int ret = 0;
    int a = 768;

    ret = aiv_list_append(list, &a);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    ret = aiv_list_remove_index(list, 0);
    aiv_list_destroy(list);
    return ret;
}

int test_aiv_list_remove_index_two()
{
    aiv_list_t *list = aiv_list_new(NULL);
    if(!list)
        return -1;

    int ret = 0;
    int a = 768;
    const char* c = "hello";

    ret = aiv_list_append(list, (void*)c);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    ret = aiv_list_remove_index(list, 0);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    ret = aiv_list_append(list, &a);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    ret = aiv_list_remove_index(list, 0);
    aiv_list_destroy(list);
    return ret;
}

int test_aiv_list_iter()
{   

    aiv_list_t *list = aiv_list_new(NULL);
    if(!list)
        return -1;

    aiv_list_item_t *context = NULL;
    aiv_list_item_t *item = NULL;
    int counter = 0;

    int a = 345;

    int ret = aiv_list_append(list, &a);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    while((item = aiv_list_iter(list, &context)))
    {
        counter++;
    }

    aiv_list_destroy(list);
    return counter;
}

int test_aiv_list_shuffle()
{
    aiv_list_t *list = aiv_list_new(NULL);
    if(!list)
        return -1;

    int a = 0;
    int b = 1;
    int c = 2;
    int d = 3;
    int e = 4;
    int f = 5;
    int g = 6;
    int h = 7;
    int i = 8;

    int ret = 0;

    ret = aiv_list_insert(list, 0, &a);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }
    ret = aiv_list_append(list, &b);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }
    ret = aiv_list_append(list, &c);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }
    ret = aiv_list_append(list, &d);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }
    ret = aiv_list_append(list, &e);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    ret = aiv_list_append(list, &f);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }
    ret = aiv_list_append(list, &g);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }
    ret = aiv_list_append(list, &h);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }
    ret = aiv_list_append(list, &i);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }


    aiv_list_shuffle(list);

    // print_list(list, int, d);

    aiv_list_destroy(list);

    return ret;
}

static int int_sort(void *left, void *right)
{
    //equal
    if(*(int*)left == *(int*)right)
        return 0;
    //left must come first
    if(*(int*)left < *(int*)right)
        return -1;
    //right must come first
    if(*(int*)left > *(int*)right)
        return 1;

    return 0;
}

int test_aiv_list_sort()
{
    aiv_list_t *list = aiv_list_new(NULL);
    if(!list)
        return -1;

    int a = 3;
    int b = 100;
    int c = 6;
    int d = -5;
    int e = 4;
    int f = 41;
    int g = 7;
    int h = 56;
    int i = 0;

    int ret = 0;

    ret = aiv_list_append(list, &a);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }
    ret = aiv_list_append(list, &b);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }
    ret = aiv_list_append(list, &c);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }
    ret = aiv_list_append(list, &d);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }
    ret = aiv_list_append(list, &e);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    ret = aiv_list_append(list, &f);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }
    ret = aiv_list_append(list, &g);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }
    ret = aiv_list_append(list, &h);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }
    ret = aiv_list_append(list, &i);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }


    aiv_list_sort(list, NULL);

    aiv_list_item_t *item = list->head;
    while(item)
    {
        if(!item->next) break;
        void *current = item->data;
        void *next    = item->next->data;
        if(current > next)
        {
            return -1;
        }
        item = item->next;
    }

    aiv_list_sort(list, int_sort);

    item = list->head;
    while(item)
    {
        if(!item->next) break;
        int current = *((int *)item->data);
        int next    = *((int *)item->next->data);
        if(current > next)
        {
            return -1;
        }
        item = item->next;
    }

    aiv_list_destroy(list);

    return ret;
}
//TODO : insert uniq, contains, contains at, len, slow len, sublist
int test_aiv_list_insert_empty_at_head()
{
    aiv_list_t *list = aiv_list_new(NULL);
    if(!list)
        return -1;
    
    const char *c = "a";

    int ret = aiv_list_insert(list, 0, &c);

    aiv_list_destroy(list);

    return ret;
}

int test_aiv_list_insert_empty_out_of_range()
{
    aiv_list_t *list = aiv_list_new(NULL);
    if(!list)
        return -1;
    
    const char *c = "a";

    int ret = aiv_list_insert(list, 1, &c);

    aiv_list_destroy(list);

    return ret;
}

int test_aiv_list_insert()
{
    aiv_list_t *list = aiv_list_new(NULL);
    if(!list)
        return -1;

    int a = 3;
    int b = 100;
    int c = 6;
    int d = -5;
    int e = 4;
    int f = 41;
    int g = 7;
    int h = 56;
    int i = 0;

    int ret = 0;

    ret = aiv_list_insert(list, 0, &a);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    ret = aiv_list_insert(list, 1, &b);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    ret = aiv_list_insert(list, 2, &c);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    ret = aiv_list_insert(list, 1, &d);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    ret = aiv_list_insert(list, 4, &d);

    aiv_list_destroy(list);

    return ret;
}

int test_aiv_list_insert_out_of_range()
{
    aiv_list_t *list = aiv_list_new(NULL);
    if(!list)
        return -1;

    int a = 3;
    int b = 100;
    int c = 6;
    int d = -5;
    int e = 4;
    int f = 41;
    int g = 7;
    int h = 56;
    int i = 0;

    int ret = 0;

    ret = aiv_list_insert(list, 0, &a);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    ret = aiv_list_insert(list, 1, &b);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    ret = aiv_list_insert(list, 2, &c);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    ret = aiv_list_insert(list, 1, &d);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    ret = aiv_list_insert(list, 10, &d);

    aiv_list_destroy(list);

    return ret;
}

int test_aiv_list_insert_uniq_empty_at_head()
{
    aiv_list_t *list = aiv_list_new(NULL);
    if(!list)
        return -1;
    
    const char *c = "a";

    int ret = aiv_list_insert_uniq(list, 0, &c);

    aiv_list_destroy(list);

    return ret;
}

int test_aiv_list_insert_uniq_empty_out_of_range()
{
    aiv_list_t *list = aiv_list_new(NULL);
    if(!list)
        return -1;
    
    const char *c = "a";

    int ret = aiv_list_insert_uniq(list, 1, &c);

    aiv_list_destroy(list);

    return ret;
}

int test_aiv_list_insert_uniq()
{
    aiv_list_t *list = aiv_list_new(NULL);
    if(!list)
        return -1;
    
    int a = 3;
    int b = 100;

    int ret = 0;

    ret = aiv_list_insert_uniq(list, 0, &a);
    if(ret)
    {
        aiv_list_destroy(list);
        return ret;
    }

    ret = aiv_list_insert_uniq(list, 1, &b);

    aiv_list_destroy(list);
    return ret;
}

void test_list_run()
{
    test(test_aiv_list_new);
    test(test_aiv_list_append);
    test(test_aiv_list_append_null);
    test_equal(test_aiv_list_remove_empty, AIV_NOT_FOUND);
    test(test_aiv_list_remove);
    test(test_aiv_list_remove_two);
    test_equal(test_aiv_list_remove_non_exsistent, AIV_NOT_FOUND);
    test_equal(test_aiv_list_remove_index_empty, AIV_NOT_FOUND);
    test(test_aiv_list_remove_index);
    test(test_aiv_list_remove_index_two);
    test_equal(test_aiv_list_iter, 1);
    test(test_aiv_list_shuffle);
    test(test_aiv_list_sort);
    test(test_aiv_list_insert_empty_at_head);
    test_equal(test_aiv_list_insert_empty_out_of_range, AIV_NOT_FOUND);
    test(test_aiv_list_insert);
    test_equal(test_aiv_list_insert_out_of_range, AIV_NOT_FOUND);
    test(test_aiv_list_insert_uniq_empty_at_head);
    test_equal(test_aiv_list_insert_uniq_empty_out_of_range, AIV_NOT_FOUND);
    test(test_aiv_list_insert_uniq);
}