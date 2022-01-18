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
			}
		}
		
		else {
			if((j%4!=0)||(j%100==0&&j%400!=0)) days+=365;    // leap year calculation
					else days+=366;
		}
	//	printf("j: %d, days: %d yearday: %d\n",j,days, yearday);
		yearday+=days;
	
	}
	int dayorder=(yearday+day)%7;
	//printf("days: %d", yearday);
	return (dayorder);
}


void calculatemonth(int month, int year)
{
	char string[10000];
	strcpy(string,"");
	strcat(string,"\n");
	char monthname[12][20]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	strcat(string,"\t\t    ");
	strcat(string,monthname[month-1]);
	strcat(string,"  ");
	char yearstr[10];
	itoa(year,yearstr,10);
	strcat(string, yearstr);
	strcat(string, " \n\n");
	strcat(string,"Sun\tMon\tTue\tWed\tThu\tFri\tSat\n\n");
	int spacereq=calculate(1,month,year),i, days=daycounter(month,year);
	if (spacereq==0) spacereq=7;
	for(i=1;i<spacereq;i++)
	{
		strcat(string,"\t");
	}
	int margin=spacereq;
	for(i=1;i<=days;i++)
	{
		char day[10];
		itoa(i,day,10);
		strcat(string,day);
		strcat(string,"\t");
		if(margin==7){
			strcat(string,"\n\n");
			margin=0;
		}margin++;
	}
	strcat(string,"\n");
	printf("%s", string) ;
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
		
		else days=30;
	}
	else if(i==2)
	{
		if((j%4!=0)||(j%100==0&&j%400!=0)) days=28;    // leap year calculation
		else days=29;
	} 
	return days;
}

void calculateyear(int year)
{
	int i;
	for(i=1;i<=12;i++)
	{
		calculatemonth(i,year);
	}
	
	
}
void select(int day, int month, int year)
{
	int dayorder=0;
	if(month==0 && day==0){ calculateyear(year); printf("\n"); system("pause"); system("cls");  } //year
	else if(day==0 && month!=0) {calculatemonth(month, year); printf("\n"); system("pause"); system("cls"); }//month
	else                                                 //day
	{
		dayorder=calculate(day, month, year);
		char days[][15]={"Saturday","Sunday", "Monday", "Tuesday", "Wednesday", "Thrusday", "Friday"}; 
		printf("\n%s\n\n", days[dayorder]); system("pause"); system("cls");
	}
	
}

int main()
{
	int day,month,year;
	while(1){
	
	printf("\nDay: "); scanf("%d", &day);
	printf("Month: "); scanf("%d", &month);
	printf("Year: "); scanf("%d", &year);
	
	//printf("%d",daycounter(month,year));
	
	if(day<=31 && month<=12 && year>=1) select(day,month,year);
	
	else printf(":::::::: Enter the proper date ::::::::\n");
	 }
	
	return 0;
}
