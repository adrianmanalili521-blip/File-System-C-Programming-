#ifndef FUNCTIONDEF_H
#define FUNCTIONDEF_H

#include <stdlib.h>
#include <string.h>

#include "functionPrototypes.h"
#include "structs.h"
#include "myColors.h"

#define MAX 100

void initFolder(folderNodePtr* folderPtr, char folderName[16], char path[MAX]) {
    (*folderPtr) = (folderNodePtr)malloc(sizeof(folderNode));
    if ((*folderPtr) == NULL) {
        printf(RED "memory allocation failed: initFolder()\n" RESET);
    } else {
        strcpy((*folderPtr)->folderName, folderName);
        strcpy((*folderPtr)->path, path);
        (*folderPtr)->prevFolder = NULL;
        (*folderPtr)->fileCount = 0;
        (*folderPtr)->folderCount = 0;
        (*folderPtr)->totalCount = 0;
        (*folderPtr)->nextFreeFileIndex = 0;
        (*folderPtr)->nextFreeFolIndex = 0;
        for (int i = 0; i < MAX; i++) {
            (*folderPtr)->files[i] = NULL;
            (*folderPtr)->folders[i] = NULL;
        }
    }
}

void disPlayContents(folderNode folder) {
    printf("\nfolders:\n");
    for (int i = 0; i < folder.folderCount; i++) {
        if (folder.folders[i] == NULL) {
            continue;
        }
        if (i % 2 == 1) {
            printf(BLUE "%s\n" RESET, folder.folders[i]->folderName);
        } else {
            printf(BLUE "%s " RESET, folder.folders[i]->folderName);
        }
    }
    printf("\n\nfiles:\n");
    for (int j = 0; j < folder.fileCount; j++) {
        if (folder.files[j] == NULL) {
            continue;
        }
        if (j % 2 == 1) {
            printf(YELLOW "%s\n" RESET, folder.files[j]->fileName);
        } else {
            printf(YELLOW "%s " RESET, folder.files[j]->fileName);
        }
    }
    printf("\n");
}

void createFolder(folderNodePtr folder, char folderName[16]) {
    if (folder->folderCount < MAX && folder->totalCount < MAX) {
        folderNodePtr newFolder;
        char path[MAX] = "";
        strcat(path, folder->path);
        strcat(path, folderName);
        strcat(path, "\\");
        initFolder(&newFolder, folderName, path);
        newFolder->prevFolder = folder;
        folder->folders[folder->folderCount] = newFolder;
        folder->folderCount++;
        folder->totalCount++;
    } else {
        printf(RED "maximum capacity reached for folder: %s\n" RESET, folder->folderName);
    }
}

void createFile(folderNodePtr folder, char fileName[16], char text[100]) {
    if (folder->fileCount != MAX && folder->totalCount != MAX) {
        fileNodePtr newFile = (fileNodePtr)malloc(sizeof(fileNode));
            if (newFile == NULL){
                printf("Memory Allocation Failed: createFile()\n");
            } else {
                strcpy(newFile->fileName, fileName);
                strcpy(newFile->text, text);
                folder->files[folder->fileCount] = newFile;

                (folder->fileCount)++;
            (folder->totalCount)++;
        }
    }
}

int searchFolder(folderNode folder, char folderName[16]) {
    int index = -1;
    for (int i = 0; i < folder.folderCount; i++) {
        if (folder.folders[i] != NULL && strcmp(folder.folders[i]->folderName, folderName)==0) {
            index = i;
            break;
        }
    }
    return index; 
}

folderNodePtr getFolAdress(folderNodePtr folder, char folderName[16]) {
    int index = searchFolder(*folder, folderName);
    if (index != -1) {
        return folder->folders[index];
    } else {
        printf(RED "folder not found!\n" RESET);
        return NULL;
    }
}

static void freeFolderRecursive(folderNodePtr folder) {
    if (folder == NULL) return;
    for (int i = 0; i < folder->folderCount; i++) {
        if (folder->folders[i] != NULL) {
            freeFolderRecursive(folder->folders[i]);
            folder->folders[i] = NULL;
        }
    }
    for (int j = 0; j < folder->fileCount; j++) {
        if (folder->files[j] != NULL) {
            free(folder->files[j]);
            folder->files[j] = NULL;
        }
    }
    free(folder);
}

void removeFolder(folderNodePtr folder, int index) {
    if (folder == NULL || index < 0 || index >= folder->folderCount) {
        return;
    }

    folderNodePtr target = folder->folders[index];
    if (target != NULL) {
        freeFolderRecursive(target);
    }

    for (int i = index; i < folder->folderCount - 1; i++) {
        folder->folders[i] = folder->folders[i + 1];
    }
    folder->folders[folder->folderCount - 1] = NULL;

    folder->folderCount--;
    folder->totalCount--;
}

#endif 