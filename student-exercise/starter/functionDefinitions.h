#ifndef FUNCTIONDEF_H
#define FUNCTIONDEF_H

#include <stdlib.h>
#include <string.h>

#include "functionPrototypes.h"
#include "structs.h"
#include "myColors.h"

#define MAX 100

// TODO: implement these functions.
// You may use the production version in the solution folder for reference.

void initFolder(folderNodePtr* folderPtr, char folderName[16], char path[MAX]) {
    // allocate and initialize the folder node
    // *folderPtr = ...
}

void disPlayContents(folderNode folder) {
    // print folder and file lists for the current folder
}

void createFolder(folderNodePtr folder, char folderName[16]) {
    // add new folder child, set path, parent, and counts
}

void createFile(folderNodePtr folder, char fileName[16], char text[100]) {
    // add new file child, set filename, text, and counts
}

int searchFolder(folderNode folder, char folderName[16]) {
    // locate folder index by name, return -1 if not found
    return -1;
}

folderNodePtr getFolAdress(folderNodePtr folder, char folderName[16]) {
    // return pointer to folder child or NULL
    return NULL;
}

void removeFolder(folderNodePtr folder, int index) {
    // remove folder child and clean memory for subtree.
}

#endif 