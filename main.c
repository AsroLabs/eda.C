#include "lib.h"

int main()
{
	float arrayTest[] = {1, 2, 3, 4, 5};
	InsertionSort(arrayTest, sizeof(arrayTest) / sizeof(arrayTest[0]));	
	return 0;
}
