#include<stdio.h>
int daysinyear(int day, int month, int year)
{
	long int days=0, yearday=0, limit, i, j; month-=1; day-=1;
	int starting, end;
	
	
	for(j=5; j<=year; j++)
	{
		days=0;
		if(j==year) 
		{
			
			limit=month;
			
			//printf("limit %d\n", limit);
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
					if((j%4!=0)||(j%100==0&&j%400!=0)) days+=28;    // leap year calculation
					else days+=29;
				}    
				//printf("i: %d, days: %d\n",i,days);
			}
		}
		//printf("j: %d, days: %d yearday: %d\n",j,days, yearday);
		else {
			if((j%4!=0)||(j%100==0&&j%400!=0)) days+=365;    // leap year calculation
					else days+=366;
		}
		yearday+=days;
	
	}
	
	return (yearday+day);
}


void select(int day, int month, int year)
{
	/*if(month==0 && day==0) calculate(year);
	else if(day==0) calculate(year, month);
	else calculate(year,month,day);*/
	long int totaldays=daysinyear(day, month,year);
	char days[][15]={"Saturday","Sunday", "Monday", "Tuesday", "Wednesday", "Thrusday", "Friday"}; int dayorder=totaldays%7;
	//printf("%d\n", dayorder);
	printf("\n%s\n\n", days[dayorder]);
}

int main()
{
	int day,month,year;
	/*while(1){
	
	printf("Day: "); scanf("%d", &day);
	printf("Month: "); scanf("%d", &month);
	printf("Year: "); scanf("%d", &year);
	select(day,month,year); }*/
	
	select(31,5,2004);
	return 0;
}
