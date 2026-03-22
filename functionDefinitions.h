#ifndef FUNCTIONDEF_H
#define FUNCTIONDEF_H

#include <stdlib.h>
#include <string.h>

#include "functionPrototypes.h"
#include "structs.h"
#include "myColors.h"

#define MAX 100

void initFolder(folderNodePtr* folderPtr, char folderName[16]) {
    (*folderPtr) = (folderNodePtr)malloc(sizeof(folderNode));
    if ((*folderPtr) == NULL) {
        printf(RED "memory allocation failed: initFolder()\n" RESET);
    } else {
        strcpy((*folderPtr)->folderName, folderName);
        for (int i = 0; i < MAX; i++){
            (*folderPtr)->prevFolder = NULL;
            (*folderPtr)->files[i] = NULL;
            (*folderPtr)->folders[i] = NULL;
            (*folderPtr)->fileCount = 0;
            (*folderPtr)->folderCount = 0;
            (*folderPtr)->totalCount = 0;
        }
    }
}

void disPlayContents(folderNode folder) {
    printf("\nfolders:\n");
    for (int i = 0; i < folder.folderCount; i++) {
        if (i % 2 == 1) {
            printf(BLUE "%s\n" RESET, folder.folders[i]->folderName);
        } else {
            printf(BLUE "%s " RESET, folder.folders[i]->folderName );
        }
    }
    printf("\n\nfiles:\n");
    for (int j = 0; j < folder.fileCount; j++) {
        if (j % 2 == 1) {
            printf(YELLOW "%s\n" RESET, folder.files[j]->fileName);
        } else {
            printf(YELLOW "%s" RESET, folder.files[j]->fileName);
        }
    }
    printf("\n");
}

void createFolder(folderNodePtr folder, char folderName[16]) {
    if (folder->folderCount != MAX && folder->totalCount != MAX) {
        folderNodePtr newFolder;
        initFolder(&newFolder, folderName);
        newFolder->prevFolder = folder;
        folder->folders[folder->folderCount] = newFolder;
        (folder->folderCount)++;
        (folder->totalCount)++;
    } else {
        printf(RED "maximum capacity reached for folder: %s" RESET, folder->folderName);
    }
}


#endif 