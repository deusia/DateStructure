#include<stdio.h>
#include<windows.h>
#define MONTHS 12
#define YEARS 5
double *pt[YEARS][MONTHS];
int main(void)
{
	 double rain[YEARS][MONTHS] =
	{
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
		{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
		{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
		{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
	};
	int year=0, month;
	int i, k;
	double subtotal, total;
	for (i = 0; i < YEARS; i++)
		for (k = 0; k < MONTHS; k++)
			pt[i][k] = &(rain[i][k]);
	printf("YEARS     RAINFALL     (inches)\n");
	for (year = 0, total = 0; year < YEARS; year++)//calculate every year's average
	{
		for (month = 0,subtotal=0; month < MONTHS; month++)
			subtotal += *pt[year][month];
		printf("%5d %15.lf\n", 2010 + year, subtotal);
		total += subtotal;
	}
	printf("\nThe yearly average is %lf inches.\n", total / YEARS);
	printf("MONTHLY AVERAGES:\n\n");
	printf("JAN FEB MAR APR MAY JUN JUL AUS SEP OCT");
	printf("nov dec\n");

	for (month = 0; month < MONTHS; month++)
	{
		for (year = 0, subtotal = 0; year < YEARS; year++)
			subtotal += *pt[year][month];
		printf("%4.1f", subtotal / YEARS);
	}
	printf("\n");
	system("pause");
	return 0;
}