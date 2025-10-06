#include "Headers.h"

void PrintTimeItems(TimeItems TimeItemsvar)
{
    fprintf(stdout, "Time: %s, Rest time: %lu, Stretch time: %lu, Reps: %d", TimeItemsvar.currtimestring, TimeItemsvar.Rest_Intervals, 
    TimeItemsvar.Rest_Intervals, TimeItemsvar.Repetitions);
    return;
}

TimeItems ReadDefaults(void)
{
    TimeItems ItemsRead;
    char currdir[BUFFSIZE]={'\0'};
    getcwd(currdir, BUFFSIZE);
    fprintf(stdout, "Your directory is: %s\n", currdir);
    strncat(currdir, FileName, sizeof(char)*(BUFFSIZE-strlen(currdir)-strlen(FileName)));
    fprintf(stdout, "Reading From: %s\n", currdir);
    int Sd=open(currdir, O_RDONLY);
    if(Sd<0)
    {
    perror("Error Opening File:");
    exit(-69);
    }
    uint16_t Readsize=0;
    Readsize+=read(Sd, &ItemsRead, sizeof(TimeItems)); 
    printf("Read %d of %d\n", Readsize, sizeof(TimeItems));
    close(Sd);
    PrintTimeItems(ItemsRead);
    return ItemsRead;
}
    
    bool SaveDefaults(TimeItems SaveDefaults_SaveDefaults)
{
    char currdir[BUFFSIZE]={'\0'};
    getcwd(currdir, BUFFSIZE);
    fprintf(stdout, "Your directory is: %s\n", currdir);
    strncat(currdir, FileName, sizeof(char)*(BUFFSIZE-strlen(currdir)-strlen(FileName)));
    fprintf(stdout, "Writing to: %s\n", currdir);
    PrintTimeItems(SaveDefaults_SaveDefaults);
    int Sd=open(currdir, O_CREAT | S_IRWXU | O_TRUNC, 0644);
    if(Sd<0)
    {
    perror("Error Opening File:");
    exit(-69);
    }
    uint16_t WriteSize=0;
    WriteSize=write(Sd, &SaveDefaults_SaveDefaults, sizeof(TimeItems));
    printf("\nWritten %d of %d", WriteSize, sizeof(TimeItems));
    close(Sd);
    return EXIT_SUCCESS;
}

uint32_t GetNumber(void)
{
    uint32_t NumbToReturn=0;
    char buff[BUFFSIZE]="\0";
    while(NumbToReturn<1 || NumbToReturn>100)
    {
    fflush(stdin);
    fputs( "\tNumber must be between 0 & 100->>>>>", stdout);
    fgets(buff, BUFFSIZE-1, stdin);
    NumbToReturn=strtol(buff, 0, 10);
    }
    return NumbToReturn;
}