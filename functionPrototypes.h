#ifndef FUNCTIONPROTO_H
#define FUNCTIONPROTO_H

#include "structs.h"

void initFolder(folderNodePtr* folderPtr, char folderName[16], char path[100]); //used to initilize folders

void disPlayContents(folderNode folder);

void createFolder(folderNodePtr folder, char folderName[16]);

void createFile(folderNodePtr folder, char fileName[16], char text[100]);

int searchFolder(folderNode folder, char folderName[16]);

folderNodePtr getFolAdress(folderNodePtr folder, char folderName[16]);

void displayCommands();

void removeFolder(folderNodePtr folder, int index);

#endif