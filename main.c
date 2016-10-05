#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calendar.h"
#include "activity.h"
#include "data.h"

struct tm *tm;

const char *MONTHS[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
const char *DAYS[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

void print_multiple_calendars(struct tm *tm, int num) {
	print_calendar(tm,TRUE);
	time_t rawtime = time(NULL);
	struct tm *t = localtime(&rawtime);
	t->tm_mday = 1; //Initialize to the first of the month
	int c;
	for(c = 1; c < num; c++) {
		t->tm_mon = (t->tm_mon + 1) % 12;
		if(t->tm_mon == 0) t->tm_year++;
		mktime(t);
		t->tm_year += 1900; //tm_year refers to years since 1900. We have to trick mktime().
		print_calendar(t,FALSE);
		t->tm_year -= 1900; //Setting the year back to trick mktime().
	}
}

int prompt_createActivity(void) {
	char name[64];
	char time[64];
	char loc[64];
	char date[10];
	char color[16];
	printf("Enter activity name: ");
	fgets(name,64,stdin);
	printf("Enter time range of activity: ");
	fgets(time,64,stdin);
	printf("Enter location of activity: ");
	fgets(loc,64,stdin);
	printf("Enter date of activity [YYYYMMDD]: ");
	fgets(date,10,stdin);
	printf("Enter color for activity: ");
	fgets(color,16,stdin);
	char *c;
	color[strlen(color) -1] = '\0';
	if(strcmp(color,"red") == 0) c= F_RED;
	else if(strcmp(color,"blue") == 0) c= F_BLUE;
	else if(strcmp(color,"yellow") == 0) c= F_YELLOW;
	else if(strcmp(color,"green") == 0) c= F_GREEN;
	else if(strcmp(color,"magenta") == 0) c= F_MAGENTA;
	else if(strcmp(color,"cyan") == 0) c= F_CYAN;
	else if(strcmp(color,"RED") == 0) c= R_RED;
	else if(strcmp(color,"BLUE") == 0) c= R_BLUE;
	else if(strcmp(color,"YELLOW") == 0) c= R_YELLOW;
	else if(strcmp(color,"GREEN") == 0) c= R_GREEN;
	else if(strcmp(color,"MAGENTA") == 0) c= R_MAGENTA;
	else if(strcmp(color,"CYAN") == 0) c = R_CYAN;
	else c = "";
	name[strlen(name) -1] = '\0';
	time[strlen(time) -1] = '\0';
	loc[strlen(loc) -1] = '\0';
	date[strlen(date) -1] = '\0';
	Activity *a;
	if((a = createActivity(name,time,loc,date,c)) == NULL) {
		printf("Error creating activity\n");
		return 1;
	}
	printActivity(a);
	return 0;
}

int main(int argc, char **argv) {
	if(argc < 2) {
		printf("USAGE: butler <category> {options}\n");
		LinkedList *list = createLinkedList(NULL);
		addToFront(list,(void *)42);
		addToFront(list,(void *)23);
		addToFront(list,(void *)16);
		addToFront(list,(void *)15);
		addToFront(list,(void *)8);
		addToFront(list,(void *)4);
		printLinkedList(list);
		removeFirst(list);
		removeFirst(list);
		removeFirst(list);
		printLinkedList(list);
		return 1;
	}
	if (strcmp(argv[1],"calendar") == 0) {
		tm = create_tm();
		if(argc > 2) {
			print_multiple_calendars(tm,atoi(argv[2]));
		}
		else {
			print_calendar(tm,TRUE);
		}
	}
	else if (strcmp(argv[1],"activity") == 0) {
		if(argc == 2) {
			printf("The activity category requires extra options.\n");
			return 2;
		}
		if(strcmp(argv[2],"create") == 0) {
			prompt_createActivity();
		}
		else {
			printf("Error: \'%s\' is not a recognized option\n",argv[2]);
			return 2;
		}
	}
	else {
		printf("Error: \'%s\' is not a recognized category\n",argv[1]);
		return 2;
	}
	
	return 0;
}
