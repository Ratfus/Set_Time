#include "Headers.h"

int main()
{
    CLSCREEN();

    fputs("Change Default? y=yes\n", stdout);
    if('y'==getchar())
    {
    fputs("Changing Default...\n", stdout);
    TimeItems SetDefaults=SetTimeItems();
    SaveDefaults(SetDefaults);
    }
    else
    {
    fputs("Running Normal - using defaults...\n", stdout);
    TimeItems TimeItems_M=ReadDefaults();
    PrintTimeItems(TimeItems_M);
    ExecuteStretch(TimeItems_M);
    }
    return EXIT_SUCCESS;
}