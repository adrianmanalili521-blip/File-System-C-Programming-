#ifndef FUNCTIONPROTO_H
#define FUNCTIONPROTO_H

#include "structs.h"

void initFolder(folderNodePtr* folderPtr, char folderName[16]); //used to initilize folders

void disPlayContents(folderNode folder);

void createFolder(folderNodePtr folder, char folderName[16]);

#endif