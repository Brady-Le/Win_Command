#include"GetTime.h"
#include<Windows.h>
#include<stdio.h>
#include<time.h>

//GetTime构造函数
void Time_Calender_Ctor(Time_Calender* This)
{
	struct tm* timeptr;
	//日历时间类
	time_t calendar;
	//获取系统时间  &引用且返回 time（）计算当前日历时间
	time(&calendar);
	//转化为当地时间 location（）把时间设为本地时区并转化为时钟结构
	timeptr = localtime(&calendar);
	//时钟结构体赋值赋值给相应变量
	This->year = timeptr->tm_year;
	This->month = timeptr->tm_mon;
	This->MonthDay = timeptr->tm_mday;
	This->WeekDay = timeptr->tm_wday;
	This->hour = timeptr->tm_hour;
	This->min = timeptr->tm_min;
	This->sec = timeptr->tm_sec;
}

int GetSec(Time_Calender* This)
{
	return This->sec;
}

int GetMin(Time_Calender* This)
{
	return This->min;
}

int GetHour(Time_Calender* This)
{
	return This->hour;
}

int GetMonthDay(Time_Calender* This)
{
	return This->MonthDay;
}

int GetMonth(Time_Calender* This)
{
	return This->month;
}

int GetYear(Time_Calender* This)
{
	return This->year;
}

int GetWeekDay(Time_Calender* This)
{
	return This->WeekDay;
}

void GetTime()
{
	char weekdayString[10];
	Time_Calender TC;
	Time_Calender_Ctor(&TC);
	switch (GetWeekDay(&TC))
	{
	case 01: strcpy(weekdayString, "Monday"); break;
	case 02: strcpy(weekdayString, "Tuesday"); break;
	case 03: strcpy(weekdayString, "Wednesday"); break;
	case 04: strcpy(weekdayString, "Thursday"); break;
	case 05: strcpy(weekdayString, "Friday"); break;
	case 06: strcpy(weekdayString, "Saturday"); break;
	case 07: strcpy(weekdayString, "Sunday"); break;
	}
	printf("%4d-%02d-%02d %s %02d:%02d:%02d\n", 1900 + GetYear(&TC), 
		1 + GetMonth(&TC), GetMonthDay(&TC), weekdayString,
		GetHour(&TC), GetMin(&TC), GetSec(&TC));
}