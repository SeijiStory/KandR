#include <stdio.h>

int main(int argc, char **argv)
{
	double fahr;
	double celsius;
	double lower = 0;
	double upper = 300;
	double step = 20;
	celsius = lower;
	printf("Celsius\tFahrenheit\n");
	while (celsius <= upper) {
		fahr = (9.0 * celsius + 160) / 5.0;
		printf("%7.0f\t%10.1f\n", celsius, fahr);
		celsius += step;
	}
	return 0;
}
