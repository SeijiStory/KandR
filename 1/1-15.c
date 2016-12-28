#include <stdio.h>

double ftoc(double temp);
int main(int argc, char **argv)
{
	double fahr;
	double celsius;
	double lower = 0;
	double upper = 300;
	double step = 20;
	fahr = lower;
	while (fahr <= upper) {
		celsius = ftoc(fahr);
		printf("%10.0f\t%7.1f\n", fahr, celsius);
		fahr += step;
	}
	return 0;
}

double ftoc(double temp)
{
	return (5.0/9.0) * (temp - 32.0);
}
