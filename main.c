#include <stdio.h>
#include <string.h>

#include "functionDef.h"
#include "functionProto.h"
#include "structs.h"

#define RED   "\033[31m"
#define GREEN "\033[32m"
#define BLUE  "\033[34m"
#define RESET "\033[0m"

int main(){
    folderNode rootFolder;
    initRootFolder(&rootFolder);

    char command[16];
    char folderName[16];

    do {
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "--help")==0){
            displayCommands();
        } else if (strcmp(command, "cd ..")==0) {
            printf("cd ..\n");
        } else if (strcmp(command, "cd something")==0){
            printf("if symptoms persist consult your programmer\n");
        } else if (strcmp(command, "ls")==0){
            displayContents(rootFolder);
        } else if (strcmp(command, "touch")==0) {
            printf("touch\n");
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

    return 0;
}