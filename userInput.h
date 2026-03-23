#ifndef INPUT_H
#define INPUT_H

#include "functionDefinitions.h"
#include "functionPrototypes.h"
#include "structs.h"
#include "myColors.h"
#include "displayCommands.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void UserInput () {
    folderNodePtr folderPtr;
    initFolder(&folderPtr, "root", "root\\");
    folderNodePtr* trav = &folderPtr;
    folderNodePtr* temp = NULL;

    printf(GREEN "Your program is running...\n" RESET);

    char command[16];
    char folderName[16];
    char fileName[16];
    char text[100];

    do {
        printf("%s", (*trav)->path);
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "--help")==0) {
            displayCommands();
        } else if (strcmp(command, "ls")==0) {
            disPlayContents((**trav));
        } else if (strcmp(command, "mkdir")==0) {
            printf("Enter folderName: ");
            fgets(folderName, sizeof(folderName), stdin);
            folderName[strcspn(folderName, "\n")] = '\0';

            createFolder((*trav), folderName);
        } else if (strcmp(command, "touch")==0) {
            printf("Enter file name: ");
            fgets(fileName, sizeof(fileName), stdin);
            fileName[strcspn(fileName, "\n")] = '\0';

            printf("Enter text: ");
            fgets(text, sizeof(text), stdin);
            text[strcspn(text, "\n")] = '\0';


            createFile((*trav), fileName, text);
        } else if (strcmp(command, "cd")==0) {
            printf("Enter folder name: ");
            fgets(folderName, sizeof(folderName), stdin);
            folderName[strcspn(folderName, "\n")] ='\0';

            temp = getFolAdress((*trav), folderName);
            if (temp != NULL) trav = temp;

        } else if (strcmp(command, "cd ..")==0) {
            if ((*trav)->prevFolder != NULL) {
                trav = &(*trav)->prevFolder;

            }
        } else if (strcmp(command, "cd ~")==0) {
            trav = &folderPtr;
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