#include"GetTime.h"
#include<Windows.h>
#include<stdio.h>
#include<time.h>

//GetTime���캯��
void Time_Calender_Ctor(Time_Calender* This)
{
	struct tm* timeptr;
	//����ʱ����
	time_t calendar;
	//��ȡϵͳʱ��  &�����ҷ��� time�������㵱ǰ����ʱ��
	time(&calendar);
	//ת��Ϊ����ʱ�� location������ʱ����Ϊ����ʱ����ת��Ϊʱ�ӽṹ
	timeptr = localtime(&calendar);
	//ʱ�ӽṹ�帳ֵ��ֵ����Ӧ����
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