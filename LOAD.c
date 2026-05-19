#include <stdio.h>
#include <string.h>

char M[100][4];  // External memory

void initMemory() {
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 4; j++) {
            M[i][j] = ' ';
        }
    }
}

int main() {
    FILE *fp;
    char line[40];
    int i = 0, j, k;

    initMemory();

    fp = fopen("input.txt", "r");

    while(fgets(line, sizeof(line), fp)) {

        // Remove newline
        line[strcspn(line, "\n")] = 0;

        if(strncmp(line, "$AMJ", 4) == 0) {
            i = 0;  // Start loading from address 00
        }
        else if(strncmp(line, "$DTA", 4) == 0) {
            continue;  // Ignore
        }
        else if(strncmp(line, "$END", 4) == 0) {
            break;
        }
        else {
            // Load instructions into memory (4 chars each)
            k = 0;
            while(k < strlen(line)) {
    for(j = 0; j < 4; j++) {
        if(k < strlen(line))
            M[i][j] = line[k++];
        else
            M[i][j] = ' ';   // fill remaining with space
    }
    i++;
}
        }
    }

    fclose(fp);

    // Display memory
    printf("\nMemory Content:\n");
    for(i = 0; i < 100; i++) {
        printf("%02d : ", i);
        for(j = 0; j < 4; j++) {
            printf("%c", M[i][j]);
        }
        printf("\n");
    }

    return 0;
}