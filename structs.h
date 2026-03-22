#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX 100

typedef struct Files {
    char fileName[16];
    char text[MAX];
} fileNode, *fileNodePtr;

typedef struct Folders {
    struct Folders* prevFolder;
    char folderName[16];
    fileNodePtr files[MAX];
    struct Folders* folders[MAX];
    int fileCount;
    int folderCount;
    int totalCount;
} folderNode, *folderNodePtr;

#endif