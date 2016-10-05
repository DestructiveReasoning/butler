#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#define RESET		"\x1B[0m"
#define BOLD		"\x1B[1m"
#define REVERSE		"\x1B[7m"
#define F_RED		"\x1B[31m"
#define F_GREEN		"\x1B[32m"
#define F_YELLOW	"\x1B[33m"
#define F_BLUE		"\x1B[34m"
#define F_MAGENTA	"\x1B[35m"
#define F_CYAN		"\x1B[36m"
#define B_RED		"\x1B[41m"
#define B_GREEN		"\x1B[42m"
#define B_YELLOW	"\x1B[43m"
#define B_BLUE		"\x1B[44m"
#define B_MAGENTA	"\x1B[45m"
#define B_CYAN		"\x1B[46m"
#define R_RED		"\x1B[31;7m"
#define R_GREEN		"\x1B[32;7m"
#define R_YELLOW	"\x1B[33;7m"
#define R_BLUE		"\x1B[34;7m"
#define R_MAGENTA	"\x1B[35;7m"
#define R_CYAN		"\x1B[36;7m"

#define TRUE		1
#define FALSE		0

extern const char *MONTHS[12];
extern const char *DAYS[7];
#endif
