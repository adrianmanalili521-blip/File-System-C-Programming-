#ifndef INPUT_H
#define INPUT_H

//basic colors
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

//bright colors
#define BBLACK   "\033[90m"
#define BRED     "\033[91m"
#define BGREEN   "\033[92m"
#define BYELLOW  "\033[93m"
#define BBLUE    "\033[94m"
#define BMAGENTA "\033[95m"
#define BCYAN    "\033[96m"
#define BWHITE   "\033[97m"

//text styles 
#define BOLD      "\033[1m"
#define DIM       "\033[2m"
#define UNDERLINE "\033[4m"
#define BLINK     "\033[5m"
#define REVERSE   "\033[7m"
#define HIDDEN    "\033[8m"

//background colors
#define BG_BLACK   "\033[40m"
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"

#include "functionDef.h"
#include "functionProto.h"
#include "structs.h"
    
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void UserInput () {
    folderNode rootFolder;
    initRootFolder(&rootFolder);

    char command[16];
    char folderName[16];
    char fileName[16];
    char text[100];

    printf(RED "something is happening!...\n" RESET);
    sleep(2);
    printf(BLUE "or maybe not..\n" RESET );
    sleep(3);
    printf(RED "oh! wait! there is!..\n" RESET);
    sleep(2);
    printf(GREEN "your program is now running hehe...\n\n" RESET);

    do {
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "--help")==0){
            displayCommands();
        } else if (strcmp(command, "cd ..")==0) {
            printf("cd ..\n");
        } else if (strcmp(command, "cd something")==0){
            printf(BG_RED "if symptoms persist consult your programmer\n" RESET);
        } else if (strcmp(command, "ls")==0){
            displayContents(rootFolder);
        } else if (strcmp(command, "touch")==0) {
            printf("Enter file name: \n");
            fgets(fileName, sizeof(fileName), stdin);
            fileName[strcspn(fileName, "\n")] = '\0';

            if (strcmp(fileName, "")==0) {
                printf(RED "Failed to create file.\n" RESET);
            } else {
                printf("Enter text: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0';
                createFile(&rootFolder, fileName, text);
            }
        } else if (strcmp(command, "mkdir")==0) {
            printf("name of folder: ");
            fgets(folderName, sizeof(folderName), stdin);
            if (strcmp(folderName, "")!=0){
                createFolder(&rootFolder, folderName);
            } else {
                printf(RED "coud not create folder\n" RESET);
            }
        } else if (strcmp(command, "find something")==0) {
                printf("find folder path\n");
        } else if (strcmp(command, "rm")==0) {
                printf("rm\n");
        } else {
            printf(RED "Invalid Command, enter ", RESET);
            printf(GREEN "--help " RESET);
            printf("to view commands\n");
        }
    } while (1);

}

#endif 