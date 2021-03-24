#include <stdio.h>

int main()
{
	int a = 5 ;
	int* b_ptr = &a ;	
	int** c_ptr = &b_ptr ;
    *b_ptr = 6; // a = 6
    int* d_ptr = b_ptr;
    *d_ptr = 8; // a = 8
	print (**c_ptr)  ;  
}