#ifndef _CALENDAR_H_
#define _CALENDAR_H_

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "constants.h"

int days_in_month(int,int);

struct tm *create_tm();

void print_calendar(struct tm *,int);

#endif
