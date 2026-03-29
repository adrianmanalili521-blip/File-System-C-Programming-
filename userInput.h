#ifndef INPUT_H
#define INPUT_H

#include "functionDefinitions.h"
#include "functionPrototypes.h"
#include "structs.h"
#include "myColors.h"
#include "displayCommands.h"
#include <stdio.h>
#include <string.h>

void UserInput () {
    folderNodePtr rootFolder;
    initFolder(&rootFolder, "root", "root\\");
    folderNodePtr trav = rootFolder;
    folderNodePtr temp = NULL;
    int index = -1;

    printf(GREEN "Your program is running...\n" RESET);

    char command[16];
    char folderName[16];
    char fileName[16];
    char text[100];

    do {
        printf("%s", trav->path);
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "--help")==0) {
            displayCommands();
        } else if (strcmp(command, "ls")==0) {
            disPlayContents(*trav);
        } else if (strcmp(command, "mkdir")==0) {
            printf("Enter folderName: ");
            fgets(folderName, sizeof(folderName), stdin);
            folderName[strcspn(folderName, "\n")] = '\0';

            createFolder(trav, folderName);
        } else if (strcmp(command, "touch")==0) {
            printf("Enter file name: ");
            fgets(fileName, sizeof(fileName), stdin);
            fileName[strcspn(fileName, "\n")] = '\0';

            printf("Enter text: ");
            fgets(text, sizeof(text), stdin);
            text[strcspn(text, "\n")] = '\0';

            createFile(trav, fileName, text);
        } else if (strcmp(command, "cd")==0) {
            printf("Enter folder name: ");
            fgets(folderName, sizeof(folderName), stdin);
            folderName[strcspn(folderName, "\n")] ='\0';

            temp = getFolAdress(trav, folderName);
            if (temp != NULL) trav = temp;

        } else if (strcmp(command, "cd ..")==0) {
            if (trav->prevFolder != NULL) {
                trav = trav->prevFolder;
            }
        } else if (strcmp(command, "cd ~")==0) {
            trav = rootFolder;
        } else if (strcmp(command, "rm")==0) {
            printf("Enter folder name: ");
            fgets(folderName, sizeof(folderName), stdin);
            folderName[strcspn(folderName, "\n")] = '\0';
            index = searchFolder(*trav, folderName);
            if (index != -1) {
                removeFolder(trav, index);
            } else {
                printf(RED "could not find folder\n" RESET);
            }
        } else if (strcmp(command, "exit")==0) {
            printf(GREEN "Exiting...\n" RESET);
            break;
        } else {
            printf(RED "Invalid Command!" RESET);
            printf("use ");
            printf(GREEN "--help " RESET);
            printf("to view commands\n");
        }
    } while (1);

    freeFolderRecursive(rootFolder);
}

#endif 