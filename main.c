#define i_type Floats, float // Container type (name, element type)
#include <stc/vec.h>         // "instantiate" the desired container type
#include <stdio.h>

#include <sds.h>
#include <mimalloc.h>

int main(void)
{
    Floats nums = {0};
    Floats_push(&nums, 30.f);
    Floats_push(&nums, 10.f);
    Floats_push(&nums, 20.f);

    for (int i = 0; i < Floats_size(&nums); ++i)
        printf(" %g", nums.data[i]);

    for (c_each(i, Floats, nums))     // Alternative and recommended way to iterate.
        printf(" %g", *i.ref);      // i.ref is a pointer to the current element.

    Floats_drop(&nums); // cleanup memory

	sds mystring = sdsnew("Hello World!");
	printf("%s\n", mystring);
	sdsfree(mystring);

	void* test_mi = mi_malloc(10);
}
