#include <stdio.h>

int main()
{
	int* arr = calloc(sizeof(int), 5);
	for (int i = 0; i < 5; i++)
		arr[i] = i * i;
	int* ptr = malloc(sizeof(int));
	int** ptr_to_ptr;
	ptr = 2;
	ptr_to_ptr = &ptr;


	return 0;
}