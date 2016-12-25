#include <stdio.h>

int main(int argc, char **argv)
{
	double fahr;
	double celsius;
	double lower = 0;
	double upper = 300;
	double step = 20;
	fahr = lower;
	printf("Fahrenheit\tCelsius\n");
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%10.0f\t%7.1f\n", fahr, celsius);
		fahr += step;
	}
	return 0;
}
