#include "activity.h"
#include "calendar.h"
#include "constants.h"

Activity *createActivity(char *name, char *time, char *location, char *date, char *color) {
	Activity *a = (Activity *)malloc(sizeof(Activity));
	char *c;

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

	a->name = (char *)malloc(sizeof('c')*strlen(name));
	a->time = (char *)malloc(sizeof('c')*strlen(time));
	a->location = (char *)malloc(sizeof('c')*strlen(location));
	a->date = (char *)malloc(sizeof('c')*strlen(date));
	strcpy(a->name,name);
	strcpy(a->location,location);
	strcpy(a->time,time);

	if(!isValidDate(date)) {
		printf("\'%s\' is not a valid date entry. Dates must contain only numbers of the format YYYYMMDD.\n",date);
		return NULL;
	}
	strcpy(a->date,date);
	a->color = c;
	return a;
}
LinkedList *loadActivities(void) {
	LinkedList *list = createLinkedList(NULL);

	char *filepath;
	filepath = getenv("HOME");
	strcat(filepath,"/.butler/events");
	FILE *file;
	file = fopen(filepath,"r");
	if(file == NULL) return NULL;

	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while((read = getline(&line,&len,file)) != -1) {
		//Parse line
		char attrs[6][128];

		Activity *activity;
		int i,j,pos;
		i = 0;
		pos = 0;
		for(j = 0; j < len; j++) {
			if(line[j] == ';' || line[j] == '\n') {
				attrs[i][pos] = '\0';
				pos = 0;
				i++;
			}
			else {
				attrs[i][pos++] = line[j];
			}
		}
		attrs[5][0] = '\0';
		activity = createActivity(attrs[1],attrs[2],attrs[3],attrs[0],attrs[4]);
		ll_addToFront(list,(void *)activity);
	}

	linknode *iterator = list->head;
	while(iterator != NULL) {
		printActivity((Activity *)iterator->data);
		iterator = iterator->next;
	}

	fclose(file);

	return list;
}
void printActivity(Activity *a) {
	printf("%s%s%s%s\n",BOLD,a->color,a->name,RESET);
	printf("%sTime:%s %s\n",BOLD,RESET,a->time);
	printf("%sLocation:%s %s\n",BOLD,RESET,a->location);
	char fdate[12];
	memset(fdate,0,12);
	formatDate(a->date,fdate);
	printf("%sDate%s: %s\n", BOLD,RESET,fdate);
	printf("\n");
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
