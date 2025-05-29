#include <stdio.h>
#include <stdbool.h>
#include <m-list.h>

LIST_DEF(list_int, int)

int main(void)
{
	printf("Hello, world!\n");
    list_int_t l;
    list_int_init(l);
    list_int_push_back(l, 1);
    list_int_push_back(l, 2);
    list_int_push_back(l, 3);
	
    for (int i = 0; i < list_int_size(l); ++i) {
        printf("%d\n", *list_int_get(l, i));
    }

	return 0;
}
