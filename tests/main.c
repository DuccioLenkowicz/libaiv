#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void test_list_run();
void test_dict_run();

int main(int argc, char **argv)
{
    srand((unsigned)time(NULL));
    rand();
    test_list_run();
    test_dict_run();

    fprintf(stdout, "all tests passed\n");
}