#ifndef Headers
#define Headers
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include "Globals.c"

#include "FuncsFiles.c"
#include "FileIO.c"

uint32_t GetNumber(void);
TimeItems ReadDefaults(void);
bool SaveDefaults(TimeItems SaveDefaults_SaveDefaults);
uint32_t GetNumber(void);
TimeItems SetTimeItems(void);
void MkLine(uint32_t LineSize, char Symbal);
void ExecuteStretch(const TimeItems ExecuteStretch_TimeItems);
static char* SetTimeString(void);
void EllapsedTime(time_t Seconds, bool PrintSecs);

#endif
