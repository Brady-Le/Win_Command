#pragma once
#ifndef _GetTime_H_
#define _GetTime_H_

typedef struct {
	//∂®“Â Ù–‘
	int sec;
	int min;
	int hour;
	int MonthDay;
	int month;
	int year;
	int WeekDay;

}Time_Calender;

void Time_Calender_Ctor(Time_Calender* This);

int GetSec(Time_Calender* This);

int GetMin(Time_Calender* This);

int GetHour(Time_Calender* This);

int GetMonthDay(Time_Calender* This);

int GetMonth(Time_Calender* This);

int GetYear(Time_Calender* This);

int GetWeekDay(Time_Calender* This);

void GetTime();
#endif // !_GetTime_H_
