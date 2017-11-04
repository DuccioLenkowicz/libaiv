#include <aiv/error.h>
#include <stdio.h>

#define test(x) if (x())\
{\
    fprintf(stderr, "test failed while running function " #x "() at address %p line %d\n", x, __LINE__);\
    exit(1);\
\
}\

#define test_equal(x, y) {\
    int ret = x();\
    if (ret != y)\
    {\
        fprintf(stderr, "test failed while running function " #x "() at address %p line %d, expecting %d got %d\n", x, __LINE__, y, ret);\
        exit(1);\
    }\
}

#define print_list(list_ptr, data_type, print_format){\
    aiv_list_item_t *item = list_ptr->head;\
    while(item)\
    {\
        fprintf(stdout, strcat_macro(%, print_format\n), *(data_type*)item->data);\
        item = item->next;\
    }\
}\

#define strcat_macro(str1, str2) #str1 "" #str2


