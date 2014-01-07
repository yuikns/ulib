#include <stdio.h>
#include <assert.h>
#include <ulib/dp_lis.h>

using namespace ulib;

int main()
{
	int test1[] = { 0, 2, 1, 3, 5, 3, 2, 4 };
	int test2[] = { 4, 5, 2, 3 };
	int test3[] = { 1, 2, 3, 4, -1, -2, -3, -4, -7, -6, 2, -5, -1, -4, -3, -2, -1, 0 };

	int result[1024];

	assert(dp_lis<int>(test1, NULL, sizeof(test1)/sizeof(test1[0])) == 4);
	assert(dp_lis<int>(test1, result, sizeof(test1)/sizeof(test1[0])) == 4);
	assert(result[0] == 0 && result[1] == 1 && result[2] == 2 && result[3] == 4);
	assert(dp_lis<int>(test2, result, sizeof(test2)/sizeof(test2[0])) == 2);
	assert(result[0] == 2 && result[1] == 3);
	assert(dp_lis<int>(test3, result, sizeof(test3)/sizeof(test3[0])) == 8);
	assert(result[0] == -7 && result[1] == -6 && result[2] == -5 && result[3] == -4 &&
	       result[4] == -3 && result[5] == -2 && result[6] == -1 && result[7] == 0);

	printf("passed\n");

	return 0;
}
