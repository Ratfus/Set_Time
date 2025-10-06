#include "Headers.h"

uint32_t GetNumber(void);
TimeItems ReadDefaults(void);
bool SaveDefaults(TimeItems SaveDefaults_SaveDefaults);
uint32_t GetNumber(void);
void MkLine(uint32_t LineSize, char Symbal);
void ExecuteStretch(const TimeItems ExecuteStretch_TimeItems);
static char* SetTimeString(void);
void EllapsedTime(time_t Seconds, bool PrintSecs);
extern void PrintTimeItems(TimeItems TimeItemsvar);

TimeItems SetTimeItems(void)
{
    TimeItems SetTimeItems_Var;
    memset(&SetTimeItems_Var, 0, sizeof(TimeItems));
    strncpy(SetTimeItems_Var.currtimestring, SetTimeString(), BUFFSIZE);
    fputs("Enter Rest Intervals in Secs:\n", stdout);
    SetTimeItems_Var.Rest_Intervals=GetNumber();
    CLSCREEN();
    fputs("Enter Stretch Intervals in Secs:\n", stdout);
    SetTimeItems_Var.Stretch_Time=GetNumber();
    CLSCREEN();
    fputs("Enter Total Reps:\n", stdout);
    SetTimeItems_Var.Repetitions=GetNumber();
    CLSCREEN();
    return SetTimeItems_Var;
}

void MkLine(uint32_t LineSize, char Symbal)
{
    for(uint32_t count=0; count<LineSize; count++)
    {
        putc(Symbal, stdout);
    }
    putc('\n', stdout);
    return;
}

void ExecuteStretch(const TimeItems ExecuteStretch_TimeItems)
{
    PrintTimeItems(ExecuteStretch_TimeItems);
    for(int count=1; count<=ExecuteStretch_TimeItems.Repetitions; count++)
    {
        STDLINE();
        fprintf(stdout, "You're on set: %d of %d\n", count, ExecuteStretch_TimeItems.Repetitions);
        STDLINE();
        fputs("Resting State\b\n", stdout);
        EllapsedTime(ExecuteStretch_TimeItems.Rest_Intervals, 1);
        STDLINE();
        fputs("Stretch State\b\n", stdout);
        EllapsedTime(ExecuteStretch_TimeItems.Stretch_Time, 1);
        CLSCREEN();
    }
}

static char* SetTimeString(void)
{
    time_t currtime=time(NULL);
    static char LocalTimeString[BUFFSIZE];
    strncpy(LocalTimeString, asctime((localtime(&currtime))), BUFFSIZE);
    char *wordpoint=NULL;
    uint16_t count=0;
    uint16_t exitcounter=4;
    LocalTimeString[strlen(LocalTimeString)-1]='\0';
    return LocalTimeString;
}

void EllapsedTime(time_t Seconds, bool PrintSecs)
{
    if(Seconds<0)
    {
    fputs("Segmentation Fault", stderr);
    exit(EXIT_FAILURE);
    }
    time_t StartTime=time(NULL);
    while(true)
    {
    static time_t Prior_Time=0;
    time_t EllapsedTime=time(NULL)-StartTime;
    if(PrintSecs && Prior_Time!=EllapsedTime)
    {
    printf("\t----->>>>>>You're on %ld of %ld seconds!\n", EllapsedTime, Seconds);
    Prior_Time=EllapsedTime;
    }
    if(EllapsedTime==Seconds)return;
    }

    fputs("Fuck you - unknown error", stderr);
    exit(EXIT_FAILURE);
}
