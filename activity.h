#ifndef _ACTIVITY_H_
#define _ACTIVITY_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "constants.h"

typedef struct {
	char *name;
	char *time;
	char *location;
	char *color;
	char *date;
} Activity;

Activity *createActivity(char *name, char *time, char *location, char *date, char *color);
void printActivity(Activity *);
void formatDate(char *, char *);
int isValidDate(char *);

#endif
