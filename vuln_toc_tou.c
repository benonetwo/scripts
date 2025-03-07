#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char *filename = "temp.txt";

    // Check if the file is writable
    if (access(filename, W_OK) == 0) {
        printf("[+] File is writable, proceeding to open...\n");
        
        sleep(5);  // Simulating delay (TOC/TOU window)

        // Open the file for writing
        int fd = open(filename, O_WRONLY);
        if (fd != -1) {
            write(fd, "Hacked!\n", 8);
            close(fd);
            printf("[+] File written successfully!\n");
        } else {
            printf("[-] Error opening file!\n");
        }
    } else {
        printf("[-] No write permission!\n");
    }

    return 0;
}
