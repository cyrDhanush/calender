#include<stdio.h>
int daysinyear(int day, int month, int year)
{
	int days=0, yearday=0, limit, i, j; month-=1; day-=1;
	
	
	
	for(j=2000; j<=year; j++)
	{
		days=0;
		if(j==year) limit=month;
		else limit=12-1;
		printf("limit %d\n", limit);
		for(i=1;i<=limit;i++)
		{
			if(i<8 && i!=2)      // upto august
			{
				if(i%2==0) days+=30;
				
				else days+=31;
			}
			else if(i!=2 && i>=8){	// after august
				if(i%2==0) days+=31;
				
				else days+=30;
			}
			else if(i==2)
			{
				if(j%4==0) days+=29;    // leap year calculation
				else days+=28;
			}
			printf("i: %d, days: %d\n",i,days);
		}
		printf("j: %d, days: %d yearday: %d\n",j,days, yearday);
		yearday+=days;
	
	}
	
	return (yearday+day);
}


void select(int day, int month, int year)
{
	/*if(month==0 && day==0) calculate(year);
	else if(day==0) calculate(year, month);
	else calculate(year,month,day);*/
	int totaldays=daysinyear(day, month,year);
	printf("%d\n", totaldays);
	char days[][15]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thrusday", "Friday", "Saturday"};
	printf("%s\n", days[(totaldays%7)-1]);
}
void calculate(int year, int month){
	
}
int main()
{
	int day,month,year;
	while(1){
	
	printf("Day: "); scanf("%d", &day);
	printf("Month: "); scanf("%d", &month);
	printf("Year: "); scanf("%d", &year);
	select(day,month,year); }
}
