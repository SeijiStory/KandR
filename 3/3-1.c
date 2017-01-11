#include <stdio.h>
#define ARRAY_SIZE(x) (sizeof((x))/sizeof(*(x)))

int binsearch(int x, int v[], int n);
int main(int argc, char **argv)
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printf("%d\n", binsearch(7, arr, ARRAY_SIZE(arr)));
	printf("%d\n", binsearch(10, arr, ARRAY_SIZE(arr)));
	printf("%d\n", binsearch(1, arr, ARRAY_SIZE(arr)));
	printf("%d\n", binsearch(0, arr, ARRAY_SIZE(arr)));
	printf("%d\n", binsearch(11, arr, ARRAY_SIZE(arr)));
	return 0;
}

int binsearch(int x, int v[], int n)
{
	int low = 0;
	int high = n - 1;
	int mid;
	while (low < high) {
		mid = (low+high)/2;
		if (x <= v[mid])
			high = mid;
		else
			low = mid + 1;
	}
	if (v[high] == x)
		return high;
	return -1;
}
