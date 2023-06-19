#include "convert_integer.h"
#include <stdio.h>

int ordinalDay(int,int,int);
int isLeapYear(int);
int dayOfTheWeek(int,int);
int isoWeek(int,int,int);
int weeksInYear(int);
int modulus(int);
int getISOYear(int,int,int);
void printLine1(int,int,int);
void printLine2(int,int);
void printLine3(int,int,int);
int main(int argc,char **argv)
{
    int day,month,year,ordDay,dOTW,ISOWeek,ISOYear;

    day=get_integer();
    month=get_integer();
    year=get_integer();

    ordDay=ordinalDay(day,month,year);
    dOTW = dayOfTheWeek(year,ordDay);
    ISOWeek=isoWeek(ordDay,dOTW,year);
    ISOYear = getISOYear(month,ISOWeek,year);

    printLine1(day,month,year);
    printLine2(ordDay,year);
    printLine3(ISOYear,ISOWeek,dOTW);
    return 0;
}
void printLine1(int day,int month, int ISOYear)
{
    printf("%d-",ISOYear);
    if(month<10)
        printf("0%d-",month);
    else
        printf("%d-",month);
    if(day<10)
        printf("0%d\n",day);
    else
        printf("%d\n",day);
}
void printLine2(int ordDay,int ISOYear)
{
    printf("%d-",ISOYear);
    if(ordDay<10)
        printf("00%d\n",ordDay);
    else if(ordDay<100)
        printf("0%d\n",ordDay);
    else
        printf("%d\n",ordDay);
}
void printLine3(int ISOYear,int ISOWeek,int dayOfTheWeek)
{
    printf("%d-",ISOYear);
    if(ISOWeek<10)
        printf("W0%d-",ISOWeek);
    else
        printf("W%d-",ISOWeek);
    printf("%d\n",dayOfTheWeek);
}
int ordinalDay(int day, int month,int year)
{
    int lYTest,ordDay,intyCalc;
    float calc;
    lYTest=isLeapYear(year);
    if(month==1)
        return day;
    else if(month==2)
        return (day+31);
    calc = (30.6*month-91.4);
    intyCalc=(int)calc;
    ordDay=intyCalc+day;
    if(lYTest==1)
        return (ordDay+60);
    return (ordDay+59);
}
int dayOfTheWeek(int year,int day)
{
    int calcResult,yMinus1;
    yMinus1=year-1;
    calcResult = (day+5*(yMinus1%4)+4*(yMinus1%100)+6*(yMinus1%400))%7;
    if(calcResult==0)
        calcResult=7;
    return calcResult;
}
int getISOYear(int month,int ISOWeek, int year)
{
    int ISOYear;
    if (month==12 && ISOWeek==1)
        ISOYear=year+1;
    else if (month==1 && (ISOWeek==52 || ISOWeek==53))
        ISOYear=year-1;
    else
        ISOYear=year;
    return ISOYear;
}
int isoWeek(int ordDay,int weekDay,int year)
{
    int week;
    float weekFloat;
    weekFloat = ((ordDay-weekDay+10)/7);
    week = (int)weekFloat;
    if(week==0)
        week = weeksInYear(year-1);
    else if(week>weeksInYear(year))
    {
        if(weekDay<4)
            week = 1;
    }
    return week;
}
int weeksInYear(int year)
{
    int wIY;
    if(modulus(year)==4 || modulus(year-1)==3)
    {
        wIY=53;
    }
    else
    {
        wIY=52;
    }
    return wIY;
}
int modulus(int year)
{
    int r;
    r=(year+year/4-year/100+year/400)%7;
    return r;
}
int isLeapYear(int year)
{
    if(year==1900 || year==2100)
        return 0;
    else if(year%4==0)
        return 1;
    return 0;
}