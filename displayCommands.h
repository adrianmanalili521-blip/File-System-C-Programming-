#ifndef DISPLAYCOMMANDS_H
#define DISPLAYCOMMANDS_H

#include "myColors.h"

void displayCommands() {
    printf(CYAN "\nls" RESET);
    printf(": used to list folders in current directory\n");
    printf(CYAN "mkdir" RESET);
    printf(": used to create folder\n"); 
    printf(CYAN "touch" RESET);
    printf(": used to create file");
    printf(YELLOW "cd" RESET);
    printf(": used to enter a directory\n");
    printf(YELLOW "cd .." RESET);
    printf(": used to get back to previous directory\n");
    printf(YELLOW "cd ~" RESET);
    printf(": used to get to root directory\n\n");
}

#endif