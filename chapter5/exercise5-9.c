#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

static char daytab[2][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int main(){
	int m, d;
	month_day(1988,60, &m, &d);
	printf("test month_day: %d, %d\n",m,d);
	printf("test day_of_year: %d\n", day_of_year(1988,3,1));
	month_day(1988,0, &m, &d);
	month_day(1988,367, &m, &d);
	printf("test day_of_year: %d\n", day_of_year(1988,2,30));
	return 1;
}

int day_of_year(int year, int month, int day){
	if(month < 1 || month > 12 || day < 1)
		return -1;
	int leap;
	char *ptr;

	leap = year%4 && year%100 != 0 || year%400 == 0;
	ptr = daytab[leap];
	if(day > *(ptr + month))
		return -1;
	while(--month > 0)
		day += *++ptr;
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday){
	if(yearday < 1 || yearday > 366){
		printf("Err: too many days in year\n");
		return;
	}
	int i, leap;
	char *ptr;
	leap = year%4 && year%100 != 0 || year%400 == 0;
	ptr = daytab[leap];
	if(!leap && yearday > 365){
		printf("Err: too many days in year\n");
		return;
	}
	while(yearday > *++ptr)
		yearday -= *ptr;
	*pmonth = ptr - daytab[leap];
	*pday = yearday;
}
