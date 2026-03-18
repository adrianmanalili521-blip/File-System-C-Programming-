#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX 100

typedef struct FileNode {
    //file can contain these members
    char fileName[16];
    char text[100];
} fileNode, *fileNodePtr;

typedef struct FolderNode {
    //a folder can contain current folderName, subfolders and other files;
    char folderName[16];
    struct FolderNode* folderPtr[MAX];
    fileNode* filePtr[MAX];
    int fileCount;
    int folderCount;
    int totalCount;
} folderNode, *folderNodePtr;   

typedef struct RootFolder {
    //there can be only one root folder, can contain subfolders and files and rootfolderName
    char rootFolName[16];
    folderNodePtr folderPtr[MAX];
    fileNodePtr filePtr[MAX];
    int fileCount;
    int folderCount;
    int totalCount;
} rootFolNode, *rootFolNodePtr;

#endif