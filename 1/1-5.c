#include <stdio.h>

int main(int argc, char **argv)
{
	double fahr;
	double celsius;
	double lower = 0;
	double upper = 300;
	double step = 20;
	printf("Fahrenheit\tCelsius\n");
	for (fahr = upper; fahr >= lower; fahr -= step) {
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%10.0f\t%7.1f\n", fahr, celsius);
	}
	return 0;
}
