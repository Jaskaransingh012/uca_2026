#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    struct stat fileStat;

    if (stat(argv[1], &fileStat) == -1) {
        perror("stat");
        return 1;
    }

    printf("========== File Atrributes for : %s ==========\n", argv[1]);

    printf("File: %s\n", argv[1]);

    // size of the file
    printf("File Size            : %ld bytes\n", fileStat.st_size);

    // no of hardlinks
    printf("Hard Links           : %ld\n", fileStat.st_nlink);

    // permission ----
    printf("Permissions (Octal)  : %o\n", fileStat.st_mode & 0777);

    // file type ----
    printf("File Type            : ");

    if (S_ISREG(fileStat.st_mode))
        printf("Regular File\n");
    else if (S_ISDIR(fileStat.st_mode))
        printf("Directory\n");
    else if (S_ISCHR(fileStat.st_mode))
        printf("Character Device\n");
    else if (S_ISBLK(fileStat.st_mode))
        printf("Block Device\n");
    else if (S_ISFIFO(fileStat.st_mode))
        printf("FIFO (Named Pipe)\n");
    else if (S_ISLNK(fileStat.st_mode))
        printf("Symbolic Link\n");
    else if (S_ISSOCK(fileStat.st_mode))
        printf("Socket\n");
    else
        printf("Unknown\n");

    // owner of the file
    printf("User ID (UID)        : %d\n", fileStat.st_uid);
    printf("Group ID (GID)       : %d\n", fileStat.st_gid);


   //  without using the ctime we get long integer
    printf("Last Access Time     : %ld\n", (long)fileStat.st_atime);

   //  using the ctime get the proper time string
    printf("Last Modification    : %s", ctime(&fileStat.st_mtime));

    return 0;
}
