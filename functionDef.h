#ifndef FUNCTIONDEF_H
#define FUNCTIONDEF_H

#include <stdlib.h>
#include <string.h>

#include "functionProto.h"
#include "structs.h"

#define MAX 100

void initRootFolder(rootFolNode *rootFol){
    strcpy(rootFol->rootFolName, "root");

    for (int i = 0; i < MAX; i++){
        rootFol->folderPtr[i] = NULL;
        rootFol->filePtr[i] = NULL;
    }
}

void initSubFolders(folderNode *folNode, char folderName[16]){
    strcpy(folNode->folderName, folderName);
    
    for (int i = 0; i < MAX; i++){
        folNode->folderPtr[i] = NULL;
        folNode->filePtr[i] = NULL;
    }
}

#endif 