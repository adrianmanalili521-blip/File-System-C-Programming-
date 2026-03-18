#ifndef FUNCTIONDEF_H
#define FUNCTIONDEF_H

#include <stdlib.h>
#include <string.h>

#include "functionProto.h"
#include "structs.h"

#define MAX 100

void initRootFolder(rootFolNodePtr rootFol){
    strcpy(rootFol->rootFolName, "root");

    for (int i = 0; i < MAX; i++){
        rootFol->folderPtr[i] = NULL;
        rootFol->filePtr[i] = NULL;
    }

    rootFol->folderCount = 0;
    rootFol->fileCount = 0; 
    rootFol->totalCount = 0;
}

void initSubFolders(folderNodePtr folNode, char folderName[16]){
    strcpy(folNode->folderName, folderName);
    
    for (int i = 0; i < MAX; i++){
        folNode->folderPtr[i] = NULL;
        folNode->filePtr[i] = NULL;
    }
    folNode->folderCount = 0;
    folNode->fileCount = 0;
    folNode->totalCount = 0;
}

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

void createFolderNode(rootFolNodePtr rootFol, char folderName[16]){
    folderNodePtr folNode = (folderNodePtr)malloc(sizeof(folderNode));

    if (folNode == NULL){
        printf("Memory Allocation failed for createFolderNode()");
    } else {
        initSubFolders(folNode, folderName);
        insertToParentFolder(rootFol, folNode);
    }

}

void insertToParentFolder(rootFolNodePtr rootFol, folderNodePtr folNode){
    if (rootFol->totalCount != MAX-1){
        rootFol->folderPtr[rootFol->folderCount] = folNode;
        (rootFol->folderCount)++;
        (rootFol->totalCount)++;
    } else {
        printf(RED "Parent Folder is full!\n\n" RESET);
    }
}

void displayFolderContents(rootFolNode rootFol){
    printf("folder name: %s\n", rootFol.rootFolName);
    printf("folders:\n");
    for (int i = 0; i < rootFol.folderCount; i++){
        printf("%s\n", (rootFol.folderPtr[i])->folderName);
    }
    printf("files:\n");
    for (int j = 0; j < rootFol.fileCount; j++){
        printf("%s\n", (rootFol.filePtr[j])->fileName);
    }
    printf("total count: %d\n", rootFol.totalCount);
}
#endif 