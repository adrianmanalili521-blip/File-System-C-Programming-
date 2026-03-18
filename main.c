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
    rootFolNode rootFolNode;
    initRootFolder(&rootFolNode);

    char folderName[16];
    char fileName[16];
    char text[100];
    char command[16];

    printf (GREEN "your programs is now running...\n\n" RESET);

    do {
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "--help")==0){
            displayCommands();
        } else if (strcmp(command, "touch")==0) {
            printf("if bugs persist consult your programmer :)\n");
        } else if (strcmp(command, "mkdir")==0) {
            printf("Enter folder Name: ");
            fgets(folderName, sizeof(folderName), stdin);
            folderName[strcspn(folderName, "\n")] = '\0';
            createFolderNode(&rootFolNode, folderName);
        } else if (strcmp(command, "ls")==0) {
            displayFolderContents(rootFolNode);
        } else if (strcmp(command, "find")==0) {
            printf("if bugs persist consult your programmer :)\n");
        } else if (strcmp(command, "write")==0) {
            printf("if bugs persist consult your programmer :)\n");
        } else if (strcmp(command, "append")==0) {
            printf("if bugs persist consult your programmer :)\n");
        } else if (strcmp(command, "rm")==0) {
            printf("if bugs persist consult your programmer :)\n");
        } else {
            printf(RED "Invalid Command " RESET);
            printf(", use ");
            printf(GREEN "--help" RESET);
            printf(" to view commands\n");
        }

    } while (1);

    



    return 0;
}