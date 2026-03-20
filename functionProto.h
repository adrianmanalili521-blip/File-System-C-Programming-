#ifndef FUNCTIONPROTO_H
#define FUNCTIONPROTO_H

#include "structs.h"

void initRootFolder (folderNodePtr folder);

void createFolder (folderNodePtr parentFolder, char folderName[16]);

void insertFolder (folderNodePtr parentFolder, folderNodePtr newFolder);

void displayContents (folderNode parentFolder);

void createFile (folderNodePtr parentFolder, char fileName[16], char text[100]);

void insertFile (folderNodePtr parentFolder, fileNodePtr newFile);


#endif