#include <stdlib.h>
#include <time.h>
#include <stdio.h>

const char FileName[20]="/Workout.Default";
#define STDLINE() MkLine(50, '*')
#define CLSCREEN() fputs("\033[2J\033[1;1H", stdout)
#define BUFFSIZE 690
#define READPERM 0444
#define CLSCREEN() fputs("\033[2J\033[1;1H", stdout)

typedef struct _TimeItems
{
char currtimestring[BUFFSIZE];
time_t Rest_Intervals;
time_t Stretch_Time;
uint32_t Repetitions;
}TimeItems;
