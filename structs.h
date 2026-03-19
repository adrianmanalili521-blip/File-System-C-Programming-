#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX 100

typedef struct File {
    char fileName[16];
    char text[100];
} fileNode, *fileNodePtr;

typedef struct Folder {
    char folderName[16];
    struct Folder* folderPtrArr[MAX];
    fileNodePtr filePtrArr[MAX];
    int folderCount;
    int fileCount;
    int totalCount;     // per directory maximum capacity is 100
} folderNode, *folderNodePtr;


#endif