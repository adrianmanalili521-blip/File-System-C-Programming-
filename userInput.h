#ifndef INPUT_H
#define INPUT_H

#include "functionDefinitions.h"
#include "functionPrototypes.h"
#include "structs.h"
#include "myColors.h"
    
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void UserInput () {
    folderNodePtr folderPtr;
    initFolder(&folderPtr, "root");
    folderNodePtr* trav = &folderPtr;

    printf(GREEN "Your program is running...\n" RESET);

    char command[16];
    char folderName[16];

    do {
        printf("%s\\", folderPtr->folderName);
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "--help")==0) {
            printf(RED "something went wrong, " RESET);
            printf("if symptoms persist consult your programmer.\n");
        } else if (strcmp(command, "ls")==0) {
            disPlayContents((*folderPtr));
        } else if (strcmp(command, "mkdir")==0) {
            printf("Enter folderName: ");
            fgets(folderName, sizeof(folderName), stdin);
            folderName[strcspn(folderName, "\n")] = '\0';

            createFolder((*trav), folderName);
        }

        else {
            printf(RED "Invalid Command!" RESET);
            printf("use ");
            printf(GREEN "--help " RESET);
            printf("to view commands\n");
        }
    } while (1);

}

#endif 