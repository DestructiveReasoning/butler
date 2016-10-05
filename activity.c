#include "activity.h"
#include "calendar.h"

Activity *createActivity(char *name, char *time, char *location, char *date, char *color) {
	Activity *a = (Activity *)malloc(sizeof(Activity));
	a->name = name;
	a->time = time;
	a->location = location;
	if(!isValidDate(date)) {
		printf("\'%s\' is not a valid date entry. Dates must contain only numbers of the format YYYYMMDD.\n",date);
		return NULL;
	}
	a->date = date;
	a->color = color;
	return a;
}

void printActivity(Activity *a) {
	printf("%s%s%s%s\n",BOLD,a->color,a->name,RESET);
	printf("%sTime:%s %s\n",BOLD,RESET,a->time);
	printf("%sLocation:%s %s\n",BOLD,RESET,a->location);
	char fdate[12];
	memset(fdate,0,12);
	formatDate(a->date,fdate);
	printf("%sDate%s: %s\n", BOLD,RESET,fdate);
}

void formatDate(char *date, char *fdate) {
	char year[5];
	char month[3];
	char day[3];
	memcpy(year,&date[0],4);
	memcpy(month,&date[4],2);
	memcpy(day,&date[6],2);
	year[4] = month[2] = day[2] = '\0';
	strcat(fdate,MONTHS[(atoi(month) - 1)%12]);
	strcat(fdate," ");
	strcat(fdate,day);
	strcat(fdate,", ");
	strcat(fdate,year);
	strcat(fdate,"\0");
}

int isValidDate(char *date) {
	if (strlen(date) != 8) return 0;
	int c;
	for(c = 0; c < strlen(date); c++) {
		if(!isdigit(date[c])) return 0;
	}
	char month[3], day[3], year[5];
	memcpy(year,&date[0],2);
	memcpy(month,&date[4],2);
	memcpy(day,&date[6],2);
	month[2] = day[2] = year[4] = '\0';
	if(atoi(month) < 1 || atoi(month) > 12) return 0;
	if(atoi(day) < 1 || atoi(day) > days_in_month(atoi(month),atoi(year))) {
		printf("%s/%s/%s doesn't exist\n",day,month,year);
		return 0;
	}
	return 1;
}
