#include <stdio.h>
#include <windows.h>
#include <string.h>

// Function to count the number of folders in a directory
int getNumberOfFolders(const char path[]) {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind;
    int folderCount = 0;

    char searchPath[MAX_PATH];
    snprintf(searchPath, MAX_PATH, "%s\\*", path);

    hFind = FindFirstFile(searchPath, &findFileData);
    if (hFind == INVALID_HANDLE_VALUE) {
        return 0;
    }

    do {
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0) {
                folderCount++;
            }
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
    return folderCount;
}

// Function to count the number of files in a directory
int getNumberOfFiles(const char path[]) {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind;
    int fileCount = 0;

    char searchPath[MAX_PATH];
    snprintf(searchPath, MAX_PATH, "%s\\*", path);

    hFind = FindFirstFile(searchPath, &findFileData);
    if (hFind == INVALID_HANDLE_VALUE) {
        return 0;
    }

    do {
        if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            fileCount++;
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
    return fileCount;
}

// Function to get the names of files and folders in a directory
void getFolderAndFiles(const char path[], char files[][256], char folders[][256]) {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind;

    char searchPath[MAX_PATH];
    snprintf(searchPath, MAX_PATH, "%s\\*", path);

    hFind = FindFirstFile(searchPath, &findFileData);
    if (hFind == INVALID_HANDLE_VALUE) {
        return;
    }

    int fileIndex = 0;
    int folderIndex = 0;

    do {
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0) {
                strncpy(folders[folderIndex], findFileData.cFileName, 256);
                folderIndex++;
            }
        } else {
            strncpy(files[fileIndex], findFileData.cFileName, 256);
            fileIndex++;
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}

int main() {
    char path[512];
    printf("Enter the directory path: ");
    gets(path);

    int numFolders = getNumberOfFolders(path);
    int numFiles = getNumberOfFiles(path);

    char folders[numFolders][256];
    char files[numFiles][256];

    getFolderAndFiles(path, files, folders);

    printf("Folders:\n");
    for (int i = 0; i < numFolders; i++) {
        printf("%s\n", folders[i]);
    }

    printf("\nFiles:\n");
    for (int i = 0; i < numFiles; i++) {
        printf("%s\n", files[i]);
    }

    return 0;
}
