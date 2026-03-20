#ifndef FUNCTIONDEF_H
#define FUNCTIONDEF_H

#include <stdlib.h>
#include <string.h>

#include "functionProto.h"
#include "structs.h"

#define MAX 100

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

#define RESET "\033[0m"

void displayCommands(){
    printf(CYAN "\nList of Commands:\n" RESET);
    printf(GREEN "touch" RESET);
    printf(": used to create file\n");
    printf(GREEN "mkdir" RESET);
    printf(": used to create directory\n");
    printf(GREEN "ls" RESET);
    printf(": used to list contents in a directory\n");
    printf(GREEN "find" RESET);
    printf(": used to find path of a file or folder\n");
    printf(GREEN "write" RESET);
    printf(": used to write to a file\n");
    printf(GREEN "append" RESET);
    printf(": used to apend to a file\n");
    printf(RED "rm" RESET);
    printf(": used to remove file or folder\n\n\n");
}

void initRootFolder (folderNodePtr folder){
    strcpy(folder->folderName, "root");
    for (int i = 0; i < MAX; i++){
        folder->folderPtrArr[i] = NULL;
        folder->filePtrArr[i] = NULL;
    }
    folder->folderCount = 0;
    folder->fileCount = 0;
    folder->totalCount = 0;
}

void createFolder (folderNodePtr parentFolder, char folderName[16]){
    folderNodePtr newFolder = (folderNodePtr)malloc(sizeof(folderNode));

    if (newFolder == NULL) {
        printf(RED "Failed to Allocated Memory: createFolder()\n" RESET);
    } else {
        strcpy(newFolder->folderName, folderName);
        insertFolder(parentFolder, newFolder);
    }
}

void insertFolder (folderNodePtr parentFolder, folderNodePtr newFolder){
    parentFolder->folderPtrArr[parentFolder->folderCount] = newFolder;
    (parentFolder->folderCount)++;
    (parentFolder->totalCount)++;
}

void displayContents (folderNode parentFolder){
    printf("%s:\n", parentFolder.folderName);
    printf("folders:\n");
    for (int i = 0; i < parentFolder.folderCount; i++){
        printf("%s\n", parentFolder.folderPtrArr[i]->folderName);
    }
    printf("files:\n");
    for (int j = 0; j < MAX; j++){
        printf("%s\n", parentFolder.filePtrArr[j]->fileName);
    }
    printf("folder count: %d\n", parentFolder.folderCount);
    printf("file count: %d\n", parentFolder.fileCount);
    printf("total count: %d\n", parentFolder.totalCount);
}

void createFile (folderNodePtr parentFolder, char fileName[16], char text[100]){
    fileNodePtr newFile = (fileNodePtr)malloc(sizeof(fileNode));

    if (newFile == NULL) {
        printf(RED "Memory Allocation Failed: createFile()\n" RESET);
    } else {
        strcpy(newFile->fileName, fileName);
        strcpy(newFile->text, text);
        insertFile(parentFolder, newFile);
    }
}

void insertFile (folderNodePtr parentFolder, fileNodePtr newFile){
    if (parentFolder->fileCount != MAX && parentFolder->totalCount != MAX) {
        parentFolder->filePtrArr[parentFolder->fileCount] = newFile;
        (parentFolder->fileCount)++;
        (parentFolder->totalCount)++;
    } else {
        printf(RED "maximun items reached in %s " RESET, parentFolder->folderName);
    }
}

#endif 