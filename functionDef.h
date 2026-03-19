#ifndef FUNCTIONDEF_H
#define FUNCTIONDEF_H

#include <stdlib.h>
#include <string.h>

#include "functionProto.h"
#include "structs.h"

#define MAX 100

#define RED   "\033[31m"
#define GREEN "\033[32m"
#define BLUE  "\033[34m"
#define RESET "\033[0m"

void displayCommands(){
    printf(GREEN "List of Commands:\n" RESET);
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
    printf(": used to remove file or folder\n");
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


#endif 