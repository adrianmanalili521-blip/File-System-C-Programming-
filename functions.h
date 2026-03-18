#ifndef FUNCTION_H
#define FUNCTION_H

#include "structs.h"

fileNode createFile(chat folderName[16], char str[100]);
folderNode createFolder(char folderName[16], char fileName[16]);
rootFolNode createRootFolder();

#endif