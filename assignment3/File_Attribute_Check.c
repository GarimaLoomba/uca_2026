#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

void printFileType(mode_t mode) {
    if (S_ISREG(mode))
        printf("Regular File\n");
    else if (S_ISDIR(mode))
        printf("Directory\n");
    else if (S_ISCHR(mode))
        printf("Character Device\n");
    else if (S_ISBLK(mode))
        printf("Block Device\n");
    else if (S_ISFIFO(mode))
        printf("FIFO (Named Pipe)\n");
    else if (S_ISLNK(mode))
        printf("Symbolic Link\n");
    else if (S_ISSOCK(mode))
        printf("Socket\n");
    else
        printf("Unknown\n");
}

int main(int argc, char *argv[]) {
    struct stat fileStat;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (stat(argv[1], &fileStat) == -1) {
        perror("stat");
        return EXIT_FAILURE;
    }

    printf("=== File Attributes for: %s ===\n", argv[1]);

    printf("File Type:            ");
    printFileType(fileStat.st_mode);

    printf("Permissions:          %04o\n", fileStat.st_mode & 0777);
    printf("File Size:            %lld bytes\n", (long long)fileStat.st_size);
    printf("Hard Links Count:     %lu\n", (unsigned long)fileStat.st_nlink);
    printf("Owner (UID):          %u\n", fileStat.st_uid);
    printf("Group (GID):          %u\n", fileStat.st_gid);

    printf("Last Access Time:     %s", ctime(&fileStat.st_atime));
    printf("Last Modification:    %s", ctime(&fileStat.st_mtime));
    printf("Status Change Time:   %s", ctime(&fileStat.st_ctime));

    return EXIT_SUCCESS;
}