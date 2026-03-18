#ifndef MYHEADER_H
#define MYHEADER_H

typedef struct File {
    char str[100];
} fileNode;

typedef struct Folder {
    struct Folder* folderPtr[100];
    struct File* filePtr[100]
    int count;
} folderNode;

typedef struct RootFolder {
    struct File* filePtr[100];
    struct Folder* folderPtr[100];
    int count;
}


#endif