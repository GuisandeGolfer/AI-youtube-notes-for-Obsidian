#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_FILE_COUNT 100

int isMP3File(const char *filename)
{
  const char *extension = ".mp3";
  size_t len = strlen(filename);
  size_t extLen = strlen(extension);
  return (len > extLen) && (strcmp(filename + len - extLen, extension) == 0);
}


int main(int argc, char *argv[])
{
      // Check for the correct number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Open the specified directory
    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    // Variables to store file information
    struct dirent *entry;
    struct stat fileStat;
    char latestMp3[MAX_FILE_COUNT][256];
    time_t latestTime = 0;
    int mp3Count = 0;

    // Iterate through the directory entries
    while ((entry = readdir(dir))) {
        char filePath[256];
        snprintf(filePath, sizeof(filePath), "%s/%s", argv[1], entry->d_name);

        // Check if it's a regular file and has the .mp3 extension
        if (stat(filePath, &fileStat) == 0 && S_ISREG(fileStat.st_mode) && isMP3File(entry->d_name)) {
            // Check if it's the latest MP3 file based on modification time
            if (fileStat.st_mtime > latestTime) {
                latestTime = fileStat.st_mtime;
                strcpy(latestMp3[0], entry->d_name);
                mp3Count = 1;
            } else if (fileStat.st_mtime == latestTime && mp3Count < MAX_FILE_COUNT) {
                strcpy(latestMp3[mp3Count], entry->d_name);
                mp3Count++;
            }
        }
    }

    // Close the directory
    closedir(dir);

    // Print the latest MP3 file(s)
    if (mp3Count > 0) {
        printf("Latest MP3 file(s):\n");
        for (int i = 0; i < mp3Count; i++) {
            printf("%s\n", latestMp3[i]);
        }
    } else {
        printf("No MP3 files found in the directory.\n");
    }

  return EXIT_SUCCESS;
}
