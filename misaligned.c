#include <stdio.h>
#include <assert.h>
#include <string.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[j]);
        }
    }
    return i * j;
}

void testPrintColorMap() {
    // Redirect stdout to a pipe
    FILE* pipe = popen("./tshirts.out", "r"); // Execute the compiled program and read its output
    if (!pipe) {
        perror("popen failed");
        return;
    }

    // Read the output into a buffer
    char buffer[1024];
    size_t index = 0;
    while (fgets(buffer + index, sizeof(buffer) - index, pipe) != NULL) {
        index = strlen(buffer);
        if (index >= sizeof(buffer) - 1) {
            break; // Prevent buffer overflow
        }
    }
    pclose(pipe);


    assert(strstr(buffer, "0 | White | Blue") != NULL);
    assert(strstr(buffer, "24 | Violet | Slate") != NULL);

   
    assert(strstr(buffer, "1 | White | Orange") != NULL);
    assert(strstr(buffer, "5 | Red | Blue") != NULL);


    int lineCount = 0;
    for(char* p = buffer; *p != '\0'; p++) {
        if(*p == '\n') lineCount++;
    }
    assert(lineCount == 25);
    printf("All test cases passed!\n");
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    testPrintColorMap();
    printf("All is well (maybe!)\n");
    return 0;
}
