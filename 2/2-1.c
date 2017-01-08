#include <stdio.h>
#include <string.h>

int main (int argc, char **argv)
{
	unsigned char ucharsize = 0;
	unsigned short ushortsize = 0;
	unsigned int uintsize = 0;
	unsigned long ulongsize = 0;
	unsigned long long ullongsize = 0;

	signed char icharmax = 0;
	signed short ishortmax = 0;
	signed int iintmax = 0;
	signed long ilongmax = 0;
	signed long long illongmax = 0;
	signed char icharmin = 0;
	signed short ishortmin = 0;
	signed int iintmin = 0;
	signed long ilongmin = 0;
	signed long long illongmin = 0;

	float floatmax = 0;
	double doublemax = 0;
	float floatmin = 0;
	double doublemin = 0;

	ucharsize = ~ucharsize;
	printf("Max unsigned char size: %u\n", ucharsize);

	ushortsize = ~ushortsize;
	printf("Max unsigned short size: %u\n", ushortsize);

	uintsize = ~uintsize;
	printf("Max unsigned int size: %u\n", uintsize);

	ulongsize = ~ulongsize;
	printf("Max unsigned long size: %lu\n", ulongsize);

	ullongsize = ~ullongsize;
	printf("Max unsigned long long size: %llu\n", ullongsize);

	icharmax = (signed char)((unsigned char)(~icharmax) >> 1);
	printf("Max char size: %d\n", icharmax);
	icharmin = ((icharmax << 1) + 1) ^ icharmax;
	printf("Min char size: %d\n", icharmin);

	ishortmax = (signed short)((unsigned short)(~ishortmax) >> 1);
	printf("Max short size: %d\n", ishortmax);
	ishortmin = ((ishortmax << 1) + 1) ^ ishortmax;
	printf("Min short size: %d\n", ishortmin);

	iintmax = (signed int)((unsigned int)(~iintmax) >> 1);
	printf("Max int size: %d\n", iintmax);
	iintmin = ((iintmax << 1) + 1) ^ iintmax;
	printf("Min int size: %d\n", iintmin);

	ilongmax = (signed long)((unsigned long)(~ilongmax) >> 1);
	printf("Max long size: %ld\n", ilongmax);
	ilongmin = ((ilongmax << 1) + 1) ^ ilongmax;
	printf("Min long size: %ld\n", ilongmin);

	illongmax = (signed long long)((unsigned long long)(~illongmax) >> 1);
	printf("Max long long size: %lld\n", illongmax);
	illongmin = ((illongmax << 1) + 1) ^ illongmax;
	printf("Min long long size: %lld\n", illongmin);

	/* float test assumes IEEE floating point standard */
	unsigned long f = 0;
	unsigned long mantissa = ~0;
	mantissa >>= 9;
	unsigned long expt = 0x7F;
	expt <<= 24;
	f = f | mantissa | expt;
	floatmax = *(float *)&f; /* evil floating point bit level hacking */
	printf("Max float size: %f\n", floatmax);
	f |= ((unsigned long)(~0) ^ ((unsigned long)(~0) >> 1));
	floatmin = *(float *)&f;
	printf("Min float size: %f\n", floatmin);

	/* double test assumes IEEE floating point standard */
	unsigned long long d = 0;
	unsigned long long dmantissa = ~0;
	dmantissa >>= 12;
	unsigned long long dexpt = 0x3FF;
	dexpt <<= 53;
	d = d | dmantissa | dexpt;
	doublemax = *(double *)&d; 
	printf("Max double size: %f\n", doublemax);
	d |= ((unsigned long long)(~0) ^ ((unsigned long long)(~0) >> 1));
	doublemin = *(double *)&d;
	printf("Min double size: %f\n", doublemin);

	return 0;
}
