#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX 100

typedef struct FileNode {
    //file can contain these members
    char fileName[16];
    char text[100];
} fileNode;

typedef struct FolderNode {
    //a folder can contain current folderName, subfolders and other files;
    char folderName[16];
    struct FolderNode* folderPtr[MAX];
    fileNode* filePtr[MAX];
} folderNode;   

typedef struct RootFolder {
    //there can be only one root folder, can contain subfolders and files and rootfolderName
    char rootFolName[16];
    folderNode* folderPtr[MAX];
    fileNode* filePtr[MAX];
} rootFolNode;

#endif