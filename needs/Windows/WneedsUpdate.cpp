#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#ifdef _WIN32
    #include <windows.h>
    #include <direct.h> // Include this for _mkdir
    #define PATH_SEPARATOR '\\'
#else
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #define PATH_SEPARATOR '/'
#endif

#define BUFFER_SIZE 1024

// Function to concatenate file paths
void join_paths(char *result, const char *folder, const char *file) {
    sprintf(result, "%s%c%s", folder, PATH_SEPARATOR, file);
}

// Function to copy a single file
void copy_file(const char *source_file, const char *dest_file) {
    FILE *src = fopen(source_file, "rb");
    if (src == NULL) {
        printf("Error opening source file: %s\n", source_file);
        return;
    }

    FILE *dest = fopen(dest_file, "wb");
    if (dest == NULL) {
        printf("Error opening destination file: %s\n", dest_file);
        fclose(src);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

// Function to copy all files from source directory to destination directory
void copy_directory(const char *source_dir, const char *dest_dir) {
    DIR *dir = opendir(source_dir);
    if (dir == NULL) {
        printf("Error opening directory: %s\n", source_dir);
        return;
    }

    struct dirent *entry;
    struct stat statbuf;

    while ((entry = readdir(dir)) != NULL) {
        // Skip . and .. directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char source_path[512], dest_path[512];
        join_paths(source_path, source_dir, entry->d_name);
        join_paths(dest_path, dest_dir, entry->d_name);

        // Check if entry is a regular file
        if (stat(source_path, &statbuf) == 0 && S_ISREG(statbuf.st_mode)) {
            printf("Copying %s to %s\n", source_path, dest_path);
            copy_file(source_path, dest_path);
        }
    }

    closedir(dir);
}

// Function to create a directory if it doesn't exist
void create_directory(const char *dir) {
    #ifdef _WIN32
        _mkdir(dir);
    #else
        mkdir(dir, 0755);
    #endif
}

int main(int argc, char *argv[]) {
    char source[512] = "C:\\Users\\PC\\AppData\\Roaming\\saps-is-my-project"; // Default source folder
    char destination[512] = "C:\\Users\\PC\\Documents\\1. All My Stuff\\Coding\\Qt\\Qt_projects\\Ordo FInal Iteration\\needs\\Windows"; // Default destination folder

    // If the -t option is provided with paths
    if (argc == 4 && strcmp(argv[1], "-t") == 0) {
        strncpy(source, argv[2], sizeof(source) - 1);
        strncpy(destination, argv[3], sizeof(destination) - 1);
    } else if (argc != 1) {
        printf("Usage: %s [-t source_folder destination_folder]\n", argv[0]);
        return 1;
    }

    // Create destination folder if it doesn't exist
    create_directory(destination);

    // Copy the contents
    copy_directory(source, destination);

    printf("File copying completed.\n");
    return 0;
}
