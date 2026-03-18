#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct File {
    char fileName[16];
    char str[100];
} fileNode;

typedef struct Folder {
    char folderName[16];
    struct Folder* folderPtr[100];
    struct File* filePtr[100]
    int count;
} folderNode;

typedef struct RootFolder {
    char folderName[16];
    struct File* filePtr[100];
    struct Folder* folderPtr[100];
    int count;
} rootFolNode;


#endif