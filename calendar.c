#include "calendar.h"


int days_in_month(int month, int year) {
	if(month == 3 || month == 5 || month == 8 || month == 10) {
		return 30;
	}
	else if (month == 1) {
		int leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if(leapYear) return 29;
		return 28;
	}
	return 31;
}

void print_calendar(struct tm *tm, int showCurrentDate) {
	int month = tm->tm_mon;
	printf("%s%s %d%s\n",BOLD,MONTHS[month],tm->tm_year, RESET);
	printf(BOLD F_BLUE REVERSE "Sun  Mon  Tue  Wed  Thu  Fri  Sat  \n" RESET);
	int cur_week = (tm->tm_mday - 1) / 7;
	int total_days = days_in_month(month,tm->tm_year);
	int cal[6][7]; //Calendar has (at most) 6 rows, 7 columns

	int today = tm->tm_mday;
	tm->tm_mday = 1;
	tm->tm_year -= 1900;
	mktime(tm);
	tm->tm_year += 1900;
	int cur_mday = 1;
	int cur_wday = tm->tm_wday;

	int w,d;
	for(w = 0; w < 6; w++){
		for(d = 0; d < 7; d++) {
			cal[w][d] = 0;
		}
	}

	//Get to the first week
	while(cur_mday - cur_wday > 8) {
		cur_week--;
		cur_mday -= 7;
	}

	//Get to first sunday
	cur_mday -= cur_wday;
	cur_wday = 0;

	int cw = 0;

	//Populate calendar
	while(cur_mday <= total_days) {
		if(cur_mday > 0 && cur_mday <= total_days) {
			if(cur_mday < 1) cal[0][cur_wday % 7] = 0;
			else cal[cw / 7][cur_wday % 7] = cur_mday;
		}
		cur_mday++;
		cur_wday++;
		cw++;
	}

	char *padding = "";
	for(w = 0; w < 6; w++) {
		for(d = 0; d < 7; d++) {
			padding = (cal[w][d] > 9) ? "  " : "   ";
			if (cal[w][d] != 0) {
				if(cal[w][d] != today || !showCurrentDate)printf("%d%s ",cal[w][d],padding);
				else printf("%s%d%s%s ",R_RED,cal[w][d],padding,RESET);
			}
			else printf("     ");
		}
		printf("\n");
	}
	printf("\n");
}

struct tm *create_tm() {
	time_t rawtime = time(NULL);
	struct tm *tm = localtime(&rawtime);
	tm->tm_year += 1900;
	return tm;
}
