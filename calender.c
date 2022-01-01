#include<stdio.h>
#include<string.h>
int calculate(int day, int month, int year)
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
			
					
				days=daycounter(i,j);
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
	int dayorder=(yearday+day)%7;
	return (dayorder);
}

const char* calculatemonth(int month, int year)
{
	char string[10000];
	
	
	return string; 
}
int daycounter(int month, int year)
{
	int i=month,j=year,days;
	if(i<8 && i!=2)      // upto august
				{
					if(i%2==0) days=30;
					
					else days=31;
				}
				else if(i!=2 && i>=8){	// after august
					if(i%2==0) days=31;
					
					else days+=30;
				}
				else if(i==2)
				{
					if((j%4!=0)||(j%100==0&&j%400!=0)) days=28;    // leap year calculation
					else days=29;
				} 
		return days;
}

const char* calculateyear(int year)
{
	char yearstring[10000];
	return yearstring;
}
void select(int day, int month, int year)
{
	int dayorder=0;
	if(month==0 && day==0) printf("%s",calculateyear(year));  //year
	else if(day==0) printf("%s",calculatemonth(month, year)); //month
	else                                                 //day
	{
		dayorder=calculate(day, month,year);
		char days[][15]={"Saturday","Sunday", "Monday", "Tuesday", "Wednesday", "Thrusday", "Friday"}; 
		printf("\n%s\n", days[dayorder]);
	}
	
}

int main()
{
	int day,month,year;
	while(1){
	
	printf("\nDay: "); scanf("%d", &day);
	printf("Month: "); scanf("%d", &month);
	printf("Year: "); scanf("%d", &year);
	
	if(day<=31 && month <=12 && year>=1) select(day,month,year);
	else printf(":::::::: Enter the proper date ::::::::\n");
	 }
	

	return 0;
}
