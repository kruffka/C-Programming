#include <stdio.h>
#include <stdlib.h> // <malloc.h>

int main(void) {

	int arr[3]; // {int[0], int[1], int[2]}
    arr[0] = 123;
    arr[1] = 111;
    arr[2] = 42;
    printf("%d %d %d\n", arr[0], arr[1], arr[2]);

    arr[3] = 0; // <-- buffer overflow

    int arr2[] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
        printf("[%d] = %d\n", i, arr2[i]);
    }
	
    int n = 5; // 4 byte
	printf("n = %d; addr of n = %p\n", n, &n);

	int *ptr = NULL; 
	//*ptr = 3; // segmentation fault

    ptr = &n;
	printf("n value = %d, n addr = %p; ptr value = %p, ptr addr = %p\n", n, &n, ptr, &ptr);


    /*     ___________________________________________________
		   |	            							     |
		   |                                                 V
-----------|---------------|-------------------------------|---------------|--
  ..|  |   | p |   |   |   |   |   |   |   |   |   |   |   | n |   |   |   |..
-----------|---------------|-------------------------------|---------------|--
	     100 101 102 103 104							 112 113 114 115 116
			   
		int n = 5;
		int *p;   // sizeof(p) = sizeof(int *) = sizeof(ptr) = 4 or 8 byte (x86_32 or x86_64)
		p = &n;   // p = addr of n
		*p = 123; // dereference pointer p

	*/

	printf("n = %d\n", n);

	*ptr = 123;
	printf("n = %d\n", n);

	// &arr[0] == arr; arr[0] == *arr;
	printf("arr[2] = %d *(arr+2) = %d\n", arr[2], *(arr + 2));

	printf("Array:\n");
	for (int i = 0; i < 3; i++) {
		printf("[%d] %d == %d\n", i, arr[i], *(arr + i));
	}

    int size_of_array = 4;
	int *dyn_arr = (int *)malloc(size_of_array * sizeof(int));
    if (dyn_arr == NULL) {
        printf("error in malloc\n");
        exit(1);
    }
    // calloc()
	// realloc()
    for (int i = 0; i < size_of_array; i++) {
        dyn_arr[i] = i;
        printf("%d ", dyn_arr[i]);
    }
	printf("\n");
	free(dyn_arr);
    dyn_arr = NULL;
}