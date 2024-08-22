#include <stdio.h>
#include <assert.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            // Print the index, major color, and minor color
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[j]);
        }
    }
    
    // Return the total number of color combinations
    return i * j;
}

int main() {
    int result = printColorMap();
    
    // Assert that the number of color combinations is 25
    assert(result == 25);
    
    printf("All is well (maybe!)\n");
    return 0;
}
